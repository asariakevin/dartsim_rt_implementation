const Signal = require('./Signal');
module.exports = class Port {
	constructor(name, protocol, isConjugated = false, isService = true, isWired = true, isPublish = false,
		isRelay = false, isNotification = false, isAutomaticRegistration = true, registrationOverride = '', replication = 1, capsule = null) {
		this.name = name;
		this.protocol = protocol;
		this.isConjugated = isConjugated;
		this.isWired = isWired;
		this.isService = isService;
		this.isPublish = isPublish;
		this.isRelay = isRelay;
		this.isNotification = isNotification;
		this.isAutomaticRegistration = isAutomaticRegistration;
		this.registrationOverride = registrationOverride;
		this.replication = replication;
		this.capsule = capsule;
		this.deferredQueue = [];
		this.farEnds = Array(this.replication).fill(0);
	}
	connect(...farends) {
		for(let i=0; i<farends.length; i++) {
			if(this.getIndex(farends[i]) != -1)
			return false;
			let index = this.getNextAvailableIndex();
			if(index == -1)
			return false;
			this.farEnds[index] = farends[i];
			if(this.isNotification) {
				this.sendToSelf(Signal.rtBound());
			}
		}
		return true;
	}
	getIndex(farend) {
		for (let i = 0; i < this.replication; i++)
		if(this.farEnds[i]
			&& this.farEnds[i].part == farend.part
			&& this.farEnds[i].index == farend.index
		&& this.farEnds[i].port == farend.port)
		return i;
		return -1;
	}
	disconnect(farend) {
		let index = this.getIndex(farend);
		if(index != -1) {
			this.farEnds[index] = 0;
			if(this.isNotification) {
				this.sendToSelf(Signal.rtUnbound());
			}
		}
	}
	getNextAvailableIndex() {
		for(let i=0; i<this.replication; i++)
		if(!this.farEnds[i])
		return i;
		return -1;
	}
	send(signal) {
		let result = true;
		for (let i = 0; i < this.replication; i++) {
			if(this.farEnds[i])
			result &= this.sendAt(signal, i);
		}
		return result;
	}
	sendAt(signal, index) {
		if(index >= this.replication
			|| !this.farEnds[index]) {
			return false;
		}
		this.capsule.deliver(signal.toMessage(this.farEnds[index], this.capsule.index));
		return true;
	}
	sendToSelf(signal) {
		this.capsule.deliver(signal.toMessage({
					slot: this.capsule.fqn,
					part: this.capsule.name,
					index: this.capsule.index,
					port: this.name
		}, this.capsule.index));
		return true;
	}
	defer(message) {
		this.deferredQueue.push(message);
	}
	recall() {
		if(this.deferredQueue.length > 0)
		this.capsule.deliver(this.deferredQueue.pop());
	}
	recallAll() {
		while(this.deferredQueue.length > 0)
		this.capsule.deliver(this.deferredQueue.pop());
	}
}