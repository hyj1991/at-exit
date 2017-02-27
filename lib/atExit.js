/**
 * @description js bridge, at exit hook
 * @author https://github.com/hyj1991
 */
'use strict';
let ae = null;
try {
    ae = require('../build/Release/atExit.node');
} catch (e) {
    ae = require('../build/Debug/atExit.node');
}

let callbaclBeforeExit = [];

/**
 * @param cbs function or array: atExit(callback) or atExit([cb1, cb2, ...])
 */
function atExit(cbs) {
    if (!ae) {
        console.error("atExit.node build failed!");
        return;
    }

    if (callbaclBeforeExit.length > 5) {
        console.error("callbacks called before process exit must less than 5!");
        return;
    }

    if (!Array.isArray(cbs)) cbs = [cbs];
    callbaclBeforeExit = callbaclBeforeExit.concat(cbs);
    //register cbs
    ae.registerFunction(function () {
        callbaclBeforeExit.forEach(cb => cb());
    });
}

module.exports = atExit;