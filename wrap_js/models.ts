export module DlcTestVectors {

    export interface LocalPayouts {
        WIN: number;
        LOSE: number;
    }

    export interface OutPoint {
        txid: string;
        vout: number;
    }

    export interface Output {
        value: number;
        spk: string;
    }

    export interface Utxo {
        outPoint: OutPoint;
        output: Output;
        keys: string[];
        hashType: number;
        scriptWitness: string;
    }

    export interface Inputs {
        localPayouts: LocalPayouts;
        realOutcome: string;
        oracleKey: string;
        oracleSig: string;
        oracleKValue: string;
        oracleRValue: string;
        localExtPrivKey: string;
        localInput: number;
        localFundingUtxos: Utxo[];
        localChangeSPK: string;
        remoteExtPrivKey: string;
        remoteInput: number;
        remoteFundingUtxos: Utxo[];
        remoteToRemoteSweepSPK: string;
        remoteChangeSPK: string;
        penaltyTimeout: number;
        contractMaturity: number;
        contractTimeout: number;
        feeRate: number;
    }

    export interface Outputs {
        fundingTx: string;
        localCets: string[];
        remoteCets: string[];
        refundTx: string;
        mutualCloseTx: string;
        localClosingTx: string;
        remoteClosingTx: string;
    }

    export interface RootObject {
        inputs: Inputs;
        outputs: Outputs;
    }

    export interface DlcTransactions {

        fundTxHex: string;
        closingCetsHex: string[];
        refundTxHex: string;
    }
}