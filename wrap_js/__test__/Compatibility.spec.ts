import feeTestVector from "./data/dlc_fee_test.json";
import txTestVector from "./data/dlc_tx_test.json";
import scriptSamples from "./data/script_samples.json";
import * as cfddlcjs from "../../index.js";
import * as TestData from "./data/TestData";
import * as CfdUtils from "../cfd_utils";

function GetScriptForLength(length: number): string {
  return scriptSamples.find((x) => x.byteLen === length).script;
}

function GetInputAmount(rawtx: string, idx: number): number {
  const tx = CfdUtils.DecodeRawTransaction(rawtx);
  return Number(tx.vout[idx].value);
}

function GetTxidFromRawTransaction(rawtx: string): string {
  return CfdUtils.DecodeRawTransaction(rawtx).txid;
}

type InputInfo = {
  tx: string;
  idx: number;
  inputKeys: string[];
  redeemScript?: string;
  scriptWitness: string;
};

function GetTotalInputAmount(fundingInputTxs: InputInfo[]): number {
  return fundingInputTxs.reduce(
    (acc, cur) => acc + GetInputAmount(cur.tx, cur.idx),
    0
  );
}

describe("Compatibility", () => {
  test("tx test vectors", () => {
    for (const testVector of txTestVector) {
      const totalCollateral =
        testVector.inputs.offerParams.collateral +
        testVector.inputs.acceptParams.collateral;
      const req: cfddlcjs.CreateDlcTransactionsRequest = {
        payouts: testVector.inputs.params.contractInfo.map((x) => {
          return {
            local: x.localPayout,
            remote: totalCollateral - x.localPayout,
          };
        }),
        localFundPubkey: CfdUtils.GetPubkeyFromPrivkey(
          testVector.inputs.offerParams.fundingPrivKey
        ),
        remoteFundPubkey: CfdUtils.GetPubkeyFromPrivkey(
          testVector.inputs.acceptParams.fundingPrivKey
        ),
        localFinalScriptPubkey: CfdUtils.GetAddressScript(
          testVector.inputs.offerParams.payoutAddress
        ),
        remoteFinalScriptPubkey: CfdUtils.GetAddressScript(
          testVector.inputs.acceptParams.payoutAddress
        ),
        localInputAmount: GetTotalInputAmount(
          testVector.inputs.offerParams.fundingInputTxs
        ),
        remoteInputAmount: GetTotalInputAmount(
          testVector.inputs.acceptParams.fundingInputTxs
        ),
        localCollateralAmount: testVector.inputs.offerParams.collateral,
        remoteCollateralAmount: testVector.inputs.acceptParams.collateral,
        localChangeScriptPubkey: CfdUtils.GetAddressScript(
          testVector.inputs.offerParams.changeAddress
        ),
        remoteChangeScriptPubkey: CfdUtils.GetAddressScript(
          testVector.inputs.acceptParams.changeAddress
        ),
        cetLockTime: testVector.inputs.params.contractMaturityBound,
        refundLocktime: testVector.inputs.params.contractTimeout,
        localInputs: testVector.inputs.offerParams.fundingInputTxs.map((x) => {
          return {
            vout: x.idx,
            txid: CfdUtils.DecodeRawTransaction(x.tx).txid,
            maxWitnessLength: x.maxWitnessLen,
            redeemScript: x.redeemScript
              ? CfdUtils.ParseAsmScript(x.redeemScript)
              : undefined,
          };
        }),
        remoteInputs: testVector.inputs.acceptParams.fundingInputTxs.map(
          (x) => {
            return {
              vout: x.idx,
              txid: CfdUtils.DecodeRawTransaction(x.tx).txid,
              maxWitnessLength: x.maxWitnessLen,
              redeemScript: x.redeemScript
                ? CfdUtils.ParseAsmScript(x.redeemScript)
                : undefined,
            };
          }
        ),
        feeRate: testVector.inputs.params.feeRate,
      };
      const dlcTxs = cfddlcjs.CreateDlcTransactions(req);
      expect(dlcTxs.fundTxHex).toEqual(testVector.txs.fundingTx);
      expect(dlcTxs.cetsHex.map(GetTxidFromRawTransaction)).toEqual(
        testVector.txs.cets.map(GetTxidFromRawTransaction)
      );
      expect(GetTxidFromRawTransaction(dlcTxs.refundTxHex)).toEqual(
        GetTxidFromRawTransaction(testVector.txs.refundTx)
      );
    }
  }),
    test("fee test vector", () => {
      for (const testVector of feeTestVector) {
        const req: cfddlcjs.CreateDlcTransactionsRequest = {
          payouts: TestData.Payouts,
          localFundPubkey: TestData.LocalFundPubkey,
          remoteFundPubkey: TestData.RemoteFundPubkey,
          localFinalScriptPubkey: GetScriptForLength(
            testVector.inputs.offerPayoutSPKLen
          ),
          remoteFinalScriptPubkey: GetScriptForLength(
            testVector.inputs.acceptPayoutSPKLen
          ),
          localInputAmount: TestData.LocalInputAmount,
          remoteInputAmount: TestData.RemoteInputAmount,
          localCollateralAmount: TestData.LocalCollateralAmount,
          remoteCollateralAmount: TestData.RemoteCollateralAmount,
          localChangeScriptPubkey: GetScriptForLength(
            testVector.inputs.offerChangeSPKLen
          ),
          remoteChangeScriptPubkey: GetScriptForLength(
            testVector.inputs.acceptChangeSPKLen
          ),
          refundLocktime: 0,
          localInputs: testVector.inputs.offerInputs.map((x) => {
            return {
              vout: 0,
              txid:
                "83266d6b22a9babf6ee469b88fd0d3a0c690525f7c903aff22ec8ee44214604f",
              maxWitnessLength: x.maxWitnessLen,
              redeemScript:
                x.redeemScriptLen > 0
                  ? CfdUtils.ParseAsmScript("00".repeat(x.redeemScriptLen))
                  : "",
            };
          }),
          remoteInputs: testVector.inputs.acceptInputs.map((x) => {
            return {
              vout: 0,
              txid:
                "83266d6b22a9babf6ee469b88fd0d3a0c690525f7c903aff22ec8ee44214604f",
              maxWitnessLength: x.maxWitnessLen,
              redeemScript:
                x.redeemScriptLen > 0
                  ? CfdUtils.ParseAsmScript("00".repeat(x.redeemScriptLen))
                  : "",
            };
          }),
          feeRate: testVector.inputs.feeRate,
        };
        const dlcTxs = cfddlcjs.CreateDlcTransactions(req);
        const fundTx = CfdUtils.DecodeRawTransaction(dlcTxs.fundTxHex);

        const localTotalFee =
          TestData.LocalInputAmount -
          TestData.LocalCollateralAmount -
          Number(fundTx.vout[1].value);
        const remoteTotalFee =
          TestData.RemoteInputAmount -
          TestData.RemoteCollateralAmount -
          Number(fundTx.vout[2].value);
        const totalClosingFee =
          Number(fundTx.vout[0].value) -
          TestData.LocalCollateralAmount -
          TestData.RemoteCollateralAmount;
        expect(localTotalFee).toEqual(
          testVector.offerFundingFee + testVector.offerClosingFee
        );

        expect(remoteTotalFee).toEqual(
          testVector.acceptFundingFee + testVector.acceptClosingFee
        );

        expect(totalClosingFee).toEqual(
          testVector.offerClosingFee + testVector.acceptClosingFee
        );
      }
    });
});
