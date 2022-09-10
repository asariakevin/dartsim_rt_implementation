const Formation = require('./Formation')
module.exports = class TeamConfiguration {
	constructor() {
		this.altitudeLevel = null,
		this.formation = null,
		this.ecm = null,
		this.ttcIncAlt = null,
		this.ttcDecAlt = null,
		this.ttcIncAlt2 = null,
		this.ttcDecAlt2 = null
	}
}