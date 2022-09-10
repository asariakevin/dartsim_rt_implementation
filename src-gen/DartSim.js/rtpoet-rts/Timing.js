const NanoTimer = require('nanotimer');
const Timespec = require('./Timespec');
const Signal = require('./Signal');
module.exports = {
	base: function(port) {
		this.port = port;
		this.timers = {};
		this.informIn = function(tspec, customParam) {
			let id = this._genID();
			this.timers[id] = new NanoTimer();
			this.timers[id].setTimeout(this._callback, [this.port, customParam], tspec.toNano()+'n');
			return id;
		};
		this.informAt = function(tspec, customParam) {
			let id = this._genID();
			this.timers[id] = new NanoTimer();
			this.timers[id].setTimeout(this._callback, [this.port, customParam], tspec.subtract(Timespec.now()).toNano()+'n');
			return id;
		};
		this.informEvery = function(tspec, customParam) {
			let id = this._genID();
			this.timers[id] = new NanoTimer();
			this.timers[id].setInterval(this._callback, [this.port, customParam], tspec.toNano()+'n');
			return id;
		};
		this.cancelTimer = function(tid) {
			if(tid in this.timers) {
				this.timers[tid].clearTimeout();
				this.timers[tid].clearInterval();
			}
			delete this.timers[tid];
		};
		this._genID = function () {
			return Math.random().toString(36).substr(2, 9);
		};
		this._callback = function(port, customParam) {
			port.sendToSelf(new Signal(port, 'timeout', customParam));
		};
	}
}