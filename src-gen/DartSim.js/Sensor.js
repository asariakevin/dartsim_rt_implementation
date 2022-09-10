module.exports = class Sensor {
	constructor() {
		this.fpr = null,
		this.fnr = null,
		this.uniform = null,
		this.randomGenerator = null
	}
	Sensor(falsePositiveRate, falseNegativeRate) {
		fpr(falsePositiveRate);
		fnr(falseNegativeRate);
		randomGenerator.seed(RandomSeed::getNextSeed());
	}
	sense(truth) {
		bool result = truth;
		double random = uniform(randomGenerator);
		if (truth && random <= fnr) {
			result = false;
			} else if (!truth && random <= fpr) {
			result = true;
		}
		return result;
	}
}