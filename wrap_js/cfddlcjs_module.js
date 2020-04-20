"use strict";
const path = require("path");
const fs = require("fs");

// check exists
let buildTarget = "Release";
try {
  fs.statSync(path.resolve(__dirname, "./build/Release"));
} catch (err) {
  try {
    fs.statSync(path.resolve(__dirname, "./build/Debug"));
    buildTarget = "Debug";
  } catch (err) {
    throw new ReferenceError(`missing cfddlcjs module. ${err}`);
  }
}

// load cfd-dlc-js module
const cfddlcjs = require(`./build/${buildTarget}/cfddlc_js`);
if (typeof cfddlcjs !== "object" || cfddlcjs === null) {
  throw new ReferenceError("Not support typeof cfddlcjs.");
}

const parseBigInt = function (_, value) {
  return typeof value == "bigint" ? value.toString() : value;
};

const wrappedModule = {};

Object.keys(cfddlcjs).forEach((key) => {
  const hook = function (...args) {
    if (args.length > 1) {
      throw Error(
        "ERROR: Invalid argument passed:" + `func=[], args=[${args}]`
      );
    }

    let retObj;
    try {
      // stringify all arguments
      const argStr = args.map((arg) => JSON.stringify(arg, parseBigInt));

      retObj = JSON.parse(cfddlcjs[key].apply(wrappedModule, argStr));
    } catch (err) {
      // JSON convert error
      throw new Error(
        "ERROR: Invalid function call:" +
          ` func=[${key}], args=[${args}] ` +
          err
      );
    }

    if (retObj.hasOwnProperty("error")) {
      throw new Error(JSON.stringify(retObj.error));
    }
    return retObj;
  };
  Object.defineProperty(wrappedModule, key, {
    value: hook,
    enumerable: true,
  });
});

module.exports = wrappedModule;
