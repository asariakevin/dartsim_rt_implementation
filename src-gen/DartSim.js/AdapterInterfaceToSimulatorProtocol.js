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
			this.sendIsFinished = function(finished) {
				this.finished = finished
			}
			this.sendReadForwardThreatSensor = function(readings) {
				this.readings = readings
			}
			this.sendReadForwardTargetSensor = function(readings) {
				this.readings = readings
			}
			this.sendReadForwardThreatSensorForObservation = function(readings) {
				this.readings = readings
			}
			this.sendReadForwardTargetSensorForObservation = function(readings) {
				this.readings = readings
			}
			this.sendStep = function(detection) {
				this.detection = detection
			}
			this.sendResults = function(simulationResults) {
				this.simulationResults = simulationResults
			}
			this.sendScreenOutput = function(screenOutput) {
				this.screenOutput = screenOutput
			}
			this.sendParameters = function(simulationParams) {
				this.simulationParams = simulationParams
			}
			this.sendState = function(teamState) {
				this.teamState = teamState
			}
		};
		this.isFinished = function() {
			return new Signal(port, 'isFinished', {
			})
		}
		this.readForwardThreatSensor = function(cells) {
			return new Signal(port, 'readForwardThreatSensor', {
					'cells': cells
			})
		}
		this.readForwardTargetSensor = function(cells) {
			return new Signal(port, 'readForwardTargetSensor', {
					'cells': cells
			})
		}
		this.readForwardThreatSensorForObservation = function(cells, numOfObservations) {
			return new Signal(port, 'readForwardThreatSensorForObservation', {
					'cells': cells,
					'numOfObservations': numOfObservations
			})
		}
		this.readForwardTargetSensorForObservation = function(cells, numOfObservations) {
			return new Signal(port, 'readForwardTargetSensorForObservation', {
					'cells': cells,
					'numOfObservations': numOfObservations
			})
		}
		this.step = function(tactics, decisionTimeMsec) {
			return new Signal(port, 'step', {
					'tactics': tactics,
					'decisionTimeMsec': decisionTimeMsec
			})
		}
		this.getResults = function() {
			return new Signal(port, 'getResults', {
			})
		}
		this.getScreenOutput = function() {
			return new Signal(port, 'getScreenOutput', {
			})
		}
		this.getParameters = function() {
			return new Signal(port, 'getParameters', {
			})
		}
		this.getState = function() {
			return new Signal(port, 'getState', {
			})
		}
		this.createSimulator = function() {
			return new Signal(port, 'createSimulator', {
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
			this.isFinished = function() {
			}
			this.readForwardThreatSensor = function(cells) {
				this.cells = cells
			}
			this.readForwardTargetSensor = function(cells) {
				this.cells = cells
			}
			this.readForwardThreatSensorForObservation = function(cells, numOfObservations) {
				this.cells = cells
				this.numOfObservations = numOfObservations
			}
			this.readForwardTargetSensorForObservation = function(cells, numOfObservations) {
				this.cells = cells
				this.numOfObservations = numOfObservations
			}
			this.step = function(tactics, decisionTimeMsec) {
				this.tactics = tactics
				this.decisionTimeMsec = decisionTimeMsec
			}
			this.getResults = function() {
			}
			this.getScreenOutput = function() {
			}
			this.getParameters = function() {
			}
			this.getState = function() {
			}
			this.createSimulator = function() {
			}
		};
		this.sendIsFinished = function(finished) {
			return new Signal(port, 'sendIsFinished', {
					'finished': finished
			})
		}
		this.sendReadForwardThreatSensor = function(readings) {
			return new Signal(port, 'sendReadForwardThreatSensor', {
					'readings': readings
			})
		}
		this.sendReadForwardTargetSensor = function(readings) {
			return new Signal(port, 'sendReadForwardTargetSensor', {
					'readings': readings
			})
		}
		this.sendReadForwardThreatSensorForObservation = function(readings) {
			return new Signal(port, 'sendReadForwardThreatSensorForObservation', {
					'readings': readings
			})
		}
		this.sendReadForwardTargetSensorForObservation = function(readings) {
			return new Signal(port, 'sendReadForwardTargetSensorForObservation', {
					'readings': readings
			})
		}
		this.sendStep = function(detection) {
			return new Signal(port, 'sendStep', {
					'detection': detection
			})
		}
		this.sendResults = function(simulationResults) {
			return new Signal(port, 'sendResults', {
					'simulationResults': simulationResults
			})
		}
		this.sendScreenOutput = function(screenOutput) {
			return new Signal(port, 'sendScreenOutput', {
					'screenOutput': screenOutput
			})
		}
		this.sendParameters = function(simulationParams) {
			return new Signal(port, 'sendParameters', {
					'simulationParams': simulationParams
			})
		}
		this.sendState = function(teamState) {
			return new Signal(port, 'sendState', {
					'teamState': teamState
			})
		}
	}
}