import * as cfddlcjs from "../index.js";
import * as CfdUtils from "./cfd_utils";

function MessagesToMessagesList(input: string[][]): cfddlcjs.Messages[] {
  return input.map((x) => {
    return {
      messages: x,
    };
  });
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
  adaptorSignature: string,
  prv: string,
  oracleSignatures: string[],
  localFundPubkey: string,
  remoteFundPubkey: string
): string {
  const reqJson: cfddlcjs.SignCetRequest = {
    cetHex: transaction,
    fundPrivkey: prv,
    fundTxId,
    fundVout: 0,
    fundInputAmount,
    localFundPubkey,
    remoteFundPubkey,
    oracleSignatures,
    adaptorSignature,
  };

  return cfddlcjs.SignCet(reqJson).hex;
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

  const pubkey1 = CfdUtils.GetPubkeyFromPrivkey(prv1);
  const pubkey2 = CfdUtils.GetPubkeyFromPrivkey(prv2);

  const signatures = pubkey1 < pubkey2 ? [sig1, sig2] : [sig2, sig1];

  const addSigReq: cfddlcjs.AddSignaturesToRefundTxRequest = {
    refundTxHex: transaction,
    signatures,
    fundTxId,
    localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(prv2),
  };

  return cfddlcjs.AddSignaturesToRefundTx(addSigReq).hex;
}

export function CreateCetAdaptorSignatures(
  cets: string[],
  privkey: string,
  oraclePubkey: string,
  oracleRValues: string[],
  messages: string[][],
  fundTxId: string,
  fundVout: number,
  fundInputAmount: number,
  localFundPubkey: string,
  remoteFundPubkey: string
) {
  const req: cfddlcjs.CreateCetAdaptorSignaturesRequest = {
    cetsHex: cets,
    privkey,
    fundTxId,
    fundVout,
    localFundPubkey,
    remoteFundPubkey,
    oraclePubkey,
    oracleRValues,
    messagesList: MessagesToMessagesList(messages),
    fundInputAmount,
  };

  return cfddlcjs.CreateCetAdaptorSignatures(req).adaptorPairs;
}

export function VerifyAdaptorSignatures(
  cets: string[],
  adaptorPairs: cfddlcjs.AdaptorPair[],
  messages: string[][],
  oraclePubkey: string,
  oracleRValues: string[],
  localFundPubkey: string,
  remoteFundPubkey: string,
  fundTxId: string,
  fundInputAmount: number,
  verifyRemote: boolean
) {
  const req: cfddlcjs.VerifyCetAdaptorSignaturesRequest = {
    cetsHex: cets,
    adaptorPairs,
    messagesList: MessagesToMessagesList(messages),
    localFundPubkey,
    remoteFundPubkey,
    oraclePubkey,
    oracleRValues,
    fundTxId,
    fundInputAmount,
    verifyRemote,
  };

  return cfddlcjs.VerifyCetAdaptorSignatures(req).valid;
}
