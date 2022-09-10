let format = require('util').format
module.exports = {
	base: function(port, stream = process.stdout) {
		this.port = port;
		this.stream = stream;
		this.space = function() {
			return ' ';
		};
		this.tab = function() {
			return '\t';
		};
		this.cr = function() {
			return '\r';
		};
		this.crtab = function(i) {
			this.show('\n');
			while(--i >= 0)
			this.tab();
		};
		this.log = function() {
			stream.write(format.apply(null, arguments)+'\n');
		};
		this.show = function() {
			stream.write(format.apply(null, arguments));
		};
		this.clear = function() {};
		this.commit = function() {};
	}
}