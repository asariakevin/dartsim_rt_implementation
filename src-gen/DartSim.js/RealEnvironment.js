const Coordinate = require('./Coordinate')
module.exports = class RealEnvironment {
	constructor() {
		this.size = null,
		this.envMap = null
	}
	populate(size, numOfObjects) {
		this->size = size;
		envMap.clear();
		std::default_random_engine gen(RandomSeed::getNextSeed());
		std::uniform_int_distribution<> unifX(0, size.x - 1);
		std::uniform_int_distribution<> unifY(0, size.y - 1);
		while (numOfObjects > 0) {
			unsigned x = unifX(gen);
			unsigned y = unifY(gen);
			while (envMap[Coordinate(x,y)]) {
				x = unifX(gen);
				y = unifY(gen);
			}
			envMap[Coordinate(x,y)] = true;
			numOfObjects--;
		}
	}
	getSize() {
		return size;
	}
	isObjectAt(location) {
		bool isThere = false;
		const auto it = envMap.find(location);
		if (it != envMap.end()) {
			isThere = it->second;
		}
		return isThere;
	}
	setAt(location, objectPresent) {
		envMap[location] = objectPresent;
	}
}