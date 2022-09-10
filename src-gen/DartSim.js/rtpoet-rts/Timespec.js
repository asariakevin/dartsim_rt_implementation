module.exports =  class Timespec {
	constructor(sec, nsec = 0) {
		this._nsec_per_sec = 1000000000;
		this.sec = sec;
		this.nsec = nsec;
	}
	static get(sec = 0, nsec = 0) {
		return new Timespec(sec, nsec);
	}
	static now() {
		let hrTime = process.hrtime();
		return Timespec.get(hrTime[0], hrTime[1]);
	}
	add(operand) {
		return Timespec.get(this.sec + operand.sec, this.nsec + operand.nsec)._normalize();
	}
	subtract(operand) {
		return Timespec.get(this.sec - operand.sec, this.nsec - operand.nsec)._normalize();
	}
	greater(operand) {
		return this.toNano() > operand.toNano();
	}
	less(operand) {
		return this.toNano() < operand.toNano();
	}
	equals(operand) {
		return this.toNano() == operand.toNano();
	}
	toString() {
		return '(' + this.sec + ',' + this.nsec + ')';
	}
	toNano() {
		return this.sec * this._nsec_per_sec + this.nsec;
	}
	_normalize() {
		for(;;) {
			if( this.sec < 0 ) {
				if(-this._nsec_per_sec < this.nsec && this.nsec <= 0)
				break;
				this.sec  += this.nsec / this._nsec_per_sec;
				this.nsec %= this._nsec_per_sec;
				if(this.nsec > 0) {
					this.sec  += 1;
					this.nsec -= this._nsec_per_sec;
				}
			}
			else if(this.sec > 0) {
				if(0 <= this.nsec && this.nsec < this._nsec_per_sec)
				break;
				this.sec  += this.nsec / this._nsec_per_sec;
				this.nsec %= this._nsec_per_sec;
				if(this.nsec < 0) {
					this.sec  -= 1;
					this.nsec += this._nsec_per_sec;
				}
			}
			else {
				if(-this._nsec_per_sec < this.nsec && this.nsec < this._nsec_per_sec)
				break;
				this.sec  += this.nsec / this._nsec_per_sec;
				this.nsec %= this._nsec_per_sec;
			}
		}
		return this;
	}
}