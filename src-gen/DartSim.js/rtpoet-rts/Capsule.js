const Signal = require('./Signal');
const { Machine, State, interpret } = require('xstate');
module.exports = class Capsule {
	constructor() {
		this.name = '';
		this.index = -1;
		this.fqn = '';
		this.parts = {};
		this.borderPorts = [];
		this.internalPorts = [];
		this.routingTable = [];
		this.stateMachine = null;
	}
	wireParts() {
		for(let partName in this.parts)
		for(let slotIdx = 0; slotIdx<this.parts[partName].replication; slotIdx++)
		if(this.parts[partName].slots[slotIdx])
		this.wireSlot(partName, slotIdx);
	}
	wireSlot(partName, slotIdx) {
		for(let portName in this.routingTable[partName][slotIdx]) {
			for(let farEndIdx = 0; farEndIdx<this.routingTable[partName][slotIdx][portName].length; farEndIdx++) {
				this.parts[partName].slots[slotIdx].send('wirePort', portName, this.routingTable[partName][slotIdx][portName][farEndIdx]);
			}
		}
		for(let portName in this.routingTable[this.name]) {
			for(let farEndIdx = 0; farEndIdx<this.routingTable[this.name][portName].length; farEndIdx++) {
				let destPart = this.routingTable[this.name][portName][farEndIdx].part;
				let destIndex = this.routingTable[this.name][portName][farEndIdx].index;
				if(destPart == partName && destIndex == slotIdx)
				this.wirePort(portName, this.routingTable[this.name][portName][farEndIdx])
			}
		}
	}
	unwireSlot(partName, slotIdx) {
		for(let portName in this.routingTable[partName][slotIdx]) {
			for(let farEndIdx = 0; farEndIdx<this.routingTable[partName][slotIdx][portName].length; farEndIdx++) {
				this.parts[partName].slots[slotIdx].send('unwirePort', portName, this.routingTable[partName][slotIdx][portName][farEndIdx]);
			}
		}
		for(let portName in this.routingTable[this.name][0]) {
			for(let farEndIdx = 0; farEndIdx<this.routingTable[this.name][0][portName].length; farEndIdx++) {
				let destPart = this.routingTable[this.name][0][portName][farEndIdx].part;
				let destIndex = this.routingTable[this.name][0][portName][farEndIdx].index;
				if(destPart == partName && destIndex == slotIdx)
				this.unwirePort(portName, this.routingTable[this.name][0][portName][farEndIdx])
			}
		}
	}
	wireSap(part, port, candidates) {
		let slotIndex = 0;
		let portIndex = 0;
		for(let i=0; i<candidates.length; i++) {
			let candidatePart = this.parts[candidates[i].part];
			let candidatePort = candidatePart.borderPorts[candidates[i].port];
			for(let j=0; j<candidatePart.replication; j++) {
				if(!candidatePart.slots[j])
				continue;
				let availableFarEnds = candidatePort.replication -
				this.routingTable[candidatePart.name][j][candidatePort.name].length;
				while(availableFarEnds > 0) {
					if(slotIndex >= part.replication)
					return;
					if(!part.slots[slotIndex]) {
						slotIndex++;
						continue;
					}
					if(portIndex >= port.replication) {
						slotIndex++;
						portIndex = 0;
						continue;
					}
					this.routingTable[candidatePart.name][j][candidatePort.name].push({
							part: part.name,
							index: slotIndex,
							port: port.name
					});
					this.routingTable[part.name][slotIndex][port.name].push({
							part: candidatePart.name,
							index: j,
							port: candidatePort.name
					});
					part.slots[slotIndex].send('wirePort', port.name, {
							part: candidatePart.name,
							index: j,
							port: candidatePort.name
					});
					candidatePart.slots[j].send('wirePort', candidatePort.name, {
							part: part.name,
							index: slotIndex,
							port: port.name
					});
					portIndex++;
					availableFarEnds--;
				}
			}
		}
	}
	getCandidateSppPorts(sap) {
		let primeCandidates = [];	// matching registration override
		let otherCandidates = [];
		for(let partName in this.parts) {
			let part = this.parts[partName];
			for(let portName in part.borderPorts) {
				let port = part.borderPorts[portName];
				if(!port.isWired
					&& port.isPublish
					&& port.isAutomaticRegistration
					&& port.isConjugated == !sap.isConjugated
					&& port.protocol == sap.protocol) {
					if(port.registrationOverride == sap.registrationOverride)
					primeCandidates.push({
							part: partName,
							port: portName
					});
					else
					otherCandidates.push({
							part: partName,
							port: portName
					});
				}
			}
		}
		return primeCandidates.concat(otherCandidates);	//prime candidates first
	}
	unwirePort(port, farEnd) {
		if(this.borderPorts[port])
		return this.borderPorts[port].disconnect(farEnd);
		else if(this.internalPorts[port])
		return this.internalPorts[port].disconnect(farEnd);
		return false;
	}
	wirePort(port, farEnd) {
		if(this.borderPorts[port])
		return this.borderPorts[port].connect(farEnd);
		else if(this.internalPorts[port])
		return this.internalPorts[port].connect(farEnd);
		return false;
	}
	onImport(partName, partIndex) {
		this.name = partName;
		this.index = partIndex;
	}
	onDeport(partName, partIndex) {
		delete this.name;
		delete this.index;
	}
	inject(message) {
		if(this.interpreter) this.interpreter.send(message.destPort+"::"+message.signal, message);
		else message.defer();
	}
	defer(message) {
		if(this.borderPorts[message.destPort])
		this.borderPorts[message.destPort].defer(message);
		else if(this.internalPorts[message.destPort])
		this.internalPorts[message.destPort].defer(message);
	}
	deliver(message) {
		if(message.destSlot === this.fqn) {
			let self = this;
			message.defer = function() { self.defer(message); }
			this.inject(message);
		}
		else {
			let destSlot = null;
			let longestPrefix = -1;
			for(let part in this.parts) {
				for(let slotIdx=0; slotIdx < this.parts[part].slots.length; slotIdx++) {
					let slot = this.parts[part].slots[slotIdx]
					let fqn = slot.getCustomParameters().fqn;
					if(message.destSlot.startsWith(fqn)) {
						if (fqn.length > longestPrefix) {
							longestPrefix = fqn.length;
							destSlot = slot;
						}
					}
				}
			}
			if(destSlot != null)
			destSlot.send('deliver', message);
			else if(this.actor.getParent() != null)
			this.actor.getParent().send('deliver', message);
			else
			console.log(this.getFQN()+"\t\t\tunexpected message: "+JSON.stringify(message))
		}
	}
	getName() {
		return this.name+'['+this.index+']';
	}
	getFQN() {
		return this.fqn;
	}
	getIndex() {
		return this.index;
	}
	save() {
		if(this.currentState)
		return JSON.stringify(this.currentState);
		return null;
	}
	run(initialState) {
		if(this.stateMachine) {
			this.stateMachine['id'] = this.getFQN();
			let machine = Machine(this.stateMachine);
			this.currentState = initialState ?
			machine.resolveState(State.create(JSON.parse(initialState))) : null;
			this.interpreter = interpret(machine ).onTransition(state => {
					this.currentState  = state;
			});
			if(this.currentState)
			this.interpreter.start(this.currentState);
			else
			this.interpreter.start();
			for (let port in this.internalPorts)
			this.internalPorts[port].recallAll();
			for (let port in this.borderPorts)
			this.borderPorts[port].recallAll();
		}
		for (let name in this.parts)
		for(let i=0; i<this.parts[name].slots.length; i++)
		if(!this.parts[name].optional && !this.parts[name].plugin)
		this.parts[name].slots[i].send('run');
	}
}