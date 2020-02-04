import * as cfddlcjs from '../index.js';
import * as cfdjs from 'cfd-js';
import * as models from "./models";

import * as fs from 'fs';
import testVectors from './compatibility_input.json';

function GetPubFromPriv(privkey: string) {
    let reqPrivKey = {
        privkey: privkey,
        isCompressed: true,
    };

    return cfdjs.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
}

function GetExtPubFromExtPriv(extPriv: string) {
    const reqJson = {
        extkey: extPriv,
        network: 'testnet',
    };

    let resp = cfdjs.CreateExtPubkey(reqJson);
    return resp.extkey;
}

function GetPrivKeyFromExtPriv(extPriv: string) {
    const reqJson = {
        extkey: extPriv,
        network: 'testnet',
        wif: false,
        isCompressed: true,
    }

    let resp = cfdjs.GetPrivkeyFromExtkey(reqJson);
    return resp.privkey;
}

function GetPubkeyFromExtPriv(extPriv: string) {
    let priv = GetPrivKeyFromExtPriv(extPriv);
    return GetPubFromPriv(priv);
}

function GetChildPrivKeyFromExtPriv(extPriv: string, index: number) {
    let reqJson: cfdjs.CreateExtkeyFromParentPathRequest = {
        extkey: extPriv,
        network: "regtest",
        path: `m/0/${index}`,
        extkeyType: "extPrivkey",
        childNumberArray: [],
    }
    let extChild = cfdjs.CreateExtkeyFromParentPath(reqJson).extkey;

    let reqJson2: cfdjs.GetPrivkeyFromExtkeyRequest = {
        extkey: extChild,
        network: "regtest",
        wif: false,
        isCompressed: false,
    };

    let priv = cfdjs.GetPrivkeyFromExtkey(reqJson2).privkey;
    return priv;
}

function GetAddressFromPubkey(pubkey: string) {
    let data: cfdjs.CreateAddressKeyData = {
        hex: pubkey,
        type: "pubkey",
    };
    let reqJson: cfdjs.CreateAddressRequest = {
        isElements: false,
        keyData: data,
        network: "regtest",
        hashType: "p2wpkh",
    };

    return cfdjs.CreateAddress(reqJson).address;
}


function CreateDlcTxs(input: models.DlcTestVectors.Inputs): models.DlcTestVectors.DlcTransactions {
    let oraclePubKey = GetPubFromPriv(input.oracleKey);
    let localFundPrivkey = GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 0);
    let localSweepPrivkey = GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 1);
    let localFinalPrivkey = GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 2);
    let remoteFundPrivkey = GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 0);
    let remoteSweepPrivkey = GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 1);
    let remoteFinalPrivkey = GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 2);
    let localFundPubkey = GetPubFromPriv(localFundPrivkey);
    let localSweepPubkey = GetPubFromPriv(localSweepPrivkey);
    let localFinalPubkey = GetPubFromPriv(localFinalPrivkey);
    let remoteFundPubkey = GetPubFromPriv(remoteFundPrivkey);
    let remoteSweepPubkey = GetPubFromPriv(remoteSweepPrivkey);
    let remoteFinalPubkey = GetPubFromPriv(remoteFinalPrivkey);
    let remoteFinalAddress = GetAddressFromPubkey(remoteFinalPubkey);
    let localFinalAddress = GetAddressFromPubkey(localFinalPubkey);

    const reqJson: cfddlcjs.CreateDlcTransactionsRequest = {
        outcomes: [
            {
                local: BigInt(input.localPayouts.WIN),
                remote: BigInt(input.localPayouts.LOSE),
                messages: ["WIN"],
            },
            {
                local: BigInt(input.localPayouts.LOSE),
                remote: BigInt(input.localPayouts.WIN),
                messages: ["LOSE"]
            }
        ],
        oracleRPoints: [input.oracleRValue],
        oraclePubkey: oraclePubKey,
        localFundPubkey: localFundPubkey,
        remoteFundPubkey: remoteFundPubkey,
        localSweepPubkey: localSweepPubkey,
        remoteSweepPubkey: remoteSweepPubkey,
        localInputAmount: BigInt(input.localFundingUtxos.reduce((total, cur) => {
            return total + cur.output.value;
        }, 0)),
        localCollateralAmount: BigInt(input.localInput),
        remoteInputAmount: BigInt(input.remoteFundingUtxos.reduce((total, cur) => {
            return total + cur.output.value;
        }, 0)),
        remoteCollateralAmount: BigInt(input.remoteInput),
        timeout: input.penaltyTimeout,
        localInputs: input.localFundingUtxos.map(value =>
            ({
                txid: value.outPoint.txid,
                vout: value.outPoint.vout,
            })
        ),
        localChangeAddress: input.localChangeSPK,
        remoteInputs: input.remoteFundingUtxos.map(value =>
            ({
                txid: value.outPoint.txid,
                vout: value.outPoint.vout,
            })
        ),
        remoteChangeAddress: input.remoteChangeSPK,
        maturityTime: BigInt(1579072156),
        feeRate: input.feeRate,
        localFinalAddress: localFinalAddress,
        remoteFinalAddress: remoteFinalAddress,

    };

    return cfddlcjs.CreateDlcTransactions(reqJson) as models.DlcTestVectors.DlcTransactions;
}

