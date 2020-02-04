# cfd-dlc-js

Javascript wrapper for the cfd-dlc library

# Setup

Run:
```
npm install
npm run cmake_all
```

# Run example code

Example usage can be found in `./wrap_js/compatibility_test_ts.ts`.
Running this code however requires the `cfd-js` library (and I have not yet found a good way to integrate it in the setup).
To install it:

```
git clone https://github.com/cryptogarageinc/cfd-core
git checkout v0.0.17
npm install
npm link
```

Then go back to the root folder of `cfd-dlc-js` and run:
```
npm link
```

Then you should be able to run the example using `ts-node` (`npm install ts-node`):
```
ts-node ./wrap_js/compatibility_test_ts.ts
```
# Code generation

The interface between the C++ layer and JS/TS is automatically generated from the files located in the `src/input_json_format` folder.
To update an interface update the json file and run `npm run convert_json`.
