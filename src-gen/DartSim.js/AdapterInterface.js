const Part = require('./rtpoet-rts/Part');
const Port = require('./rtpoet-rts/Port');
const Capsule = require('./rtpoet-rts/Capsule');
const FrameService = require('./rtpoet-rts/FrameService');
const routes = require('./routes');
const Log = require('./rtpoet-rts/Log')
const AdapterInterfaceToSimulatorProtocol = require('./AdapterInterfaceToSimulatorProtocol')
module.exports = class AdapterInterface extends Capsule {
	static modulePath() {
		return '/'.concat('AdapterInterface');
	}
	constructor() {
		super();
		this.context = {
		};
		this.internalPorts = {
		}
		this.borderPorts = {
			'adapterManager': new Port (
				'adapterManager',
				'AdapterInterfaceToSimulatorProtocol',
				true,
				false,
				false,
				false,
				false,
				false,
				true,
				'',
				1,
				this
			),
			'log': new Port (
				'log',
				'Log',
				false,
				false,
				false,
				false,
				false,
				false,
				true,
				'',
				1,
				this
			)
		}
		this.adapterManager = new AdapterInterfaceToSimulatorProtocol.conjugated (this.borderPorts['adapterManager']);
		this.log = new Log.base (this.borderPorts['log']);
		this.parts = {
		};
		this.stateMachine = {
			context: this.context,
			initial: 'initialStateAdapterInterfaceCapsule',
			states: {
				'initialStateAdapterInterfaceCapsule': {
					id: 'dartsim_adapterinterface_xrormfbb_initialstateadapterinterfacecapsule',
					entry: (context, msg) => {
						this.interpreter.send({type: '__init', data: this.actorParams.initData});
					},
					on: {
						'__init':             {
							target: '#dartsim_adapterinterface_xrormfbb_running',
							actions: (context, msg) => {
								this.dartsim_adapterinterface_xrormfbb_dgavkjip_rdspmlzm(context, msg);
							},
						}
					}
				},
				'running': {
					id: 'dartsim_adapterinterface_xrormfbb_running',
				},
			},
		};
	}
	initialize(selfActor) {
		this.actor = selfActor;
		this.actorParams = selfActor.getCustomParameters();
		this.name = this.actorParams.name;
		this.index = this.actorParams.index;
		this.fqn = this.actorParams.fqn;
		this.routingTable = {
		};
		this.routingTable[this.name] = routes[this.fqn];
		let promises = [
		];
		return Promise.all(promises).then(actors => {
				this.wireParts();
		});
	}
	dartsim_adapterinterface_xrormfbb_dgavkjip_rdspmlzm(context, msg) {
		let rtData = msg.data;
		log.log("[AdapterInterface] from initial state to running state");
	}
}