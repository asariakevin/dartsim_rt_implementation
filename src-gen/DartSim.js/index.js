const actors = require('comedy');
const Port = require('rtpoet-rts/Port');
const Top = require('./Top');
actors()
.rootActor()
.then(rootActor => rootActor.createChild('/Top', {
			name : 'Top[0]',
			customParameters: {
				name: 'Top[0]',
				index: 0,
				fqn: 'Top[0]',
				data: {}
			}
}))
.then(childActor => {
		childActor.send('run');
});