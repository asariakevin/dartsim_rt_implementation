module.exports = class RandomSeed {
	constructor() {
		this.instance = null,
		this.uniform = null,
		this.randomGenerator = null
	}
	RandomSeed() {
		randomGenerator(std::random_device()())
	}
	getInstance() {
		if (instance.get() == nullptr) {
			instance.reset(new RandomSeed);
		}
		return *instance;
	}
	getNextSeed() {
		return getInstance().getSeed();
	}
	seed(seed) {
		getInstance().randomGenerator.seed(seed);
	}
	getSeed() {
		return uniform(randomGenerator);
	}
}