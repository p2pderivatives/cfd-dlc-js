# Part 1: Introduction

The goal of this tutorial is to learn how to create an application that makes use of Discreet Log Contracts (DLC) using the [cfd-dlc-js library](https://github.com/p2pderivatives/cfd-dlc-js).
We will be developing a simple command line application to create DLC and execute them on a Bitcoin regtest.
In this first part we will first briefly go over the concept of DLC, so if you are already familiar with it feel free to skip directly to [the second part](./part2.md).

## Discreet Log Contracts

DLC [were originally proposed by Taddheus Dryja](https://adiabat.github.io/dlc.pdf).
The goal of DLC is to enable setting up contracts between two parties directly on the Bitcoin blockchain.
To determine the outcome of the contract, an oracle is used.
The clever part about DLC is enabling the execution of the contract by the parties without them having to notify the oracle.
This characteristic is the reason for the "discreet log" part of the name, as they don't leave any trace visible to the oracle.
This is achieved by a peculiar use of Schnorr signatures, which is described in [the original paper](https://adiabat.github.io/dlc.pdf) for the curious reader.
What is important to note here, is that the oracle is required to publish in advance a unique R value for each event on which a signature will be provided in the future (think about it as a random number).
The public key of the oracle must also be known.

Another characteristic of DLC is that both parties can setup up the contract in a trust-less manner, albeit a minimum trust in the oracle that it will not collude with on of the parties.
This is possible thanks to the use of a particular set of Bitcoin transactions that make up the contract.

### Fund transaction

The fund transaction is used to lock the collaterals of both parties in the contract. It takes a set of UTXOs from each party as input, and locks the collaterals in a 2-of-2 multisig output.
It can also contain change outputs for each parties in case their total inputs is larger than the desired collateral.

### Contract Execution Transactions

Contract Execution Transactions (CETs) encode a possible outcome of a contract.
It takes as input the 2-of-2 multisig from the fund transaction, and contains two outputs, corresponding to the payouts for each party for a given outcome.

Each party holds a different set of CETs, where the second input pays directly to their counter-party.
The first output on the other hand requires a signature from the oracle on the outcome of the event on which the contract is based to be unlocked.
If one of the party were to broadcast a CET for an incorrect outcome (one for which they don't have an oracle signature), the first input also allows the counter-party to claim it after a certain time (using [the CheckSequenceVerify opcode](https://github.com/bitcoin/bips/blob/master/bip-0112.mediawiki)).

### Closing Transaction

A closing transaction is used by the broadcaster of a CET to retrieve the funds locked in the first output.
It must provide a signature created using a combination of the sender's private key and a signature from the oracle on the correct outcome.
It must usually be broadcast at the same time as the CET that it spends from.

### Penalty Transaction

A penalty transaction is used when a party has broadcast an incorrect CET (for an outcome on which the oracle has not signed), for the counter-party to retrieve the funds.

### Refund Transaction

To mitigate the risk of an oracle failure, the refund transaction can be used to return the initial collaterals to each party.
This transaction is timed locked (using the `nLockTime` parameter) to some time after the contract expiry to prevent any party using it before.

### Mutual Closing Transaction

Once the oracle has published a signature for the outcome of the event on which the contract is based, both parties are able to close the contract by broadcasting their CETs and a closing transaction.
However this requires broadcasting two transactions.
They can instead cooperate and close the contract using a mutual closing transaction which spends from the 2-of-2 output of the fund transaction and allocates the outputs accordingly to the outcome.

### Protocol

In order to ensure that their funds do not get locked if their counter-party misbehaves, both parties need to follow a specific protocol to setup the contract.
We will call the local party the initiator of the contract, and remote party the receiver of the contract.
This protocol is made out of of three messages:

1. The offer message contains information about the contract such as each parties collateral, the fee rate to use when building the transactions, information about the oracle (public key and R value), the possible outcomes, as well the the set of UTXOs for the local party.
1. The accept message contains the set of UTXOs for the remote party, a set of signatures for the local CETs, and a signature for the refund transaction.
1. The sign message contains a set of signatures for the remote CETs and a signature for the refund transaction.

## Notes

Specifications for DLC are [under active development](https://github.com/discreetlogcontracts/dlcspecs/), feel free to reach out if you want to contribute or have questions.
Check also [the resources page](https://github.com/discreetlogcontracts/dlcspecs/blob/master/Resources.md) to find more info on DLC.

---

Now that we have a basic understanding of DLC, let's start coding!
