var Particle = require('particle-api-js');
var particle = new Particle();
var token;
var discoveredDevices = [];

particle.login({
    username: 'debojyoti.majumder@gmail.com',
    password: 'Safeb00t'
}).then(
    // On successful loging get the token
    function(data) {
        token = data.body.access_token;
        console.log("Logged in sucessfully, token:",token);

        var deviceListPromise = particle.listDevices({auth:token});
        
        deviceListPromise.then(function(devices) {
            discoveredDevices = devices.body;
            
            for(d in discoveredDevices ) {
                var device = discoveredDevices[d];
                
                particle.getEventStream({ deviceId: device.id, name: 'adpater-activated', auth: token }).then(function(stream) {
                    stream.on('event', function(data) {
                        var eventdata = data.data;
                        console.log(eventdata);
                    });
                });
            }
        },
        function(err){
            console.log("Can not retrive list of devices",err);
        });
    },
    function(err) {
        console.log("Login failed", err);
    }
);

console.log('Press any key to exit');
process.stdin.setRawMode(true);
process.stdin.resume();
process.stdin.on('data', process.exit.bind(process, 0));
