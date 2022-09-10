const Coordinate = require('./Coordinate')
module.exports = class SimulationResults {
	constructor() {
		this.destroyed = null,
		this.whereDestroyed = null,
		this.targetsDetected = null,
		this.missionSuccess = null,
		this.decisionTimeAvg = null,
		this.decisionTimeVar = null
	}
}