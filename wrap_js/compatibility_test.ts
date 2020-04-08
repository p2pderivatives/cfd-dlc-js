import * as cfddlcjs from '../index.js';
import * as cfdjs from 'cfd-js';
import * as models from "./models";
import { CfdUtils } from "./cfd_utils";

import * as fs from 'fs';
import testVectors from './compatibility_input.json';


function CreateDlcTxs(input: models.DlcTestVectors.Inputs): models.DlcTestVectors.DlcTransactions {
    let oraclePubKey = CfdUtils.GetPubFromPriv(input.oracleKey);
    let localFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 0);
    let localSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 1);
    let localFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 2);
    let remoteFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 0);
    let remoteSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 1);
    let remoteFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 2);
    let localFundPubkey = CfdUtils.GetPubFromPriv(localFundPrivkey);
    let localSweepPubkey = CfdUtils.GetPubFromPriv(localSweepPrivkey);
    let localFinalPubkey = CfdUtils.GetPubFromPriv(localFinalPrivkey);
    let remoteFundPubkey = CfdUtils.GetPubFromPriv(remoteFundPrivkey);
    let remoteSweepPubkey = CfdUtils.GetPubFromPriv(remoteSweepPrivkey);
    let remoteFinalPubkey = CfdUtils.GetPubFromPriv(remoteFinalPrivkey);
    let remoteFinalAddress = CfdUtils.GetAddressFromPubkey(remoteFinalPubkey);
    let localFinalAddress = CfdUtils.GetAddressFromPubkey(localFinalPubkey);

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

function GetRawFundTransactionInputSignature(transaction: string, utxo: models.DlcTestVectors.Utxo) {
    const reqJson: cfddlcjs.GetRawFundTxSignatureRequest = {
        fundTxHex: transaction,
        privkey: utxo.keys[0],
        prevTxId: utxo.outPoint.txid,
        prevTxVout: utxo.outPoint.vout,
        amount: BigInt(utxo.output.value),
    }

    return cfddlcjs.GetRawFundTxSignature(reqJson).hex;
}

function VerifyFundTransactionInputSignature(transaction: string,
    utxo: models.DlcTestVectors.Utxo, signature: string) {
    const reqJson: cfddlcjs.VerifyFundTxSignatureRequest = {
        fundTxHex: transaction,
        signature: signature,
        pubkey: CfdUtils.GetPubFromPriv(utxo.keys[0]),
        prevTxId: utxo.outPoint.txid,
        prevTxVout: utxo.outPoint.vout,
        inputAmount: BigInt(utxo.output.value),
    };

    return cfddlcjs.VerifyFundTxSignature(reqJson).valid;
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
        let sig = GetRawFundTransactionInputSignature(transaction, utxo);
        let isValid = VerifyFundTransactionInputSignature(transaction, utxo, sig);
        console.log(`IsValid: ${isValid}`);
        console.log(sig);
        let der = EncodeSignatureToDER(sig);
        console.log(der);
    }

    for (let utxo of input.remoteFundingUtxos) {
        transaction = SignFundTransactionInput(transaction, utxo);
        let sig = GetRawFundTransactionInputSignature(transaction, utxo);
        let isValid = VerifyFundTransactionInputSignature(transaction, utxo, sig);
        console.log(`IsValid: ${isValid}`);
        let der = EncodeSignatureToDER(sig);
        console.log(der);
    }

    return transaction;
}

