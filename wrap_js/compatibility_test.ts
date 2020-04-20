import * as cfddlcjs from "../index.js";
import * as cfdjs from "cfd-js";
import * as models from "./models";
import * as CfdUtils from "./cfd_utils";
import * as CfdDlcUtils from "./cfddlc_utils";
import * as fs from "fs";
import testVectors from "./compatibility_input.json";

function CreateDlcTxs(
  input: models.DlcTestVectors.Inputs
): models.DlcTestVectors.DlcTransactions {
  const oraclePubKey = CfdUtils.GetPubkeyFromPrivkey(input.oracleKey);
  const localFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.localExtPrivKey,
    0
  );
  const localSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.localExtPrivKey,
    1
  );
  const localFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.localExtPrivKey,
    2
  );
  const remoteFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.remoteExtPrivKey,
    0
  );
  const remoteSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.remoteExtPrivKey,
    1
  );
  const remoteFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.remoteExtPrivKey,
    2
  );
  const localFundPubkey = CfdUtils.GetPubkeyFromPrivkey(localFundPrivkey);
  const localSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(localSweepPrivkey);
  const localFinalPubkey = CfdUtils.GetPubkeyFromPrivkey(localFinalPrivkey);
  const remoteFundPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteFundPrivkey);
  const remoteSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteSweepPrivkey);
  const remoteFinalPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteFinalPrivkey);
  const remoteFinalAddress = CfdUtils.GetAddressFromPubkey(remoteFinalPubkey);
  const localFinalAddress = CfdUtils.GetAddressFromPubkey(localFinalPubkey);

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
        messages: ["LOSE"],
      },
    ],
    oracleRPoints: [input.oracleRValue],
    oraclePubkey: oraclePubKey,
    localFundPubkey,
    remoteFundPubkey,
    localSweepPubkey,
    remoteSweepPubkey,
    localInputAmount: BigInt(
      input.localFundingUtxos.reduce((total, cur) => {
        return total + cur.output.value;
      }, 0)
    ),
    localCollateralAmount: BigInt(input.localInput),
    remoteInputAmount: BigInt(
      input.remoteFundingUtxos.reduce((total, cur) => {
        return total + cur.output.value;
      }, 0)
    ),
    remoteCollateralAmount: BigInt(input.remoteInput),
    timeout: input.penaltyTimeout,
    localInputs: input.localFundingUtxos.map((value) => ({
      txid: value.outPoint.txid,
      vout: value.outPoint.vout,
    })),
    localChangeAddress: input.localChangeSPK,
    remoteInputs: input.remoteFundingUtxos.map((value) => ({
      txid: value.outPoint.txid,
      vout: value.outPoint.vout,
    })),
    remoteChangeAddress: input.remoteChangeSPK,
    maturityTime: BigInt(1579072156),
    feeRate: input.feeRate,
    localFinalAddress,
    remoteFinalAddress,
  };

  const a = cfddlcjs.CreateDlcTransactions(
    reqJson
  ) as models.DlcTestVectors.DlcTransactions;
  const fundTx = CfdUtils.DecodeRawTransaction(a.fundTxHex);

  const mut = CfdDlcUtils.CreateMutualClosingTx(
    localFinalAddress,
    remoteFinalAddress,
    BigInt(input.localPayouts.WIN),
    BigInt(input.localPayouts.LOSE),
    fundTx.txid
  );

  console.log(mut);

  return a;
}

function VerifyFundTransactionInputSignature(
  transaction: string,
  utxo: models.DlcTestVectors.Utxo,
  signature: string
) {
  const reqJson: cfddlcjs.VerifyFundTxSignatureRequest = {
    fundTxHex: transaction,
    signature,
    pubkey: CfdUtils.GetPubkeyFromPrivkey(utxo.keys[0]),
    prevTxId: utxo.outPoint.txid,
    prevTxVout: utxo.outPoint.vout,
    fundInputAmount: BigInt(utxo.output.value),
  };

  return cfddlcjs.VerifyFundTxSignature(reqJson).valid;
}

function SignFundTransactionInput(
  transaction: string,
  utxo: models.DlcTestVectors.Utxo
) {
  const reqJson = {
    fundTxHex: transaction,
    privkey: utxo.keys[0],
    prevTxid: utxo.outPoint.txid,
    prevTxVout: utxo.outPoint.vout,
    amount: BigInt(utxo.output.value),
  };

  return cfddlcjs.SignFundTransaction(reqJson).hex;
}

