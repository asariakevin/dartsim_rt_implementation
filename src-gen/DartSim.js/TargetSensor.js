module.exports = class TargetSensor {
	constructor() {
		this.range = null,
		this.detectionFormationFactor = null,
		this.uniform = null,
		this.randomGenerator = null
	}
	TargetSensor(range, detectionFormationFactor) {
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
		double probOfDetection =
		((config.formation == TeamConfiguration::Formation::LOOSE) ? 1.0 : 1 / detectionFormationFactor)
		* max(0.0, range - config.altitudeLevel) / range;
		// ECM reduces the prob of detection
		if (config.ecm) {
			probOfDetection *= 0.25;
		}
		return probOfDetection;
	}
}