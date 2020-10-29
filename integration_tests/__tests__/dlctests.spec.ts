import * as CfdDlcUtils from "../../wrap_js/cfddlc_utils";
import * as CfdUtils from "../../wrap_js/cfd_utils";
import { DlcTestHelper } from "./test_helper";
import { DlcWalletHelper } from "./wallet_helper";

const SyncTimeout = 1000;

jest.setTimeout(50000);
const walletHelper = new DlcWalletHelper();

beforeAll(async () => {
  await walletHelper.Initialize();
});

describe("dlc tests", () => {
  it("test full execution", async () => {
    const testHelper = new DlcTestHelper(
      walletHelper.aliceWallet,
      walletHelper.bobWallet
    );

    await testHelper.Initialize();

    const oracleSignatures = testHelper.winMessages.map((m, i) =>
      CfdUtils.SchnorrSign(
        m,
        testHelper.oracleKey,
        testHelper.oracleKValues[i]
      )
    );

    expect(
      oracleSignatures.every((s, i) =>
        CfdUtils.SchnorrVerify(
          testHelper.winMessages[i],
          s,
          testHelper.oraclePubkey
        )
      )
    ).toBeTruthy();

    const dlctxs = testHelper.CreateDlcTransactions();

    const fundTx = CfdUtils.DecodeRawTransaction(dlctxs.fundTxHex);
    const fundTxId = fundTx.txid;
    const fundInputAmount = Number(fundTx.vout[0].value);

    const localAdaptorPairs = CfdDlcUtils.CreateCetAdaptorSignatures(
      dlctxs.cetsHex,
      testHelper.aliceFundPrivkey,
      testHelper.oraclePubkey,
      testHelper.oracleRValues,
      testHelper.messages,
      fundTx.txid,
      0,
      fundInputAmount,
      testHelper.aliceFundPubkey,
      testHelper.bobFundPubkey
    );

    const validLocalAdaptorPairs = CfdDlcUtils.VerifyAdaptorSignatures(
      dlctxs.cetsHex,
      localAdaptorPairs,
      testHelper.messages,
      testHelper.oraclePubkey,
      testHelper.oracleRValues,
      testHelper.aliceFundPubkey,
      testHelper.bobFundPubkey,
      fundTxId,
      fundInputAmount,
      false
    );

    expect(validLocalAdaptorPairs).toBeTruthy();

    const remoteAdaptorPairs = CfdDlcUtils.CreateCetAdaptorSignatures(
      dlctxs.cetsHex,
      testHelper.bobFundPrivkey,
      testHelper.oraclePubkey,
      testHelper.oracleRValues,
      testHelper.messages,
      fundTx.txid,
      0,
      Number(fundTx.vout[0].value),
      testHelper.aliceFundPubkey,
      testHelper.bobFundPubkey
    );

    const validRemoteAdaptorPairs = CfdDlcUtils.VerifyAdaptorSignatures(
      dlctxs.cetsHex,
      remoteAdaptorPairs,
      testHelper.messages,
      testHelper.oraclePubkey,
      testHelper.oracleRValues,
      testHelper.aliceFundPubkey,
      testHelper.bobFundPubkey,
      fundTxId,
      fundInputAmount,
      true
    );

    expect(validRemoteAdaptorPairs).toBeTruthy();

    let fundTxHex = CfdDlcUtils.SignFundTransactionInput(
      dlctxs.fundTxHex,
      testHelper.aliceInput,
      testHelper.aliceInputPrv
    );
    fundTxHex = CfdDlcUtils.SignFundTransactionInput(
      fundTxHex,
      testHelper.bobInput,
      testHelper.bobInputPrv
    );

    const receivedFundTxId = await testHelper.aliceWallet.sendRawTransaction(
      fundTxHex
    );

    expect(receivedFundTxId).toBe(fundTxId);

    await testHelper.bobWallet.generate(1);
    await testHelper.aliceWallet.generate(1);

    await DlcWalletHelper.Timeout(SyncTimeout);

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.Timeout(SyncTimeout);

    const aliceChangeBalance = await testHelper.aliceWallet.getBalance(
      1,
      testHelper.aliceChangeAddress
    );
    expect(aliceChangeBalance.bitcoin).toBeGreaterThan(0);

    const bobChangeBalance = await testHelper.bobWallet.getBalance(
      1,
      testHelper.bobChangeAddress
    );

    expect(bobChangeBalance.bitcoin).toBeGreaterThan(0);

    const cetHex = CfdDlcUtils.SignCet(
      dlctxs.cetsHex[0],
      fundTxId,
      fundInputAmount,
      remoteAdaptorPairs[0].signature,
      testHelper.aliceFundPrivkey,
      oracleSignatures,
      testHelper.aliceFundPubkey,
      testHelper.bobFundPubkey
    );
    const cet = CfdUtils.DecodeRawTransaction(cetHex);

    const cetId = await testHelper.aliceWallet.sendRawTransaction(cetHex);

    expect(cetId).toBe(cet.txid);

    await testHelper.aliceWallet.generate(1);
    await testHelper.bobWallet.generate(1);

    await DlcWalletHelper.Timeout(SyncTimeout);

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.Timeout(SyncTimeout);

    const aliceFinalBalance = await testHelper.aliceWallet.getBalance(
      1,
      testHelper.aliceFinalAddress
    );
    const bobFinalBalance = await testHelper.bobWallet.getBalance(
      1,
      testHelper.bobFinalAddress
    );

    expect(aliceFinalBalance.bitcoin).toBe(Number(testHelper.winAmount));
    expect(bobFinalBalance.bitcoin).toBe(Number(testHelper.loseAmount));
  });

  it("test refund", async () => {
    const testHelper = new DlcTestHelper(
      walletHelper.aliceWallet,
      walletHelper.bobWallet
    );

    await testHelper.Initialize();
    const dlctxs = testHelper.CreateDlcTransactions();
    let fundTxHex = CfdDlcUtils.SignFundTransactionInput(
      dlctxs.fundTxHex,
      testHelper.aliceInput,
      testHelper.aliceInputPrv
    );

    fundTxHex = CfdDlcUtils.SignFundTransactionInput(
      fundTxHex,
      testHelper.bobInput,
      testHelper.bobInputPrv
    );

    const fundTxId = await testHelper.aliceWallet.sendRawTransaction(
      fundTxHex
    );

    const fundTx = CfdUtils.DecodeRawTransaction(fundTxHex);

    const refundTxHex = CfdDlcUtils.SignRefundTransaction(
      dlctxs.refundTxHex,
      fundTxId,
      Number(fundTx.vout[0].value),
      testHelper.aliceFundPrivkey,
      testHelper.bobFundPrivkey
    );

    const refundTx = CfdUtils.DecodeRawTransaction(refundTxHex);

    const refundTxId = await testHelper.aliceWallet.sendRawTransaction(
      refundTxHex
    );

    expect(refundTx.txid).toEqual(refundTxId);

    await testHelper.aliceWallet.generate(1);
    await testHelper.bobWallet.generate(1);

    await DlcWalletHelper.Timeout(SyncTimeout);

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.Timeout(SyncTimeout);

    const aliceFinalBalance = await testHelper.aliceWallet.getBalance(
      1,
      testHelper.aliceFinalAddress
    );
    const bobFinalBalance = await testHelper.bobWallet.getBalance(
      1,
      testHelper.bobFinalAddress
    );

    expect(aliceFinalBalance.bitcoin).toBeGreaterThan(
      Number(testHelper.collateral)
    );
    expect(bobFinalBalance.bitcoin).toBeGreaterThan(
      Number(testHelper.collateral)
    );
  });
});
