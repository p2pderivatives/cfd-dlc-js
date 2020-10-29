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

While the DLC protocol originally described used the oracle signature to tweak one of the party's private key, the latest version uses so-called adaptor signatures, which essentially enable the creation of verifiably encrypted signatures.
In this protocol, each party encrypts their signatures in such a way that the signature validity can be verified, but can only be decrypted using a secret, which in DLC correspond to the signature the Oracle releases at contract maturity.

Another characteristic of DLC is that both parties can setup up the contract in a trust-less manner, albeit a minimum trust in the oracle that it will not collude with on of the parties.
This is possible thanks to the use of a particular set of Bitcoin transactions that make up the contract.

### Fund transaction

The fund transaction is used to lock the collaterals of both parties in the contract. It takes a set of UTXOs from each party as input, and locks the collaterals in a 2-of-2 multisig output.
It can also contain change outputs for each parties in case their total inputs is larger than the desired collateral.

### Contract Execution Transactions

Contract Execution Transactions (CETs) encode a possible outcome of a contract.
It takes as input the 2-of-2 multisig from the fund transaction, and contains two outputs, corresponding to the payouts for each party for a given outcome.


### Refund Transaction

To mitigate the risk of an oracle failure, the refund transaction can be used to return the initial collaterals to each party.
This transaction is timed locked (using the `nLockTime` parameter) to some time after the contract expiry to prevent any party using it before.

### Protocol

In order to ensure that their funds do not get locked if their counter-party misbehaves, both parties need to follow a specific protocol to setup the contract.
We will call the local party the initiator of the contract, and remote party the receiver of the contract.
This protocol is made out of of three messages:

1. The offer message contains information about the contract such as each parties collateral, the fee rate to use when building the transactions, information about the oracle (public key and R value), the possible outcomes, as well the the set of UTXOs for the local party.
1. The accept message contains the set of UTXOs for the remote party, a set of adaptor signatures for the CETs from the remote party, and a signature for the refund transaction.
1. The sign message contains a set of adaptor signatures for the CETs from the local party and a signature for the refund transaction.

## Notes

Specifications for DLC are [under active development](https://github.com/discreetlogcontracts/dlcspecs/), feel free to reach out if you want to contribute or have questions.
Check also [the resources page](https://github.com/discreetlogcontracts/dlcspecs/blob/master/Resources.md) to find more info on DLC.

---

Now that we have a basic understanding of DLC, we will start coding in [part 2](./part2.md)!
