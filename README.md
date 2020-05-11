# cfd-dlc-js

Javascript wrapper for the cfd-dlc library

# Tutorial

Learn how to develop an application integrating DLC using this library with the tutorial available at:
https://p2pderivatives.github.io/cfd-dlc-js/

# Setup

Run:

```
npm install
npm run cmake_all
```

# Test

## Unit tests

To run unit tests, use `npm test`.

## Integration tests

To run integration tests, you need to have bitcoin installed.
Start by running

```
./integration_tests/__tests__/start-bitcoind.sh $(pwd) integration_tests
```

to start a bitcoind instance in regtest.

Then run `npm run test_integration`.

# Code generation

The interface between the C++ layer and JS/TS is automatically generated from the files located in the `src/input_json_format` folder.
To update an interface update the json file and run `npm run convert_json`.
