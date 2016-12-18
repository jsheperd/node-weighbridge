#!/usr/local/bin/node
var serialport = require('serialport');
var SerialPort = serialport.SerialPort;
var Readline = SerialPort.parsers.Readline;

var port = new SerialPort('/dev/ttyUSB0', { baudrate: 9600, });
var parser = new Readline({ delimiter: '\r\n' })
port.pipe(parser);

function serialMsg (cmd) {
  console.log("Message:" + cmd);
  port.write('AX:'+cmd+'\r\n');
}

port.on('open', function() {
  setTimeout(function() { serialMsg('T?')}, 1000);
  setTimeout(function() { serialMsg('N?')}, 2000);
  setTimeout(function() { serialMsg('B?')}, 3000);
  setTimeout(function() { serialMsg('NU')}, 4000);
  setTimeout(function() { serialMsg('TA')}, 5000);
  setTimeout(function() { serialMsg('BR')}, 6000);
  setTimeout(function() { serialMsg('NT')}, 7000);
  setTimeout(function() { serialMsg('TR')}, 8000);
  setTimeout(function() { serialMsg('TA')}, 9000);
});

// port.on('data', function (data) {
//   console.log('Data: ' + data);
// });

parser.on('data', function(resp) {
  console.log('Response: ', resp);
});
