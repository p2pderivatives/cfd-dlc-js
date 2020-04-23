import * as cfddlcjs from "../index.js";
import * as CfdUtils from "./cfd_utils";

export function GetSchnorrPublicNonce(kValue: string) {
  const reqJson: cfddlcjs.GetSchnorrPublicNonceRequest = {
    kValue,
  };

  return cfddlcjs.GetSchnorrPublicNonce(reqJson).hex;
}

export function SchnorrSign(
  message: string,
  oraclePrivkey: string,
  oracleKValue: string
) {
  const reqJson: cfddlcjs.SchnorrSignRequest = {
    message,
    privkey: oraclePrivkey,
    kValue: oracleKValue,
  };

  return cfddlcjs.SchnorrSign(reqJson).hex;
}

export function SignFundTransactionInput(
  transaction: string,
  input: any,
  prv: any
) {
  const reqJson = {
    fundTxHex: transaction,
    privkey: prv,
    prevTxId: input.txid,
    prevVout: input.vout,
    amount: input.amount,
  };

  return cfddlcjs.SignFundTransaction(reqJson).hex;
}

export function SignCet(
  transaction: string,
  fundTxId: string,
  fundInputAmount: number,
  prv1: string,
  prv2: string
) {
  const reqJson: cfddlcjs.GetRawCetSignatureRequest = {
    cetHex: transaction,
    privkey: prv1,
    fundTxId,
    fundVout: 0,
    fundInputAmount,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  const sig1 = cfddlcjs.GetRawCetSignature(reqJson).hex;
  reqJson.privkey = prv2;
  const sig2 = cfddlcjs.GetRawCetSignature(reqJson).hex;

  const addSigReq: cfddlcjs.AddSignaturesToCetRequest = {
    cetHex: transaction,
    signatures: [sig1, sig2],
    fundTxId,
    fundVout: 0,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  return cfddlcjs.AddSignaturesToCet(addSigReq).hex;
}

export function CreateClosingTx(
  finalAddress: string,
  amount: number,
  cetTxId: string,
  cetVout: number
) {
  const reqJson: cfddlcjs.CreateClosingTransactionRequest = {
    address: finalAddress,
    amount,
    cetTxId,
    cetVout,
  };

  return cfddlcjs.CreateClosingTransaction(reqJson).hex;
}

export function SignClosingTx(
  transaction: string,
  localFundPrivkey: string,
  localSweepPubkey: string,
  remoteSweepPubkey: string,
  oraclePubkey: string,
  oracleRPoints: string[],
  messages: string[],
  oracleSigs: string[],
  delay: number,
  cetId: string,
  amount: number
) {
  const reqJson: cfddlcjs.SignClosingTransactionRequest = {
    closingTxHex: transaction,
    localFundPrivkey,
    localSweepPubkey,
    remoteSweepPubkey,
    oraclePubkey,
    oracleRPoints,
    messages,
    oracleSigs,
    delay,
    cetTxId: cetId,
    cetVout: 0,
    amount,
  };

  return cfddlcjs.SignClosingTransaction(reqJson).hex;
}

export function SignRefundTransaction(
  transaction: string,
  fundTxId: string,
  fundInputAmount: number,
  prv1: string,
  prv2: string
) {
  let reqJson: cfddlcjs.GetRawRefundTxSignatureRequest = {
    refundTxHex: transaction,
    privkey: prv1,
    fundTxId,
    fundVout: 0,
    fundInputAmount,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  const sig1 = cfddlcjs.GetRawRefundTxSignature(reqJson).hex;

  reqJson = {
    refundTxHex: transaction,
    privkey: prv2,
    fundTxId,
    fundVout: 0,
    fundInputAmount,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  const sig2 = cfddlcjs.GetRawRefundTxSignature(reqJson).hex;

  const addSigReq: cfddlcjs.AddSignaturesToRefundTxRequest = {
    refundTxHex: transaction,
    signatures: [sig1, sig2],
    fundTxId,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  return cfddlcjs.AddSignaturesToRefundTx(addSigReq).hex;
}

export function CreateMutualClosingTx(
  localFinalAddress: string,
  remoteFinalAddress: string,
  localAmount: number,
  remoteAmount: number,
  fundTxId: string
) {
  const reqJson: cfddlcjs.CreateMutualClosingTransactionRequest = {
    localFinalAddress,
    remoteFinalAddress,
    localAmount,
    remoteAmount,
    fundTxId,
    feeRate: 1,
  };

  return cfddlcjs.CreateMutualClosingTransaction(reqJson).hex;
}

export function SignMutualClosingTx(
  transaction: string,
  fundTxId: string,
  fundInputAmount: number,
  prv1: string,
  prv2: string
) {
  let reqJson: cfddlcjs.GetRawMutualClosingTxSignatureRequest = {
    mutualClosingHex: transaction,
    privkey: prv1,
    fundTxId,
    fundVout: 0,
    fundInputAmount,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  const sig1 = cfddlcjs.GetRawMutualClosingTxSignature(reqJson).hex;

  reqJson = {
    mutualClosingHex: transaction,
    privkey: prv2,
    fundTxId,
    fundInputAmount,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  const sig2 = cfddlcjs.GetRawMutualClosingTxSignature(reqJson).hex;

  const addSigReq: cfddlcjs.AddSignaturesToMutualClosingTxRequest = {
    mutualClosingTxHex: transaction,
    signatures: [sig1, sig2],
    fundTxId,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  return cfddlcjs.AddSignaturesToMutualClosingTx(addSigReq).hex;
}
