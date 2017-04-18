// Declaring the module depedencices
var net = require('net');
var mongoose = require('mongoose');
var Particle = require('particle-api-js');

var Schema = mongoose.Schema;

var particle = new Particle();
var token;
var discoveredDevices = [];

// It is a list of list
var aprioriInputList = [];

// This is to indicate if we need to predict paramteres or traing paramters
// supplied during starting the server
var trainmodel = false;

// This varibale will merge the IOT data and the patching point data
var instrumentTypeMap = {};

var parameterEventMap = {};
exludedFunctions = ['StripAssign'];

var logEntrySchema = new Schema({
    functionName: String,
    parameterName: String,
    value: Number
});

var logSchema = new Schema({
    channelName: String,
    instrumentType: String,
    dspChanges: [logEntrySchema]
});

var EventLog = mongoose.model('EventLog', logSchema);

function isExcluded(functionName) {
    var bFound = false;

    for(f in exludedFunctions ) {
        if( exludedFunctions[f] === functionName ) {
            bFound = true;
            break;
        }
    }

    return bFound;
}

function handleParmeterChange(parametrChangeDescription) {
    var timeStamp = parametrChangeDescription.timestamp;
    var eventData = parametrChangeDescription.eventDescription;

    tableKey = eventData.id;

    if( parameterEventMap[tableKey] == undefined ) {
        
        parameterEventMap[tableKey] = {dirty:true, logs:[{function:eventData.functionName, channel: eventData.channelName, parameter: eventData.parameterName, value: eventData.parameterValue}], updateStamp:timeStamp };
    } 
    else {
        if( timeStamp - parameterEventMap[tableKey].updateStamp > 200 ) {
            // Just avoid the Non DSP functions like strip assignment
            if( isExcluded(eventData.functionName) === false )
                parameterEventMap[tableKey].logs.push({function:eventData.functionName, channel: eventData.channelName, parameter: eventData.parameterName, value: eventData.parameterValue});  
        }
        else {
            var len = parameterEventMap[tableKey].logs.length;
            parameterEventMap[tableKey].logs[len-1].value = eventData.parameterValue;
        }

        parameterEventMap[tableKey].dirty = true;
        parameterEventMap[tableKey].updateStamp = timeStamp;
    }

}

function updateInstremntMapping( targetChannelName, sourcehwId ) {
    var instrumentType = instrumentTypeMap[sourcehwId];
    EventLog.findOne({'channelName':targetChannelName }, function(err, item) {

        if( item != null ) {
            if( instrumentType === undefined )  
                instrumentType = "generic";
            else
                item.instrumentType = instrumentType;
            
            item.save(function(err){console.log("Device type updated",err)});
        }
    });
}

// Handles paching action which will help us linking physical channel to virtual channels
function handlePatchingAction(patchingActionEvent) {
    var eventData = patchingActionEvent.eventDescription;
    
    // Only patch creating is needed
    if( eventData.isconnected ) {
        var targetString = eventData.target;
        var sourceString = eventData.source;

        var targetChannelName = targetString.substring(0, targetString.length - 4);
        var channelIndex = parseInt(targetChannelName.substring(targetChannelName.length-3, targetChannelName.length));
        
        // As of now will only be working with Stagebox line outs and monos
        if( targetChannelName[4] === 'm' ) {
            targetChannelName = "Inp Mono #" + channelIndex;
            
            if( sourceString.startsWith("Line In") ) {
                var sourcehwId = parseInt(sourceString.substring(7,10));
                updateInstremntMapping(targetChannelName, sourcehwId);
            }
        }
    }
}

// This function should update the mongoDB database
function updateEventDataBase(eventLogs) {
    if( trainmodel ) {
        for(log in eventLogs ) {
            var logEntry = eventLogs[log];
            var excl = isExcluded(logEntry.function);

            if( excl == false) {
                EventLog.findOne({'channelName':logEntry.channel}, function(err, item) {
                    // Only sucessful items
                    if( err == null ) {
                        
                        // Add the recode 
                        if( item == null ) {
                            // Adding new document for a channel type
                            var logItem = new EventLog({
                                    channelName: logEntry.channel,
                                    instrumentType: 'generic',
                                    dspChanges: []
                                });
                            
                            logItem.dspChanges.push({functionName:logEntry.function,parameterName:logEntry.parameter,value:log});
                            logItem.save(function(err){ console.log("channel document added", err)} );
                        }
                        else {
                            item.dspChanges.push({functionName:logEntry.function,parameterName:logEntry.parameter,value:log});
                            item.save(function(err){console.log("data added",err)});
                        }
                    }
                });
            }
        }
    }
}

function readAndBuildData() {
    var cursor = EventLog.find({}).cursor();

    cursor.on('data', function(document){
        var channelName = document.channelName;
        var dspChanges = document.dspChanges;

        var itemList = [];

        // Go through the DSP changes log
        for(ch in dspChanges) {

            var changeItem = dspChanges[ch];
            var fname = dspChanges[ch].functionName;
            var pname = dspChanges[ch].parameterName;

            if( fname !== undefined & pname !== undefined ) {
                var inpString = fname + '$' + pname; 
                
                var itemFound = false;
                for( i in itemList ) {
                    if( itemList[i] === inpString ){
                        itemFound = true;
                        break;
                    }
                }

                if( itemFound === false )
                    itemList.push(inpString);
            }
        }

        // Adding to apriori input list with the instremnt type
        itemList.push(document.instrumentType);
        aprioriInputList.push(itemList);
    })

    cursor.on('close', function(){
        console.log(aprioriInputList);
    })
}

// Gets called perodicly to check for event and flush out the new events
function lazzyDBWritter() {
    for( parameter in parameterEventMap ) {
        if( parameterEventMap[parameter].logs && parameterEventMap[parameter].logs.length > 0 ) {
            // Updaing the database
            updateEventDataBase(parameterEventMap[parameter].logs);
            parameterEventMap[parameter].logs = [];
        }
    }
}

// This is main server loop which gets the data from the and does post processing
var server = net.createServer( function(socket) {
    console.log("Got client connection");

    var dbWriterJob = setInterval(lazzyDBWritter,5000);
    var titleOpenFound = false;

    // Build the analytics model if training is not enabled
    if( trainmodel == false ) {
        readAndBuildData();
    }

    socket.on('data',function(rawData) {
        var jsonString = rawData.toString();
        
        try {
            // Parsing the JSON string
            var eventJSONObject = JSON.parse(jsonString)

            if( eventJSONObject.type === 'ParameterChange') {
                if( titleOpenFound ) handleParmeterChange(eventJSONObject);
            }
            else if(eventJSONObject.type === 'GeneralEvent') {
                var msg = eventJSONObject.eventDescription.message;
                if( msg.indexOf("opened") !== -1 )
                    titleOpenFound = true;
            }
            else if(eventJSONObject.type === 'PatchingAction') {
                if( titleOpenFound ) handlePatchingAction(eventJSONObject);
            }
        }
        catch(e) {
            //console.log("Error in parsing event log data",jsonString);
        }
    })
});

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

                        // Pasring the event data from the cloud
                        var n = eventdata.indexOf('/');
                        var instrumentType = eventdata.substring(0,n);
                        var slot = parseInt(eventdata.substring(n+1));

                        // Updaing the in memory mapping information
                        instrumentTypeMap[slot] = instrumentType;
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

server.listen(3021,'127.0.0.1');
mongoose.connect('mongodb://localhost/mixerdata');

if( process.argv.length > 2 )
    trainmodel = true;
