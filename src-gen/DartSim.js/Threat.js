module.exports = class Threat {
	constructor() {
		this.range = null,
		this.destructionFormationFactor = null,
		this.uniform = null,
		this.randomGenerator = null
	}
	Threat(range, destructionFormationFactor) {
		range(range);
		destructionFormationFactor(destructionFormationFactor);
		randomGenerator(RandomSeed::getNextSeed());
	}
	isDestroyed(threatEnv, config, location) {
		bool destroyed = false;
		bool threat = threatEnv.isObjectAt(location);
		if (threat) {
			double probOfDestruction = getProbabilityOfDestruction(config);
			double random = uniform(randomGenerator);
			destroyed = (random <= probOfDestruction);
		}
		return destroyed;
	}
	getProbabilityOfDestruction(config) {
		double probOfDestruction =
		((config.formation == TeamConfiguration::Formation::LOOSE) ? 1.0 : (1.0 / destructionFormationFactor))
		* max(0.0, range - config.altitudeLevel) / range;
		// ECM reduces the prob of destruction
		if (config.ecm) {
			probOfDestruction *= 0.25;
		}
		return probOfDestruction;
	}
}