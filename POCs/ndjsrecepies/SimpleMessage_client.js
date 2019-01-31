"use strict";

const messagingLib = require('./SimpleMessage');

let m1 = new messagingLib.SimpleMessage("M1", 10);
let m2 = new messagingLib.SimpleMessage("M2", 5);

console.log(m1.printableString);
console.log(m2.printableString);

m2.repetation = 20;
console.log(m2.printableString);
