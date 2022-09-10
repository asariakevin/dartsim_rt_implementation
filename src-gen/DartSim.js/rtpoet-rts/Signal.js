module.exports = class Signal {
	static rtBound(port) {
		return new Signal(port, 'rtBound');
	}
	static rtUnbound(port) {
		return new Signal(port, 'rtUnbound');
	}
	static fromMessage(msg, port) {
		return new Signal(port, msg.signal, msg.data);
	}
	constructor(port, type, data) {
		this.port = port;
		this.type = type;
		this.data = data;
	}
	send() {
		return this.port.send(this);
	}
	sendAt(index) {
		return this.port.sendAt(this, index);
	}
	toMessage(farend, srcPortIdx) {
		let self = this;
		return {
			srcPortIdx: srcPortIdx,
			destSlot: farend.slot,
			destPart: farend.part,
			destPartIdx: farend.index,
			destPort: farend.port,
			signal: this.type,
			data: this.data
		}
	}
}