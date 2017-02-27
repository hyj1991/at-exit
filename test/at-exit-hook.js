'use strict';
const atExit = require('../index');

atExit(function () {
    console.log('Now before exit!');
});