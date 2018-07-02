"use strict";

var WebSocketServer = require('websocket').server;
var http = require('http');

var appServer = http.createServer(function(request, response) {
});

appServer.listen(1337, function() {
    console.log("Server running on port 1337");
});

var wsLoginServer = new WebSocketServer({ httpServer: appServer });

wsLoginServer.on('request', function(request) {
    // Accepting the connection for websocket
    console.log("Request came for Login webscoket Requset", request);
    var requestUrl = request.resourceURL;

    if( requestUrl.path == '/web/login') {
        var loginRequestConnection = request.accept(null, request.origin);

        loginRequestConnection.on('message', function(data) {
            console.log("Login Message received", data);
        });
    }
    else if( requestUrl.path == '/web/switcher') {
        var switcherRequestConnection = request.accept(null, request.origin);

        switcherRequestConnection.on('message', function(data) {
            console.log("Switcher Message:", data);
        })
    }
    else {
        console.log("Not accepting the connection");
        request.reject(404, "Invalid Path");
    }
});
