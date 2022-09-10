const Signal = require('rtpoet-rts/Signal');
module.exports = {
	base: function(port) {
		this.port = port;
		this.recall = function() {
			port.recall();
		}
		this.recallAll = function() {
			port.recallAll();
		}
		this.in = function() {
			this.sendReadForwardTargetSensor = function(sensedForwardTargetSensor) {
				this.sensedForwardTargetSensor = sensedForwardTargetSensor
			}
		};
		this.createForwardTargetSensor = function(simulatorParams) {
			return new Signal(port, 'createForwardTargetSensor', {
					'simulatorParams': simulatorParams
			})
		}
		this.readForwardTargetSensor = function() {
			return new Signal(port, 'readForwardTargetSensor', {
			})
		}
	},
	conjugated: function(port) {
		this.port=port;
		this.recall = function() {
			port.recall();
		}
		this.recallAll = function() {
			port.recallAll();
		}
		this.in = function() {
			this.createForwardTargetSensor = function(simulatorParams) {
				this.simulatorParams = simulatorParams
			}
			this.readForwardTargetSensor = function() {
			}
		};
		this.sendReadForwardTargetSensor = function(sensedForwardTargetSensor) {
			return new Signal(port, 'sendReadForwardTargetSensor', {
					'sensedForwardTargetSensor': sensedForwardTargetSensor
			})
		}
	}
}