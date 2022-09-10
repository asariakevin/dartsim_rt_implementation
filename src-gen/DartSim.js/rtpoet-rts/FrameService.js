module.exports = class FrameService {
	static migrate(actor, part, location, index = -1) {
		if(index >= part.locations.length)
		return false;
		if(index != -1) {
			if(part.locations[index]
				&& part.locations[index].mode == location.mode
			&& part.locations[index].host == location.host)
			return false;
			part.locations[index] = location;
			if(part.slots[index]) {
				return part.slots[index].sendAndReceive('save').then(oldState => {
						let config = part.slots[index].actor.config;
						config['mode'] = part.locations[index].mode;
						config['host'] = part.locations[index].host;
						return part.slots[index].changeConfiguration(config).then(newActor => {
								actor.sendAndReceive('wireSlot', part.name, index).then(reply => {
										part.slots[index].send('run', oldState);
								});
								return newActor;
						});
				});
			}
			return true;
		}
		let promisses = [];
		for(let i=0; i<part.replication; i++)
		promisses.push(FrameService.migrate(actor, part, location, i));
		return Promise.all(promisses);
	}
	static import(actor, instance, part, index = -1) {
		if(!part.plugin)
		return false;
		if(part.isFull())
		return false;
		if(index >= part.slots.length)
		return false;
		if(index == -1)
		index = part.reserveNextAvailableSlotIndex();
		return actor.createChild(instance, {
				name: part.name+'['+index+']',
				customParameters: {
					name: part.name,
					index: index
				}
				}).then(childActor => {
				part.add(childActor, index);
				actor.sendAndReceive('wireSlot', part.name, index).then(reply => {
						//childActor.send('run');
				});
				return childActor;
		});
	}
	static deport(actor, part, index = -1) {
		if(!part.plugin)
		return false;
		if(index != -1 && part.slots[index]) {
			return actor.sendAndReceive('unwireSlot', part.name, index).then(reply => {
					part.remove(index);
			});
		}
		let promisses = [];
		for(let i=0; i<part.slots.length; i++)
		promisses.push(FrameService.deport(actor, part, i));
		return Promise.all(promisses);
	}
	static incarnate(actor, type, data = {}) {
		return actor.createChild(type.modulePath(), {
				customParameters: {
					data: data
				}
		});
	}
	static incarnateAt(actor, part, type, data = {}, index = -1) {
		if(!part.optional && !part.plugin)
		return false;
		if(type != part.capsule)
		return false;
		if(part.isFull())
		return false;
		if(index >= part.slots.length)
		return false;
		if(index == -1)
		index = part.reserveNextAvailableSlotIndex();
		return actor.createChild(type.modulePath(), {
				name: part.name+'['+index+']',
				customParameters: {
					name: part.name,
					index: index,
					data: data
				}
				}).then(childActor => {
				part.add(childActor, index);
				actor.sendAndReceive('wireSlot', part.name, index).then(reply => {
						childActor.send('run');
				});
				return childActor;
		});
	}
	static destroy(instance) {
		instance.destroy();
	}
}