function SignFundTransactionInputs(
  transaction: string,
  input: models.DlcTestVectors.Inputs
) {
  for (const utxo of input.localFundingUtxos) {
    transaction = SignFundTransactionInput(transaction, utxo);
  }

  for (const utxo of input.remoteFundingUtxos) {
    transaction = SignFundTransactionInput(transaction, utxo);
  }

  return transaction;
}

function GetRefundTxSignature(
  transaction: string,
  privkey: string,
  fundTxId: string,
  localFundPubkey: string,
  remoteFundPubkey: string,
  fundInputAmount: BigInt
) {
  const reqJson = {
    refundTxHex: transaction,
    privkey,
    fundTxId,
    fundTxVout: 0,
    localFundPubkey,
    remoteFundPubkey,
    fundInputAmount: BigInt(fundInputAmount),
  };

  return cfddlcjs.GetRawRefundTxSignature(reqJson).hex;
}

function EncodeSignatureToDER(signature: string) {
  const reqJson: cfdjs.EncodeSignatureByDerRequest = {
    signature,
    sighashType: "all",
    sighashAnyoneCanPay: false,
  };

  return cfdjs.EncodeSignatureByDer(reqJson).signature;
}

function SignRefundTx(
  transaction: string,
  rawFundTransaction: string,
  input: models.DlcTestVectors.Inputs
) {
  const fundTx = CfdUtils.DecodeRawTransaction(rawFundTransaction);
  const localFundPrivkey = CfdUtils.GetPrivKeyFromExtPriv(
    input.localExtPrivKey
  );
  const remoteFundPrivkey = CfdUtils.GetPrivKeyFromExtPriv(
    input.remoteExtPrivKey
  );
  const localFundPubkey = CfdUtils.GetPubkeyFromPrivkey(localFundPrivkey);
  const remoteFundPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteFundPrivkey);
  const localSignature = GetRefundTxSignature(
    transaction,
    localFundPrivkey,
    fundTx.txid,
    localFundPubkey,
    remoteFundPubkey,
    BigInt(fundTx.vout[0].value)
  );
  const remoteSignature = GetRefundTxSignature(
    transaction,
    remoteFundPrivkey,
    fundTx.txid,
    localFundPubkey,
    remoteFundPubkey,
    BigInt(fundTx.vout[0].value)
  );
  const reqJson = {
    refundTxHex: transaction,
    signatures: [localSignature, remoteSignature],
    fundTxId: fundTx.txid,
    fundTxVout: 0,
    localFundPubkey,
    remoteFundPubkey,
  };

  const response = cfddlcjs.AddSignaturesToRefundTx(reqJson);
  return response.hex;
}

function GetCetSignature(
  transaction: string,
  privkey: string,
  fundTxId: string,
  localFundPubkey: string,
  remoteFundPubkey: string,
  fundInputAmount: BigInt
) {
  const reqJson = {
    cetHex: transaction,
    privkey,
    fundTxId,
    fundTxVout: 0,
    localFundPubkey,
    remoteFundPubkey,
    fundInputAmount: BigInt(fundInputAmount),
  };

  return cfddlcjs.GetRawCetSignature(reqJson).hex;
}

function SignCet(
  transaction: string,
  rawFundTransaction: string,
  input: models.DlcTestVectors.Inputs
) {
  const fundTx = CfdUtils.DecodeRawTransaction(rawFundTransaction);
  const localFundPubkey = CfdUtils.GetPubkeyFromExtPriv(input.localExtPrivKey);
  const remoteFundPubkey = CfdUtils.GetPubkeyFromExtPriv(
    input.remoteExtPrivKey
  );
  const localSignature = GetCetSignature(
    transaction,
    CfdUtils.GetPrivKeyFromExtPriv(input.localExtPrivKey),
    fundTx.txid,
    localFundPubkey,
    remoteFundPubkey,
    BigInt(fundTx.vout[0].value)
  );
  const remoteSignature = GetCetSignature(
    transaction,
    CfdUtils.GetPrivKeyFromExtPriv(input.remoteExtPrivKey),
    fundTx.txid,
    localFundPubkey,
    remoteFundPubkey,
    BigInt(fundTx.vout[0].value)
  );
  const reqJson = {
    cetHex: transaction,
    signatures: [localSignature, remoteSignature],
    fundTxId: fundTx.txid,
    fundTxVout: 0,
    localFundPubkey,
    remoteFundPubkey,
  };

  const response = cfddlcjs.AddSignaturesToCet(reqJson);
  return response.hex;
}

