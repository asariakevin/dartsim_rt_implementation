module.exports = class SimulationParams {
	constructor() {
		this.mapSize = 40,
		this.squareMap = false,
		this.altitudeLevels = 4,
		this.changeAltitudeLatencyPeriods = 1,
		this.optimalityTest = false,
		this.longRangeSensor = null,
		this.downwardLookingSensor = null,
		this.threat = null
	}
}