function GetRefundTxSignature(transaction: string, privkey: string, fundTxId: string,
    localFundPubkey: string, remoteFundPubkey: string, fundAmount: BigInt) {
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

function EncodeSignatureToDER(signature: string) {
    const reqJson: cfdjs.EncodeSignatureByDerRequest = {
        signature: signature,
        sighashType: "all",
        sighashAnyoneCanPay: false,
    };

    return cfdjs.EncodeSignatureByDer(reqJson).signature;
}

function SignRefundTx(transaction: string, rawFundTransaction: string, input: models.DlcTestVectors.Inputs) {
    let fundTx = ParseRawTransaction(rawFundTransaction);
    let localFundPrivkey = CfdUtils.GetPrivKeyFromExtPriv(input.localExtPrivKey);
    let remoteFundPrivkey = CfdUtils.GetPrivKeyFromExtPriv(input.remoteExtPrivKey);
    let localFundPubkey = CfdUtils.GetPubFromPriv(localFundPrivkey);
    let remoteFundPubkey = CfdUtils.GetPubFromPriv(remoteFundPrivkey);
    let localSignature = GetRefundTxSignature(transaction, localFundPrivkey,
        fundTx.txid, localFundPubkey, remoteFundPubkey, BigInt(fundTx.vout[0].value));
    let remoteSignature = GetRefundTxSignature(transaction, remoteFundPrivkey,
        fundTx.txid, localFundPubkey, remoteFundPubkey, BigInt(fundTx.vout[0].value));
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
    localFundPubkey: string, remoteFundPubkey: string, fundAmount: BigInt) {
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
    let localFundPubkey = CfdUtils.GetPubkeyFromExtPriv(input.localExtPrivKey);
    let remoteFundPubkey = CfdUtils.GetPubkeyFromExtPriv(input.remoteExtPrivKey);
    let localSignature = GetCetSignature(transaction, CfdUtils.GetPrivKeyFromExtPriv(input.localExtPrivKey),
        fundTx.txid, localFundPubkey, remoteFundPubkey, BigInt(fundTx.vout[0].value));
    let remoteSignature = GetCetSignature(transaction, CfdUtils.GetPrivKeyFromExtPriv(input.remoteExtPrivKey),
        fundTx.txid, localFundPubkey, remoteFundPubkey, BigInt(fundTx.vout[0].value));
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
    let oraclePubKey = CfdUtils.GetPubFromPriv(input.oracleKey);
    let localFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 0);
    let localSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 1);
    let localFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.localExtPrivKey, 2);
    let remoteFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 0);
    let remoteSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 1);
    let remoteFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(input.remoteExtPrivKey, 2);
    let localFundPubkey = CfdUtils.GetPubFromPriv(localFundPrivkey);
    let localSweepPubkey = CfdUtils.GetPubFromPriv(localSweepPrivkey);
    let localFinalPubkey = CfdUtils.GetPubFromPriv(localFinalPrivkey);
    let remoteFundPubkey = CfdUtils.GetPubFromPriv(remoteFundPrivkey);
    let remoteSweepPubkey = CfdUtils.GetPubFromPriv(remoteSweepPrivkey);
    let remoteFinalPubkey = CfdUtils.GetPubFromPriv(remoteFinalPrivkey);
    let remoteFinalAddress = CfdUtils.GetAddressFromPubkey(remoteFinalPubkey);
    let localFinalAddress = CfdUtils.GetAddressFromPubkey(localFinalPubkey);
    let remoteExtPubkey = CfdUtils.GetExtPubFromExtPriv(input.remoteExtPrivKey);
    let oraclePubkey = CfdUtils.GetPubFromPriv(input.oracleKey);
    let reqJson = {
        amount: BigInt(cet.vout[0].value) - BigInt(122),
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
        oracleSigs: [input.oracleSig],
        cetTxid: cet.txid,
        cetVout: 0,
        amount: BigInt(cet.vout[0].value),
        cetScript: "",
    }

    return cfddlcjs.SignClosingTransaction(reqJson2).hex;
}

// function DecodeDerSignatureToRaw(der: string) {
//     const reqJson: cfdjs.DecodeDerSignatureToRawRequest = {
//         signature: der,
//     };

//     return cfdjs.DecodeDerSignatureToRaw(reqJson).signature;
// }

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
let rawSig = "ca158648dff9c55dc6ff0c7c387cb5313759faf424e775698f0837190591a8924a6ad245366f88b4952a16e4726d293ada1c78b73ac2b3e9e492a68cc63468da";
let isValidSig = VerifyFundTransactionInputSignature(fundTx, firstVector.inputs.localFundingUtxos[0], rawSig);
console.log(`IsValid: ${isValidSig}`);