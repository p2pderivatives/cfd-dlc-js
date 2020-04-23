import WalletManager = require("wallet-for-testing-js");
import * as fs from "fs";
import path from "path";

export class DlcWalletHelper {
  readonly network = "regtest";
  readonly configFilePath = __dirname + "/bitcoin.conf";
  readonly testSeed =
    "0e09fbdd00e575b654d480ae979f24da45ef4dee645c7dc2e3b30b2e093d38dda0202357754cc856f8920b8e31dd02e9d34f6a2b20dc825c6ba90f90009085e1";
  walletMgr: any;
  aliceWallet: any;
  bobWallet: any;

  public static async Timeout(ms: any) {
    return new Promise((resolve) => setTimeout(resolve, ms));
  }

  public static async SyncWait() {
    // wait update
    try {
      await this.Timeout(5000);
    } catch (tmerr) {
      // ignore error
    }
  }

  public async Initialize() {
    const dbDir = path.join(__dirname, "dbdir");
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

    try {
      fs.mkdirSync(dbDir);
    } catch (tmerr) {
      await DlcWalletHelper.Timeout(1000);
      fs.mkdirSync(dbDir);
    }

    // initialize walletManager
    this.walletMgr = new WalletManager(
      this.configFilePath,
      dbDir,
      this.network,
      this.testSeed
    );
    this.walletMgr.initialize("bitcoin");

    this.aliceWallet = await this.walletMgr.createWallet(1, "alice", "bitcoin");
    this.bobWallet = await this.walletMgr.createWallet(2, "bob", "bitcoin");
  }
}
