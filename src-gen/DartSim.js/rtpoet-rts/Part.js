module.exports = class Part {
	constructor(name, type, optional = false, plugin = false, replication = 1, borderPorts = {}) {
		this.name = name;
		this.type = type;
		this.optional = optional;
		this.plugin = plugin;
		this.replication = replication;
		this.borderPorts = borderPorts;
		this.slots = Array(this.replication).fill(0);
		this.slotReserved = Array(this.replication).fill(0);
		this.locations = Array(this.replication).fill(0);
	}
	add(instance, index = -1) {
		if(index == -1) {
			index = this.getNextAvailableSlotIndex();
			if(index == -1)
			return false;
		}
		// slot occuppied!
		if(this.slots[index])
		return -1;
		this.slots[index] = instance;
		return index;
	}
	remove(index) {
		if(index < 0 && index >= this.slots.length)
		return false;
		this.slots[index] = 0;
		this.slotReserved[index] = 0;
		return true;
	}
	getNextAvailableSlotIndex() {
		for(let i=0; i<this.replication; i++)
		if(!this.slots[i] && !this.slotReserved[i])
		return i;
		return -1;
	}
	reserveNextAvailableSlotIndex() {
		let index = this.getNextAvailableSlotIndex();
		if(index != -1)
		this.slotReserved[index] = 1;
		return index;
	}
	isFull() {
		return this.getNextAvailableSlotIndex() == -1
	}
}