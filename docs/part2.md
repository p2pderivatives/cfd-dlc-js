# Part 2: Setup

The code for this tutorial is [available on github](https://github.com/p2pderivatives/cfd-dlc-js/tree/master/examples/dlccli).

## Pre-requisite

This tutorial uses Typescript and nodejs, if you don't have nodejs installed, you can follow the instructions [here](https://nodejs.org/en/).

### Bitcoind

First you need to have bitcoind installed.
You can also use a docker container if that is more convenient for you, but the instruction in this tutorial will assume a locally installed one (note that it shouldn't make that big a difference).

### Setup

Start by initializing an npm project:

```bash
npm init
```

Set the entry point to `index.ts`:

```bash
entry point: (index.js) index.ts
```

Fill the rest however you want.

We will then install some dependencies:

```bash
npm install bitcoin-simple-rpc inquirer inquirer-datepicker uuid --save
```

Then install the DLC library as well as the base CFD library (useful for some utility functions):

```bash
npm install github:cryptogarageinc/cfd-js#v0.2.5 github:cryptogarageinc/cfd-dlc-js#v0.0.8
```

Add some dev dependencies (you can skip those if you prefer to use plain JavaScript):

```bash
npm install @types/inquirer @types/node ts-node typescript --save-dev
```

We also add a script to launch the application in the package.json:

```json
  "scripts": {
    "example": "ts-node index.ts"
  },
```

Finally, create the following `tsconfig.json` file in the root folder:

```json
{
  "compilerOptions": {
    "target": "ESNext",
    "moduleResolution": "node",
    "resolveJsonModule": true,
    "esModuleInterop": true,
    "module": "commonjs"
  }
}
```

In [the third part](./part3.md) we will finally start coding!
