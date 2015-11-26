var addon = require('./build/Release/addon.node');

console.error(addon.Echo('hello kitty!'));
console.error(addon.EchoNumber());

addon.EchoAsync('hello kitty!', function(err, info){
    console.error(info);
});


var data = "The data include some UTF8 encoding string.";
var len = Buffer.byteLength(data);
var buf = new Buffer(len);
buf.write(data, 0, 'UTF8');
console.error(addon.EchoBinary(buf).toString());