function CreateAndSignClosingTx(
  rawCet: string,
  input: models.DlcTestVectors.Inputs
) {
  const cet = CfdUtils.DecodeRawTransaction(rawCet);
  const oraclePubKey = CfdUtils.GetPubkeyFromPrivkey(input.oracleKey);
  const localFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.localExtPrivKey,
    0
  );
  const localSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.localExtPrivKey,
    1
  );
  const localFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.localExtPrivKey,
    2
  );
  const remoteFundPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.remoteExtPrivKey,
    0
  );
  const remoteSweepPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.remoteExtPrivKey,
    1
  );
  const remoteFinalPrivkey = CfdUtils.GetChildPrivKeyFromExtPriv(
    input.remoteExtPrivKey,
    2
  );
  const localFundPubkey = CfdUtils.GetPubkeyFromPrivkey(localFundPrivkey);
  const localSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(localSweepPrivkey);
  const localFinalPubkey = CfdUtils.GetPubkeyFromPrivkey(localFinalPrivkey);
  const remoteFundPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteFundPrivkey);
  const remoteSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteSweepPrivkey);
  const remoteFinalPubkey = CfdUtils.GetPubkeyFromPrivkey(remoteFinalPrivkey);
  const remoteFinalAddress = CfdUtils.GetAddressFromPubkey(remoteFinalPubkey);
  const localFinalAddress = CfdUtils.GetAddressFromPubkey(localFinalPubkey);
  const remoteExtPubkey = CfdUtils.GetExtPubFromExtPriv(input.remoteExtPrivKey);
  const oraclePubkey = CfdUtils.GetPubkeyFromPrivkey(input.oracleKey);
  const reqJson = {
    amount: BigInt(cet.vout[0].value) - BigInt(122),
    cetTxid: cet.txid,
    cetVout: 0,
    address: localFinalAddress,
  };

  const rawClosingTx = cfddlcjs.CreateClosingTransaction(reqJson).hex;

  const reqJson2: cfddlcjs.SignClosingTransactionRequest = {
    closingTxHex: rawClosingTx,
    localFundPrivkey,
    localSweepPubkey,
    remoteSweepPubkey,
    oraclePubkey,
    oracleRPoints: [input.oracleRValue],
    messages: ["WIN"],
    delay: BigInt(input.penaltyTimeout),
    oracleSigs: [input.oracleSig],
    cetTxid: cet.txid,
    cetVout: 0,
    amount: BigInt(cet.vout[0].value),
  };

  return cfddlcjs.SignClosingTransaction(reqJson2).hex;
}

function SaveTransactionToFile(raw: string, fileName: string) {
  const res = CfdUtils.DecodeRawTransaction(raw);
  fs.writeFileSync("./" + fileName, JSON.stringify(res, null, "  "));
}

const firstVector = testVectors[0];

const txs = CreateDlcTxs(firstVector.inputs);
const fundTx = SignFundTransactionInputs(txs.fundTxHex, firstVector.inputs);
const refundTx = SignRefundTx(txs.refundTxHex, fundTx, firstVector.inputs);
const cets = txs.closingCetsHex.map((cet) =>
  SignCet(cet, fundTx, firstVector.inputs)
);
const closingTx = CreateAndSignClosingTx(cets[0], firstVector.inputs);

SaveTransactionToFile(fundTx, "actualFund.json");
SaveTransactionToFile(refundTx, "actualRefund.json");
cets.forEach((cet, i) => SaveTransactionToFile(cet, `actualCet${i}.json`));

SaveTransactionToFile(firstVector.outputs.fundingTx, "expectedFund.json");
SaveTransactionToFile(firstVector.outputs.refundTx, "expectedRefund.json");
firstVector.outputs.localCets.forEach((cet, i) =>
  SaveTransactionToFile(cet, `expectedCet${i}.json`)
);

SaveTransactionToFile(closingTx, "actualClosingTx.json");
SaveTransactionToFile(
  firstVector.outputs.localClosingTx,
  "expectedClosingTx.json"
);
const rawSig =
  "ca158648dff9c55dc6ff0c7c387cb5313759faf424e775698f0837190591a8924a6ad245366f88b4952a16e4726d293ada1c78b73ac2b3e9e492a68cc63468da";
const isValidSig = VerifyFundTransactionInputSignature(
  fundTx,
  firstVector.inputs.localFundingUtxos[0],
  rawSig
);
