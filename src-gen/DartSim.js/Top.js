const Part = require('./rtpoet-rts/Part');
const Port = require('./rtpoet-rts/Port');
const Capsule = require('./rtpoet-rts/Capsule');
const FrameService = require('./rtpoet-rts/FrameService');
const routes = require('./routes');
const ForwardTargetSensor = require('./ForwardTargetSensor')
const AdapterInterface = require('./AdapterInterface')
module.exports = class Top extends Capsule {
	static modulePath() {
		return '/'.concat('Top');
	}
	constructor() {
		super();
		this.context = {
		};
		this.forwardTargetSensor = new Part('forwardTargetSensor', ForwardTargetSensor, false, false, 1, {
				'simulatorPort': {
					name: 'simulatorPort',
					protocol: 'SimulatorToForwardTargetSensor',
					isConjugated: true,
					isWired: false,
					isPublish: false,
					isRelay: false,
					isNotification: false,
					isAutomaticRegistration: true,
					registrationOverride: '',
					replication: 1
				},
				'log': {
					name: 'log',
					protocol: 'Log',
					isConjugated: false,
					isWired: false,
					isPublish: false,
					isRelay: false,
					isNotification: false,
					isAutomaticRegistration: true,
					registrationOverride: '',
					replication: 1
				}
		});
		this.adapterInterface = new Part('adapterInterface', AdapterInterface, false, false, 1, {
				'adapterManager': {
					name: 'adapterManager',
					protocol: 'AdapterInterfaceToSimulatorProtocol',
					isConjugated: true,
					isWired: false,
					isPublish: false,
					isRelay: false,
					isNotification: false,
					isAutomaticRegistration: true,
					registrationOverride: '',
					replication: 1
				},
				'log': {
					name: 'log',
					protocol: 'Log',
					isConjugated: false,
					isWired: false,
					isPublish: false,
					isRelay: false,
					isNotification: false,
					isAutomaticRegistration: true,
					registrationOverride: '',
					replication: 1
				}
		});
		this.internalPorts = {
		}
		this.borderPorts = {
		}
		this.parts = {
			'forwardTargetSensor': this.forwardTargetSensor,
			'adapterInterface': this.adapterInterface
		};
	}
	initialize(selfActor) {
		this.actor = selfActor;
		this.actorParams = selfActor.getCustomParameters();
		this.name = this.actorParams.name;
		this.index = this.actorParams.index;
		this.fqn = this.actorParams.fqn;
		this.routingTable = {
			'forwardTargetSensor': [
				routes[this.fqn + ".forwardTargetSensor[0]"]
			],
			'adapterInterface': [
				routes[this.fqn + ".adapterInterface[0]"]
			]
		};
		this.routingTable[this.name] = routes[this.fqn];
		let promises = [
			selfActor.createChild(ForwardTargetSensor.modulePath(), {
					name: this.fqn + '.forwardTargetSensor[0]',
					customParameters: {
						name: 'forwardTargetSensor',
						index: 0,
						fqn: this.fqn + '.forwardTargetSensor[0]'
					}
					}).then(childActor => {
					this.parts['forwardTargetSensor'].add(childActor, 0)
			}),
			selfActor.createChild(AdapterInterface.modulePath(), {
					name: this.fqn + '.adapterInterface[0]',
					customParameters: {
						name: 'adapterInterface',
						index: 0,
						fqn: this.fqn + '.adapterInterface[0]'
					}
					}).then(childActor => {
					this.parts['adapterInterface'].add(childActor, 0)
			})
		];
		return Promise.all(promises).then(actors => {
				this.wireParts();
		});
	}
}