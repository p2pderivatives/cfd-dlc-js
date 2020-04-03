const WalletManager = require('wallet-for-testing-js');
import * as fs from 'fs';
import * as cfd from 'cfd-js';
import * as cfddlcjs from '../../index.js';
// const path = require('path');

function SignFundTransactionInput(transaction: string, input: any, prv: any) {
  const reqJson = {
    fundTxHex: transaction,
    privkey: prv,
    prevTxid: input.txid,
    prevTxVout: input.vout,
    amount: BigInt(input.amount),
  }

  return cfddlcjs.SignFundTransaction(reqJson).hex;
}

function SignCet(
  transaction: string, fundTxId: string, fundAmount: bigint, prv1: string, prv2: string) {
  let reqJson: cfddlcjs.GetRawCetSignatureRequest = {
    cetHex: transaction,
    privkey: prv1,
    fundTxId: fundTxId,
    fundTxVout: 0,
    fundAmount: BigInt(fundAmount),
    localFundPubkey: GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: GetPubkeyFromPrivkey(prv2),
  }


  const sig1 = cfddlcjs.GetRawCetSignature(reqJson).hex;
  reqJson.privkey = prv2;
  const sig2 = cfddlcjs.GetRawCetSignature(reqJson).hex;

  const addSigReq: cfddlcjs.AddSignaturesToCetRequest = {
    cetHex: transaction,
    signatures: [sig1, sig2],
    fundTxId: fundTxId,
    fundTxVout: 0,
    localFundPubkey: GetPubkeyFromPrivkey(prv1),
    remoteFundPubkey: GetPubkeyFromPrivkey(prv2),
  };

  return cfddlcjs.AddSignaturesToCet(addSigReq).hex;
}

function GetPrivkeyFromWif(wif: string) {
  const req = {
    wif: wif,
  }

  return cfd.GetPrivkeyFromWif(req).hex;
}

function DecodeRawTransaction(rawTransaction: string) {
  let reqJson: cfd.DecodeRawTransactionRequest = {
    hex: rawTransaction,
  };

  return cfd.DecodeRawTransaction(reqJson);
}

async function GetNewPrivateKeyFromWallet(wallet: any) {
  let resp = await wallet.getNewAddress("p2pkh", "");
  const wif = await wallet.dumpPrivkey(resp.address);
  return GetPrivkeyFromWif(wif);
}

async function GetP2WPKHAddress(wallet: any) {
  const resp = await wallet.getNewAddress("p2wpkh", "");
  return resp.address;
}

function GetPubkeyFromPrivkey(privkey: string) {
  let reqPrivKey = {
    privkey: privkey,
    isCompressed: true,
  };

  return cfd.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
}

const network = "regtest";
const configFilePath = __dirname + "/bitcoin.conf";
const testSeed =
  "0e09fbdd00e575b654d480ae979f24da45ef4dee645c7dc2e3b30b2e093d38dda0202357754cc856f8920b8e31dd02e9d34f6a2b20dc825c6ba90f90009085e1";
const oracleKey = "85e9cf11bd33a4ccc6abf6c5078e2a7e44aff9c456934976cb86cffe3e1e13dc";
const oracleKValue = "8864177b5ec22563e9b325c11726a270d259b7adc16a2051d9d9256eede64c79";
const oraclePubkey = GetPubkeyFromPrivkey(oracleKey);
const oracleRValue = GetPubkeyFromPrivkey(oracleKValue);

let walletMgr: any;
let aliceWallet: any;
let bobWallet: any;
// let btcWallet3;

const timeout = async function (ms: any) {
  return new Promise(resolve => setTimeout(resolve, ms));
};

beforeAll(async () => {
  console.log("initialize node");
  const dbDir = __dirname + "/dbdir";
  // initialize db dir
  try {
    fs.statSync(dbDir);
    const files = fs.readdirSync(dbDir);
    for (const file in files) {
      if (files[file]) {
        const targetFile = files[file];
        fs.unlinkSync(`${dbDir}/${targetFile}`);
      }
    }
    fs.rmdirSync(dbDir);
  } catch (err) {
    if (err.code !== "ENOENT") throw err;
  }
  fs.mkdirSync(dbDir);

  // initialize walletManager
  walletMgr = new WalletManager(configFilePath, dbDir, network, testSeed);
  walletMgr.initialize("bitcoin");

  console.log("initialize wallet");
  aliceWallet = await walletMgr.createWallet(1, "alice", "bitcoin");
  bobWallet = await walletMgr.createWallet(2, "bob", "bitcoin");
});

