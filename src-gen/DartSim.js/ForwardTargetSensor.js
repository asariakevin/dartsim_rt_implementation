const Part = require('./rtpoet-rts/Part');
const Port = require('./rtpoet-rts/Port');
const Capsule = require('./rtpoet-rts/Capsule');
const FrameService = require('./rtpoet-rts/FrameService');
const routes = require('./routes');
const Log = require('./rtpoet-rts/Log')
const SimulatorToForwardTargetSensor = require('./SimulatorToForwardTargetSensor')
module.exports = class ForwardTargetSensor extends Capsule {
	static modulePath() {
		return '/'.concat('ForwardTargetSensor');
	}
	constructor() {
		super();
		this.context = {
		};
		this.internalPorts = {
		}
		this.borderPorts = {
			'simulatorPort': new Port (
				'simulatorPort',
				'SimulatorToForwardTargetSensor',
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
		this.simulatorPort = new SimulatorToForwardTargetSensor.conjugated (this.borderPorts['simulatorPort']);
		this.log = new Log.base (this.borderPorts['log']);
		this.parts = {
		};
		this.stateMachine = {
			context: this.context,
			initial: 'initialStateForwardTargetSensor',
			states: {
				'initialStateForwardTargetSensor': {
					id: 'dartsim_forwardtargetsensor_gmnaiqnl_initialstateforwardtargetsensor',
					entry: (context, msg) => {
						this.interpreter.send({type: '__init', data: this.actorParams.initData});
					},
					on: {
						'__init':             {
							target: '#dartsim_forwardtargetsensor_gmnaiqnl_waitingstateforwardtargetsensor',
							actions: (context, msg) => {
								this.dartsim_forwardtargetsensor_gmnaiqnl_zrhykfxm_obqmcdyw(context, msg);
							},
						}
					}
				},
				'waitingStateForwardTargetSensor': {
					id: 'dartsim_forwardtargetsensor_gmnaiqnl_waitingstateforwardtargetsensor',
					on: {
						'simulatorPort::createForwardTargetSensor': [
							{
								target: '#dartsim_forwardtargetsensor_gmnaiqnl_runningforwardtargetsensor',
								actions: (context, msg) => {
									this.dartsim_forwardtargetsensor_gmnaiqnl_mxxpdcki_dzzeaezo(context, msg);
								},
							}
						]
					}
				},
				'runningForwardTargetSensor': {
					id: 'dartsim_forwardtargetsensor_gmnaiqnl_runningforwardtargetsensor',
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
	dartsim_forwardtargetsensor_gmnaiqnl_zrhykfxm_obqmcdyw(context, msg) {
		let rtData = msg.data;
		log.log("[ForwardTargetSensor] from initial state to waiting state");
	}
	dartsim_forwardtargetsensor_gmnaiqnl_mxxpdcki_dzzeaezo(context, msg) {
		let rtData = msg.data;
		log.log("[ForwardTargetSensor] from waiting state to running state");
	}
}