function ParseRawTransaction(rawTransaction: string) {
    const reqJson = {
        hex: rawTransaction,
        network: "testnet",
        iswitness: true,
    };
    return cfdjs.DecodeRawTransaction(reqJson);
}

function SignFundTransactionInput(transaction: string, utxo: models.DlcTestVectors.Utxo) {
    const reqJson = {
        fundTxHex: transaction,
        privkey: utxo.keys[0],
        prevTxid: utxo.outPoint.txid,
        prevTxVout: utxo.outPoint.vout,
        amount: BigInt(utxo.output.value),
    }

    return cfddlcjs.SignFundTransaction(reqJson).hex;
}

function SignFundTransactionInputs(transaction: string, input: models.DlcTestVectors.Inputs) {
    for (let utxo of input.localFundingUtxos) {
        transaction = SignFundTransactionInput(transaction, utxo);
    }

    for (let utxo of input.remoteFundingUtxos) {
        transaction = SignFundTransactionInput(transaction, utxo);
    }

    return transaction;
}

function GetRefundTxSignature(transaction: string, privkey: string, fundTxId: string,
    localFundPubkey: string, remoteFundPubkey: string, fundAmount: number) {
    const reqJson = {
        refundTxHex: transaction,
        privkey: privkey,
        fundTxId: fundTxId,
        fundTxVout: 0,
        localFundPubkey: localFundPubkey,
        remoteFundPubkey: remoteFundPubkey,
        fundAmount: BigInt(fundAmount),
    };

    return cfddlcjs.GetRawRefundTxSignature(reqJson).hex;
}

function SignRefundTx(transaction: string, rawFundTransaction: string, input: models.DlcTestVectors.Inputs) {
    let fundTx = ParseRawTransaction(rawFundTransaction);
    let localFundPrivkey = GetPrivKeyFromExtPriv(input.localExtPrivKey);
    let remoteFundPrivkey = GetPrivKeyFromExtPriv(input.remoteExtPrivKey);
    let localFundPubkey = GetPubFromPriv(localFundPrivkey);
    let remoteFundPubkey = GetPubFromPriv(remoteFundPrivkey);
    let localSignature = GetRefundTxSignature(transaction, localFundPrivkey,
        fundTx.txid, localFundPubkey, remoteFundPubkey, fundTx.vout[0].value);
    let remoteSignature = GetRefundTxSignature(transaction, remoteFundPrivkey,
        fundTx.txid, localFundPubkey, remoteFundPubkey, fundTx.vout[0].value);
    let reqJson = {
        refundTxHex: transaction,
        signatures: [localSignature, remoteSignature],
        fundTxId: fundTx.txid,
        fundTxVout: 0,
        localFundPubkey: localFundPubkey,
        remoteFundPubkey: remoteFundPubkey,
    }

    let response = cfddlcjs.AddSignaturesToRefundTx(reqJson);
    return response.hex;
}

function GetCetSignature(transaction: string, privkey: string, fundTxId: string,
    localFundPubkey: string, remoteFundPubkey: string, fundAmount: number) {
    const reqJson = {
        cetHex: transaction,
        privkey: privkey,
        fundTxId: fundTxId,
        fundTxVout: 0,
        localFundPubkey: localFundPubkey,
        remoteFundPubkey: remoteFundPubkey,
        fundAmount: BigInt(fundAmount),
    };

    return cfddlcjs.GetRawCetSignature(reqJson).hex;
}

