import * as CfdUtils from "../../wrap_js/cfd_utils";
import * as CfdDlcUtils from "../../wrap_js/cfddlc_utils";
import { DlcWalletHelper } from "./wallet_helper";
import { DlcTestHelper } from "./test_helper";

jest.setTimeout(30000);
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

    const oracleSignature = CfdDlcUtils.SchnorrSign(
      testHelper.winMessages[0],
      testHelper.oracleKey,
      testHelper.oracleKValue
    );

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

    const fundTx = CfdUtils.DecodeRawTransaction(fundTxHex);

    const fundTxId = await testHelper.aliceWallet.sendRawTransaction(fundTxHex);

    expect(fundTxId).toBe(fundTx.txid);

    await testHelper.bobWallet.generate(1);
    await testHelper.aliceWallet.generate(1);

    await DlcWalletHelper.SyncWait();

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.SyncWait();

    const aliceChangeBalance = await testHelper.aliceWallet.getBalance(
      1,
      testHelper.aliceChangeAddress
    );
    expect(aliceChangeBalance.bitcoin).toBeGreaterThan(0);

    const bobChangeBalance = await testHelper.bobWallet.getBalance(
      1,
      testHelper.bobChangeAddress
    );

    console.log(aliceChangeBalance);
    console.log(bobChangeBalance);
    expect(bobChangeBalance.bitcoin).toBeGreaterThan(0);

    const cetHex = CfdDlcUtils.SignCet(
      dlctxs.closingCetsHex[0],
      fundTxId,
      BigInt(fundTx.vout[0].value),
      testHelper.aliceFundPrivkey,
      testHelper.bobFundPrivkey
    );
    const cet = CfdUtils.DecodeRawTransaction(cetHex);

    const cetId = await testHelper.aliceWallet.sendRawTransaction(cetHex);

    expect(cetId).toBe(cet.txid);

    let closingHex = CfdDlcUtils.CreateClosingTx(
      testHelper.aliceFinalAddress,
      BigInt(cet.vout[0].value) - BigInt(122 * 2),
      cet.txid,
      0
    );
    closingHex = CfdDlcUtils.SignClosingTx(
      closingHex,
      testHelper.aliceFundPrivkey,
      testHelper.aliceSweepPubkey,
      testHelper.bobSweepPubkey,
      testHelper.oraclePubkey,
      [testHelper.oracleRValue],
      testHelper.winMessages,
      [oracleSignature],
      BigInt(testHelper.dlcTimeout),
      cet.txid,
      BigInt(cet.vout[0].value)
    );

    const closingTxid = await testHelper.bobWallet.sendRawTransaction(
      closingHex
    );

    const closingTx = CfdUtils.DecodeRawTransaction(closingHex);

    expect(closingTxid).toEqual(closingTx.txid);

    await testHelper.aliceWallet.generate(1);
    await testHelper.bobWallet.generate(1);

    await DlcWalletHelper.SyncWait();

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.SyncWait();

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

    const fundTxId = await testHelper.aliceWallet.sendRawTransaction(fundTxHex);

    const fundTx = CfdUtils.DecodeRawTransaction(fundTxHex);

    const refundTxHex = CfdDlcUtils.SignRefundTransaction(
      dlctxs.refundTxHex,
      fundTxId,
      fundTx.vout[0].value,
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

    await DlcWalletHelper.SyncWait();

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.SyncWait();

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

  it("test mutual closing", async () => {
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

    const fundTxId = await testHelper.aliceWallet.sendRawTransaction(fundTxHex);

    const fundTx = CfdUtils.DecodeRawTransaction(fundTxHex);

    let mutualClosingHex = CfdDlcUtils.CreateMutualClosingTx(
      testHelper.aliceFinalAddress,
      testHelper.bobFinalAddress,
      testHelper.winAmount,
      testHelper.loseAmount,
      fundTxId
    );

    mutualClosingHex = CfdDlcUtils.SignMutualClosingTx(
      mutualClosingHex,
      fundTx.txid,
      fundTx.vout[0].value,
      testHelper.aliceFundPrivkey,
      testHelper.bobFundPrivkey
    );

    const mutualClosing = CfdUtils.DecodeRawTransaction(mutualClosingHex);

    const mutualClosingTxId = await testHelper.aliceWallet.sendRawTransaction(
      mutualClosingHex
    );

    expect(mutualClosing.txid).toEqual(mutualClosingTxId);

    await testHelper.aliceWallet.generate(1);
    await testHelper.bobWallet.generate(1);

    await DlcWalletHelper.SyncWait();

    await testHelper.aliceWallet.forceUpdateUtxoData();
    await testHelper.bobWallet.forceUpdateUtxoData();

    await DlcWalletHelper.SyncWait();

    const aliceFinalBalance = await testHelper.aliceWallet.getBalance(
      1,
      testHelper.aliceFinalAddress
    );
    const bobFinalBalance = await testHelper.bobWallet.getBalance(
      1,
      testHelper.bobFinalAddress
    );

    expect(aliceFinalBalance.bitcoin).toBeGreaterThan(
      Number(testHelper.winAmount)
    );
    expect(bobFinalBalance.bitcoin).toBeGreaterThan(
      Number(testHelper.loseAmount)
    );
  });
});