describe("dlc tests", () => {
  it("test full execution", async () => {

    const winAmount = 9990000;
    const loseAmount = 10000;
    const collateral = (winAmount + loseAmount) / 2
    const aliceFundPrivkey = await GetNewPrivateKeyFromWallet(aliceWallet);
    const aliceFundPubkey = GetPubkeyFromPrivkey(aliceFundPrivkey);
    const aliceSweepPrivkey = await GetNewPrivateKeyFromWallet(aliceWallet);
    const aliceSweepPubkey = GetPubkeyFromPrivkey(aliceSweepPrivkey);
    const aliceFinalAddress = await GetP2WPKHAddress(aliceWallet);
    const aliceChangeAddress = await GetP2WPKHAddress(aliceWallet);
    const bobFundPrivkey = await GetNewPrivateKeyFromWallet(bobWallet);
    const bobFundPubkey = GetPubkeyFromPrivkey(bobFundPrivkey);
    const bobSweepPrivkey = await GetNewPrivateKeyFromWallet(bobWallet);
    const bobSweepPubkey = GetPubkeyFromPrivkey(bobSweepPrivkey);
    const bobFinalAddress = await GetP2WPKHAddress(bobWallet);
    const bobChangeAddress = await GetP2WPKHAddress(bobWallet);

    const amount = 200000000; // 2BTC
    await aliceWallet.generate(100);
    let ret = await aliceWallet.generateFund(amount)
    ret = await bobWallet.generateFund(amount)
    await aliceWallet.generate(100)
    await bobWallet.generate(100)

    const aliceUtxos = await aliceWallet.utxoService.listUnspent();
    const aliceInput = aliceUtxos[0];
    const aliceInputWif = await aliceWallet.dumpPrivkey(aliceInput.address);
    const aliceInputPrv = GetPrivkeyFromWif(aliceInputWif);
    const bobUtxos = await bobWallet.utxoService.listUnspent();
    const bobInput = bobUtxos[0];
    const bobInputWif = await bobWallet.dumpPrivkey(bobInput.address);
    const bobInputPrv = GetPrivkeyFromWif(bobInputWif);

    console.log(aliceInput.amount);
    console.log(collateral)
    console.log(winAmount)

    const reqJson: cfddlcjs.CreateDlcTransactionsRequest = {
      outcomes: [
        {
          local: BigInt(winAmount),
          remote: BigInt(loseAmount),
          messages: ["WIN"],
        },
        {
          local: BigInt(loseAmount),
          remote: BigInt(winAmount),
          messages: ["LOSE"]
        }
      ],
      oracleRPoints: [oracleRValue],
      oraclePubkey: oraclePubkey,
      localFundPubkey: aliceFundPubkey,
      remoteFundPubkey: bobFundPubkey,
      localSweepPubkey: aliceSweepPubkey,
      remoteSweepPubkey: bobSweepPubkey,
      localInputAmount: BigInt(aliceInput.amount),
      localCollateralAmount: BigInt(collateral),
      remoteInputAmount: BigInt(bobInput.amount),
      remoteCollateralAmount: BigInt(collateral),
      timeout: 50,
      localInputs:
        [{
          txid: aliceInput.txid,
          vout: aliceInput.vout,
        }],
      localChangeAddress: aliceChangeAddress,
      remoteInputs:
        [{
          txid: bobInput.txid,
          vout: bobInput.vout,
        }],
      remoteChangeAddress: bobChangeAddress,
      maturityTime: BigInt(1579072156),
      feeRate: 2,
      localFinalAddress: aliceFinalAddress,
      remoteFinalAddress: bobFinalAddress,
    };

    const dlctxs = cfddlcjs.CreateDlcTransactions(reqJson);

    let fundTxHex = SignFundTransactionInput(dlctxs.fundTxHex, aliceInput, aliceInputPrv);
    fundTxHex = SignFundTransactionInput(fundTxHex, bobInput, bobInputPrv);

    console.log(fundTxHex);
    const fundTx = DecodeRawTransaction(fundTxHex);

    const fundTxId = await aliceWallet.sendRawTransaction(fundTxHex);

    console.log(fundTxId + " " + fundTx.txid);
    expect(fundTxId).toBe(fundTx.txid);

    await aliceWallet.generate(20);
    await bobWallet.generate(20);
    await aliceWallet.forceUpdateUtxoData();
    await bobWallet.forceUpdateUtxoData();

    console.log(aliceChangeAddress)
    console.log(bobChangeAddress)

    const aliceChangeBalance = await aliceWallet.getBalance(1, aliceChangeAddress);
    console.log(aliceChangeBalance);
    expect(aliceChangeBalance.bitcoin).toBeGreaterThan(0);

    const bobChangeBalance = await bobWallet.getBalance(1, bobChangeAddress);
    console.log(bobChangeBalance);
    expect(bobChangeBalance.bitcoin).toBeGreaterThan(0);

    let cetHex = SignCet(
      dlctxs.closingCetsHex[0],
      fundTxId, fundTx.vout[0].value,
      aliceFundPrivkey,
      bobFundPrivkey);
    const cet = DecodeRawTransaction(fundTxHex);

    const cetId = await aliceWallet.sendRawTransaction(cetHex);

    console.log(cetId + " " + cet.txid);
    expect(cetId).toBe(cet.txid);
  });
});