function SignCet(transaction: string, rawFundTransaction: string, input: models.DlcTestVectors.Inputs) {
    let fundTx = ParseRawTransaction(rawFundTransaction);
    let localFundPubkey = GetPubkeyFromExtPriv(input.localExtPrivKey);
    let remoteFundPubkey = GetPubkeyFromExtPriv(input.remoteExtPrivKey);
    let localSignature = GetCetSignature(transaction, GetPrivKeyFromExtPriv(input.localExtPrivKey),
        fundTx.txid, localFundPubkey, remoteFundPubkey, fundTx.vout[0].value);
    let remoteSignature = GetCetSignature(transaction, GetPrivKeyFromExtPriv(input.remoteExtPrivKey),
        fundTx.txid, localFundPubkey, remoteFundPubkey, fundTx.vout[0].value);
    let reqJson = {
        cetHex: transaction,
        signatures: [localSignature, remoteSignature],
        fundTxId: fundTx.txid,
        fundTxVout: 0,
        localFundPubkey: localFundPubkey,
        remoteFundPubkey: remoteFundPubkey,
    }

    let response = cfddlcjs.AddSignaturesToCet(reqJson);
    return response.hex;
}

function CreateAndSignClosingTx(rawCet: string, input: models.DlcTestVectors.Inputs) {
    let cet = ParseRawTransaction(rawCet);
    let oraclePubKey = GetPubFromPriv(input.oracleKey);
    let localFundPrivkey = GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 0);
    let localSweepPrivkey = GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 1);
    let localFinalPrivkey = GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 2);
    let remoteFundPrivkey = GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 0);
    let remoteSweepPrivkey = GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 1);
    let remoteFinalPrivkey = GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 2);
    let localFundPubkey = GetPubFromPriv(localFundPrivkey);
    let localSweepPubkey = GetPubFromPriv(localSweepPrivkey);
    let localFinalPubkey = GetPubFromPriv(localFinalPrivkey);
    let remoteFundPubkey = GetPubFromPriv(remoteFundPrivkey);
    let remoteSweepPubkey = GetPubFromPriv(remoteSweepPrivkey);
    let remoteFinalPubkey = GetPubFromPriv(remoteFinalPrivkey);
    let remoteFinalAddress = GetAddressFromPubkey(remoteFinalPubkey);
    let localFinalAddress = GetAddressFromPubkey(localFinalPubkey);
    let remoteExtPubkey = GetExtPubFromExtPriv(input.remoteExtPrivKey);
    let oraclePubkey = GetPubFromPriv(input.oracleKey);
    let reqJson = {
        amount: BigInt(cet.vout[0].value - 122),
        cetTxid: cet.txid,
        cetVout: 0,
        address: localFinalAddress,
    }

    let rawClosingTx = cfddlcjs.CreateClosingTransaction(reqJson).hex;

    let reqJson2: cfddlcjs.SignClosingTransactionRequest = {
        closingTxHex: rawClosingTx,
        localFundPrivkey: localFundPrivkey,
        localSweepPubkey: localSweepPubkey,
        remoteSweepPubkey: remoteSweepPubkey,
        oraclePubkey: oraclePubkey,
        oracleRPoints: [input.oracleRValue],
        messages: ["WIN"],
        delay: BigInt(input.penaltyTimeout),
        oracleSig: input.oracleSig,
        cetTxid: cet.txid,
        cetVout: 0,
        amount: BigInt(cet.vout[0].value),
        cetScript: "",
    }

    return cfddlcjs.SignClosingTransaction(reqJson2).hex;
}


function SaveTransactionToFile(raw: string, fileName: string) {
    let res = ParseRawTransaction(raw);
    fs.writeFileSync("./" + fileName, JSON.stringify(res, null, '  '));
}

let firstVector = testVectors[0];

let txs = CreateDlcTxs(firstVector.inputs);
let fundTx = SignFundTransactionInputs(txs.fundTxHex, firstVector.inputs);
let refundTx = SignRefundTx(txs.refundTxHex, fundTx, firstVector.inputs);
let cets = txs.closingCetsHex.map((cet) => SignCet(cet, fundTx, firstVector.inputs));
let closingTx = CreateAndSignClosingTx(cets[0], firstVector.inputs);

SaveTransactionToFile(fundTx, "actualFund.json");
SaveTransactionToFile(refundTx, "actualRefund.json");
cets.forEach((cet, i) => SaveTransactionToFile(cet, `actualCet${i}.json`));

SaveTransactionToFile(firstVector.outputs.fundingTx, "expectedFund.json");
SaveTransactionToFile(firstVector.outputs.refundTx, "expectedRefund.json");
firstVector.outputs.localCets.forEach((cet, i) => SaveTransactionToFile(cet, `expectedCet${i}.json`));

SaveTransactionToFile(closingTx, "actualClosingTx.json");
SaveTransactionToFile(firstVector.outputs.localClosingTx, "expectedClosingTx.json");