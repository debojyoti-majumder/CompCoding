var net = require('net');

parameterEventMap = {}

function handleParmeterChange(parametrChangeDescription) {
    var timeStamp = parametrChangeDescription.timestamp;
    var eventData = parametrChangeDescription.eventDescription;

    tableKey = eventData.id;

    if( parameterEventMap[tableKey] == undefined ) {
        parameterEventMap[tableKey] = {dirty:true, logs:[{function:eventData.functionName, channel: eventData.channelName, parameter: eventData.parameterName, value: eventData.parameterValue}], updateStamp:timeStamp };
    } 
    else {
        if( timeStamp - parameterEventMap[tableKey].updateStamp > 200 ) {
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
                console.log(targetChannelName, sourcehwId);
            }
        }
    }
}

// This function should update the mongoDB database
function updateEventDataBase(eventLogs) {
    console.log(eventLogs);
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

server.listen(3021,'127.0.0.1');
