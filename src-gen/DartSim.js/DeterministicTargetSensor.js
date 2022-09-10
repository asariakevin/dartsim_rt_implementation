module.exports = class DeterministicTargetSensor {
	constructor() {
		this.range = null,
		this.detectionFormationFactor = null,
		this.uniform = null,
		this.randomGenerator = null
	}
	DeterministicTargetSensor(range, detectionFormationFactor) {
		range(range);
		detectionFormationFactor(detectionFormationFactor);
		randomGenerator(RandomSeed::getNextSeed());
	}
	sense(config, targetPresent) {
		bool detected = false;
		if (targetPresent) {
			double probOfDetection = getProbabilityOfDetection(config);
			double random = uniform(randomGenerator);
			detected = (random <= probOfDetection);
		}
		return detected;
	}
	getProbabilityOfDetection(config) {
		double effectiveRange = range;
		if (config.formation == TeamConfiguration::Formation::TIGHT) {
			effectiveRange = range / detectionFormationFactor;
		}
		// ECM reduces the range of detection
		if (config.ecm) {
			effectiveRange *= 0.75;
		}
		double probOfDetection = ((effectiveRange - config.altitudeLevel) > 0.0) ? 1.0 : 0.0;
		return probOfDetection;
	}
}