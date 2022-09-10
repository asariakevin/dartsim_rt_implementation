const Coordinate = require('./Coordinate')
const TeamConfiguration = require('./TeamConfiguration')
module.exports = class TeamState {
	constructor() {
		this.position = null,
		this.directionX = null,
		this.directionY = null,
		this.config = null
	}
}