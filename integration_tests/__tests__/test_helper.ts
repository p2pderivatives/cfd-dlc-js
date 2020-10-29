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
  readonly oracleKValues = [
    "8864177b5ec22563e9b325c11726a270d259b7adc16a2051d9d9256eede64c79",
    "9e1bc6dc95ce931903cc2df67640cf6cca94ddd96aab0b847780d644e46cfae3",
  ];
  readonly oraclePubkey = CfdUtils.GetSchnorrPubkeyFromPrivkey(this.oracleKey);
  readonly oracleRValues = this.oracleKValues.map((x) =>
    CfdUtils.GetSchnorrPubkeyFromPrivkey(x)
  );

  readonly winMessages = ["1", "0"];
  readonly loseMessages = ["0", "1"];
  readonly messages = [this.winMessages, this.loseMessages];
  readonly winAmount = 9990000;
  readonly loseAmount = 10000;
  readonly collateral = (this.winAmount + this.loseAmount) / 2;
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
  readonly csvDelay = 50;
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
    this.aliceFundPubkey = CfdUtils.GetPubkeyFromPrivkey(
      this.aliceFundPrivkey
    );
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

    DlcWalletHelper.Timeout(5000);

    const aliceUtxos = await this.aliceWallet.utxoService.listUnspent();
    this.aliceInput = aliceUtxos[0];
    const aliceInputWif = await this.aliceWallet.dumpPrivkey(
      this.aliceInput.address
    );
    this.aliceInputPrv = CfdUtils.GetPrivkeyFromWif(aliceInputWif);
    const bobUtxos = await this.bobWallet.utxoService.listUnspent();
    this.bobInput = bobUtxos[0];
    const bobInputWif = await this.bobWallet.dumpPrivkey(
      this.bobInput.address
    );
    this.bobInputPrv = CfdUtils.GetPrivkeyFromWif(bobInputWif);
  }

  public CreateDlcTransactions() {
    const reqJson: cfddlcjs.CreateDlcTransactionsRequest = {
      payouts: [
        {
          local: this.winAmount,
          remote: this.loseAmount,
        },
        {
          local: this.loseAmount,
          remote: this.winAmount,
        },
      ],
      localFundPubkey: this.aliceFundPubkey,
      remoteFundPubkey: this.bobFundPubkey,
      localInputAmount: this.aliceInput.amount,
      localCollateralAmount: this.collateral,
      remoteInputAmount: this.bobInput.amount,
      remoteCollateralAmount: this.collateral,
      localInputs: [
        {
          txid: this.aliceInput.txid,
          vout: this.aliceInput.vout,
          maxWitnessLength: 108,
        },
      ],
      localChangeScriptPubkey: CfdUtils.GetAddressScript(
        this.aliceChangeAddress
      ),
      remoteInputs: [
        {
          txid: this.bobInput.txid,
          vout: this.bobInput.vout,
          maxWitnessLength: 108,
        },
      ],
      remoteChangeScriptPubkey: CfdUtils.GetAddressScript(
        this.bobChangeAddress
      ),
      refundLocktime: 1579082156,
      feeRate: 2,
      localFinalScriptPubkey: CfdUtils.GetAddressScript(
        this.aliceFinalAddress
      ),
      remoteFinalScriptPubkey: CfdUtils.GetAddressScript(this.bobFinalAddress),
    };

    return cfddlcjs.CreateDlcTransactions(reqJson);
  }
}
