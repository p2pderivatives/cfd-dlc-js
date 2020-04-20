import * as cfddlcjs from "../../index.js";
import * as CfdDlcUtils from "../../wrap_js/cfddlc_utils";
import * as CfdUtils from "../../wrap_js/cfd_utils";
import * as WalletUtils from "../../wrap_js/wallet_utils";
import { DlcWalletHelper } from "./wallet_helper";

export class DlcTestHelper {
  readonly aliceWallet;
  readonly bobWallet;
  readonly oracleKey =
    "85e9cf11bd33a4ccc6abf6c5078e2a7e44aff9c456934976cb86cffe3e1e13dc";
  readonly oracleKValue =
    "8864177b5ec22563e9b325c11726a270d259b7adc16a2051d9d9256eede64c79";
  readonly oraclePubkey = CfdUtils.GetPubkeyFromPrivkey(this.oracleKey);
  readonly oracleRValue = CfdDlcUtils.GetSchnorrPublicNonce(this.oracleKValue);

  readonly winMessages = ["WIN"];
  readonly loseMessages = ["LOSE"];
  readonly winAmount = BigInt(9990000);
  readonly loseAmount = BigInt(10000);
  readonly collateral = (this.winAmount + this.loseAmount) / BigInt(2);
  aliceFundPrivkey: string;
  aliceFundPubkey: string;
  aliceSweepPrivkey: string;
  aliceSweepPubkey: string;
  aliceFinalAddress: string;
  aliceChangeAddress: string;
  bobFundPrivkey: string;
  bobFundPubkey: string;
  bobSweepPrivkey: string;
  bobSweepPubkey: string;
  bobFinalAddress: string;
  bobChangeAddress: string;
  readonly dlcTimeout = 50;
  aliceInput;
  aliceInputPrv;
  bobInput;
  bobInputPrv;

  constructor(aliceWallet, bobWallet) {
    this.aliceWallet = aliceWallet;
    this.bobWallet = bobWallet;
  }

  public async Initialize() {
    this.aliceFundPrivkey = await WalletUtils.GetNewPrivateKeyFromWallet(
      this.aliceWallet
    );
    this.aliceFundPubkey = CfdUtils.GetPubkeyFromPrivkey(this.aliceFundPrivkey);
    this.aliceSweepPrivkey = await WalletUtils.GetNewPrivateKeyFromWallet(
      this.aliceWallet
    );
    this.aliceSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(
      this.aliceSweepPrivkey
    );
    this.aliceFinalAddress = await WalletUtils.GetP2WPKHAddress(
      this.aliceWallet
    );
    this.aliceChangeAddress = await WalletUtils.GetP2WPKHAddress(
      this.aliceWallet
    );
    this.bobFundPrivkey = await WalletUtils.GetNewPrivateKeyFromWallet(
      this.bobWallet
    );
    this.bobFundPubkey = CfdUtils.GetPubkeyFromPrivkey(this.bobFundPrivkey);
    this.bobSweepPrivkey = await WalletUtils.GetNewPrivateKeyFromWallet(
      this.bobWallet
    );
    this.bobSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(this.bobSweepPrivkey);
    this.bobFinalAddress = await WalletUtils.GetP2WPKHAddress(this.bobWallet);
    this.bobChangeAddress = await WalletUtils.GetP2WPKHAddress(this.bobWallet);

    const amount = 200000000; // 2BTC
    await this.aliceWallet.generate(100);
    await this.aliceWallet.generateFund(amount);
    await this.bobWallet.generateFund(amount);
    await this.aliceWallet.generate(100);
    await this.bobWallet.generate(100);

    DlcWalletHelper.SyncWait();

    const aliceUtxos = await this.aliceWallet.utxoService.listUnspent();
    this.aliceInput = aliceUtxos[0];
    const aliceInputWif = await this.aliceWallet.dumpPrivkey(
      this.aliceInput.address
    );
    this.aliceInputPrv = CfdUtils.GetPrivkeyFromWif(aliceInputWif);
    const bobUtxos = await this.bobWallet.utxoService.listUnspent();
    this.bobInput = bobUtxos[0];
    const bobInputWif = await this.bobWallet.dumpPrivkey(this.bobInput.address);
    this.bobInputPrv = CfdUtils.GetPrivkeyFromWif(bobInputWif);
  }

  public CreateDlcTransactions() {
    const reqJson: cfddlcjs.CreateDlcTransactionsRequest = {
      outcomes: [
        {
          local: this.winAmount,
          remote: this.loseAmount,
          messages: this.winMessages,
        },
        {
          local: this.loseAmount,
          remote: this.winAmount,
          messages: this.loseMessages,
        },
      ],
      oracleRPoints: [this.oracleRValue],
      oraclePubkey: this.oraclePubkey,
      localFundPubkey: this.aliceFundPubkey,
      remoteFundPubkey: this.bobFundPubkey,
      localSweepPubkey: this.aliceSweepPubkey,
      remoteSweepPubkey: this.bobSweepPubkey,
      localInputAmount: BigInt(this.aliceInput.amount),
      localCollateralAmount: BigInt(this.collateral),
      remoteInputAmount: BigInt(this.bobInput.amount),
      remoteCollateralAmount: this.collateral,
      timeout: this.dlcTimeout,
      localInputs: [
        {
          txid: this.aliceInput.txid,
          vout: this.aliceInput.vout,
        },
      ],
      localChangeAddress: this.aliceChangeAddress,
      remoteInputs: [
        {
          txid: this.bobInput.txid,
          vout: this.bobInput.vout,
        },
      ],
      remoteChangeAddress: this.bobChangeAddress,
      maturityTime: BigInt(1579072156),
      feeRate: 2,
      localFinalAddress: this.aliceFinalAddress,
      remoteFinalAddress: this.bobFinalAddress,
    };

    return cfddlcjs.CreateDlcTransactions(reqJson);
  }
}
