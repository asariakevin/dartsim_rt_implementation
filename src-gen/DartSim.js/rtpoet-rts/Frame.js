const FrameService = require('./FrameService');
module.exports = {
	base: function(port) {
		this.port = port;
		this.migrate = function(part, location, index) {
			return FrameService.migrate(port.capsule.actor, part, location, index);
		};
		this.incarnate = function(type, data = {}) {
			return FrameService.incarnate(port.capsule.actor, type, data);
		};
		this.incarnateAt = function(part, type, data = {}, index = -1) {
			return FrameService.incarnateAt(port.capsule.actor, part, type, data, index);
		};
		this.import = function(instance, part, index = -1) {
			FrameService.import(port.capsule.actor, instance, part, index);
		};
		this.deport = function(part, index = -1) {
			FrameService.deport(port.capsule.actor, part, index);
		};
	}
}