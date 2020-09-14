/* eslint-disable max-len */
/* eslint-disable indent */

/** Add signatures to a CET */
export interface AddSignaturesToCetRequest {
    cetHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToCetResponse {
    hex: string;
}

/** Add signatures to a mutual closing transaction */
export interface AddSignaturesToMutualClosingTxRequest {
    mutualClosingTxHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToMutualClosingTxResponse {
    hex: string;
}

/** Add signatures to a refund transaction */
export interface AddSignaturesToRefundTxRequest {
    refundTxHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToRefundTxResponse {
    hex: string;
}

/** Add a signature to fund transaction */
export interface AddSignatureToFundTransactionRequest {
    fundTxHex: string;
    signature: string;
    prevTxId: string;
    prevVout: number;
    pubkey: string;
}

export interface AddSignatureToFundTransactionResponse {
    hex: string;
}

/** Create a CET */
export interface CreateCetRequest {
    localFundPubkey: string;
    localSweepPubkey: string;
    remoteSweepPubkey: string;
    remoteFinalAddress: string;
    oraclePubkey: string;
    oracleRPoints: string[];
    messages: string[];
    csvDelay: number;
    localPayout: bigint | number;
    remotePayout: bigint | number;
    feeRate: bigint | number;
    fundTxId: string;
    fundVout?: number;
    maturityTime: bigint | number;
}

export interface CreateCetResponse {
    hex: string;
}

/** Create a closing transaction */
export interface CreateClosingTransactionRequest {
    address: string;
    amount: bigint | number;
    cetTxId: string;
    cetVout?: number;
}

export interface CreateClosingTransactionResponse {
    hex: string;
}

/** Create Dlc transactions */
export interface CreateDlcTransactionsRequest {
    outcomes: PayoutRequest[];
    oracleRPoints: string[];
    oraclePubkey: string;
    localFundPubkey: string;
    localSweepPubkey: string;
    localFinalAddress: string;
    remoteFundPubkey: string;
    remoteSweepPubkey: string;
    remoteFinalAddress: string;
    localInputAmount: bigint | number;
    localCollateralAmount: bigint | number;
    remoteInputAmount: bigint | number;
    remoteCollateralAmount: bigint | number;
    csvDelay: bigint | number;
    refundLocktime: bigint | number;
    localInputs: TxInRequest[];
    localChangeAddress: string;
    remoteInputs: TxInRequest[];
    remoteChangeAddress: string;
    feeRate: number;
    maturityTime: bigint | number;
    optionDest?: string;
    optionPremium?: bigint | number;
}

export interface CreateDlcTransactionsResponse {
    fundTxHex: string;
    localCetsHex: string[];
    remoteCetsHex: string[];
    refundTxHex: string;
}

/** Create a fund transaction */
export interface CreateFundTransactionRequest {
    localPubkey: string;
    remotePubkey: string;
    outputAmount: bigint | number;
    localInputs: TxInRequest[];
    localChange: TxOutRequest;
    remoteInputs: TxInRequest[];
    remoteChange: TxOutRequest;
    feeRate: bigint | number;
    optionDest?: string;
    optionPremium?: bigint | number;
}

export interface CreateFundTransactionResponse {
    hex: string;
}

/** Create a refund transaction */
export interface CreateMutualClosingTransactionRequest {
    localFinalAddress: string;
    remoteFinalAddress: string;
    localAmount: bigint | number;
    remoteAmount: bigint | number;
    feeRate: bigint | number;
    fundTxId: string;
    fundVout?: number;
}

export interface CreateMutualClosingTransactionResponse {
    hex: string;
}

/** Create a fund transaction */
export interface CreatePenaltyTransactionRequest {
    finalAddress: string;
    amount: bigint | number;
    cetTxId: string;
    cetVout?: number;
}

export interface CreatePenaltyTransactionResponse {
    hex: string;
}

/** Create a refund transaction */
export interface CreateRefundTransactionRequest {
    localFinalAddress: string;
    remoteFinalAddress: string;
    localAmount: bigint | number;
    remoteAmount: bigint | number;
    lockTime: bigint | number;
    fundTxId: string;
    fundVout?: number;
}

export interface CreateRefundTransactionResponse {
    hex: string;
}

export interface ErrorResponse {
    error: InnerErrorResponse;
}

/** Get a signature for a CET */
export interface GetRawCetSignatureRequest {
    cetHex: string;
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint | number;
}

export interface GetRawCetSignatureResponse {
    hex: string;
}

/** Get a signature for a CET */
export interface GetRawCetSignaturesRequest {
    cetsHex: string[];
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint | number;
}

export interface GetRawCetSignaturesResponse {
    hex: string[];
}

/** Get a signature for a fund transaction input */
export interface GetRawFundTxSignatureRequest {
    fundTxHex: string;
    privkey: string;
    prevTxId: string;
    prevVout: number;
    amount: bigint | number;
}

export interface GetRawFundTxSignatureResponse {
    hex: string;
}

/** Get a signature for a CET */
export interface GetRawMutualClosingTxSignatureRequest {
    mutualClosingHex: string;
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint | number;
}

export interface GetRawMutualClosingTxSignatureResponse {
    hex: string;
}

/** Get a signature for a CET */
export interface GetRawRefundTxSignatureRequest {
    refundTxHex: string;
    privkey: string;
    fundTxId: string;
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint | number;
}

export interface GetRawRefundTxSignatureResponse {
    hex: string;
}

/** Get a schnorr public nonce */
export interface GetSchnorrPublicNonceRequest {
    kValue: string;
}

export interface GetSchnorrPublicNonceResponse {
    hex: string;
}

export interface InnerErrorResponse {
    code: number;
    type: string;
    message: string;
}

export interface PayoutRequest {
    local: bigint | number;
    remote: bigint | number;
    messages: string[];
}

/** Create a Schnorr signature */
export interface SchnorrSignRequest {
    privkey: string;
    kValue: string;
    message: string;
}

export interface SchnorrSignResponse {
    hex: string;
}

/** Sign a closing transaction */
export interface SignClosingTransactionRequest {
    closingTxHex: string;
    localFundPrivkey: string;
    localSweepPubkey: string;
    remoteSweepPubkey: string;
    oraclePubkey: string;
    oracleRPoints: string[];
    messages: string[];
    csvDelay: bigint | number;
    oracleSigs: string[];
    cetTxId: string;
    cetVout?: number;
    amount: bigint | number;
}

export interface SignClosingTransactionResponse {
    hex: string;
}

/** Sign a fund transaction input */
export interface SignFundTransactionRequest {
    fundTxHex: string;
    privkey: string;
    prevTxId: string;
    prevVout: number;
    amount: bigint | number;
}

export interface SignFundTransactionResponse {
    hex: string;
}

export interface TxInRequest {
    txid: string;
    vout: number;
}

export interface TxOutRequest {
    amount: bigint | number;
    address: string;
}

/** Verify a signature for a CET */
export interface VerifyCetSignatureRequest {
    cetHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: bigint | number;
    verifyRemote: boolean;
}

export interface VerifyCetSignatureResponse {
    valid: boolean;
}

/** Verify a set of signatures for a set of CET */
export interface VerifyCetSignaturesRequest {
    cetsHex: string[];
    signatures: string[];
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: bigint | number;
    verifyRemote: boolean;
}

export interface VerifyCetSignaturesResponse {
    valid: boolean;
}

/** Verify a signature for a mutual closing transaction */
export interface VerifyFundTxSignatureRequest {
    fundTxHex: string;
    signature: string;
    pubkey: string;
    prevTxId: string;
    prevVout: number;
    fundInputAmount: bigint | number;
}

export interface VerifyFundTxSignatureResponse {
    valid: boolean;
}

/** Verify a signature for a mutual closing transaction */
export interface VerifyMutualClosingTxSignatureRequest {
    mutualClosingHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: bigint | number;
    verifyRemote: boolean;
}

export interface VerifyMutualClosingTxSignatureResponse {
    valid: boolean;
}

/** Verify a signature for a refund transaction */
export interface VerifyRefundTxSignatureRequest {
    refundTxHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout?: number;
    fundInputAmount: bigint | number;
    verifyRemote: boolean;
}

export interface VerifyRefundTxSignatureResponse {
    valid: boolean;
}

/**
 * @param {AddSignaturesToCetRequest} jsonObject - request data.
 * @return {AddSignaturesToCetResponse} - response data.
 */
export function AddSignaturesToCet(jsonObject: AddSignaturesToCetRequest): AddSignaturesToCetResponse;

/**
 * @param {AddSignaturesToMutualClosingTxRequest} jsonObject - request data.
 * @return {AddSignaturesToMutualClosingTxResponse} - response data.
 */
export function AddSignaturesToMutualClosingTx(jsonObject: AddSignaturesToMutualClosingTxRequest): AddSignaturesToMutualClosingTxResponse;

/**
 * @param {AddSignaturesToRefundTxRequest} jsonObject - request data.
 * @return {AddSignaturesToRefundTxResponse} - response data.
 */
export function AddSignaturesToRefundTx(jsonObject: AddSignaturesToRefundTxRequest): AddSignaturesToRefundTxResponse;

/**
 * @param {AddSignatureToFundTransactionRequest} jsonObject - request data.
 * @return {AddSignatureToFundTransactionResponse} - response data.
 */
export function AddSignatureToFundTransaction(jsonObject: AddSignatureToFundTransactionRequest): AddSignatureToFundTransactionResponse;

/**
 * @param {CreateCetRequest} jsonObject - request data.
 * @return {CreateCetResponse} - response data.
 */
export function CreateCet(jsonObject: CreateCetRequest): CreateCetResponse;

/**
 * @param {CreateClosingTransactionRequest} jsonObject - request data.
 * @return {CreateClosingTransactionResponse} - response data.
 */
export function CreateClosingTransaction(jsonObject: CreateClosingTransactionRequest): CreateClosingTransactionResponse;

/**
 * @param {CreateDlcTransactionsRequest} jsonObject - request data.
 * @return {CreateDlcTransactionsResponse} - response data.
 */
export function CreateDlcTransactions(jsonObject: CreateDlcTransactionsRequest): CreateDlcTransactionsResponse;

/**
 * @param {CreateFundTransactionRequest} jsonObject - request data.
 * @return {CreateFundTransactionResponse} - response data.
 */
export function CreateFundTransaction(jsonObject: CreateFundTransactionRequest): CreateFundTransactionResponse;

/**
 * @param {CreateMutualClosingTransactionRequest} jsonObject - request data.
 * @return {CreateMutualClosingTransactionResponse} - response data.
 */
export function CreateMutualClosingTransaction(jsonObject: CreateMutualClosingTransactionRequest): CreateMutualClosingTransactionResponse;

/**
 * @param {CreatePenaltyTransactionRequest} jsonObject - request data.
 * @return {CreatePenaltyTransactionResponse} - response data.
 */
export function CreatePenaltyTransaction(jsonObject: CreatePenaltyTransactionRequest): CreatePenaltyTransactionResponse;

/**
 * @param {CreateRefundTransactionRequest} jsonObject - request data.
 * @return {CreateRefundTransactionResponse} - response data.
 */
export function CreateRefundTransaction(jsonObject: CreateRefundTransactionRequest): CreateRefundTransactionResponse;

/**
 * @param {GetRawCetSignatureRequest} jsonObject - request data.
 * @return {GetRawCetSignatureResponse} - response data.
 */
export function GetRawCetSignature(jsonObject: GetRawCetSignatureRequest): GetRawCetSignatureResponse;

/**
 * @param {GetRawCetSignaturesRequest} jsonObject - request data.
 * @return {GetRawCetSignaturesResponse} - response data.
 */
export function GetRawCetSignatures(jsonObject: GetRawCetSignaturesRequest): GetRawCetSignaturesResponse;

/**
 * @param {GetRawFundTxSignatureRequest} jsonObject - request data.
 * @return {GetRawFundTxSignatureResponse} - response data.
 */
export function GetRawFundTxSignature(jsonObject: GetRawFundTxSignatureRequest): GetRawFundTxSignatureResponse;

/**
 * @param {GetRawMutualClosingTxSignatureRequest} jsonObject - request data.
 * @return {GetRawMutualClosingTxSignatureResponse} - response data.
 */
export function GetRawMutualClosingTxSignature(jsonObject: GetRawMutualClosingTxSignatureRequest): GetRawMutualClosingTxSignatureResponse;

/**
 * @param {GetRawRefundTxSignatureRequest} jsonObject - request data.
 * @return {GetRawRefundTxSignatureResponse} - response data.
 */
export function GetRawRefundTxSignature(jsonObject: GetRawRefundTxSignatureRequest): GetRawRefundTxSignatureResponse;

/**
 * @param {GetSchnorrPublicNonceRequest} jsonObject - request data.
 * @return {GetSchnorrPublicNonceResponse} - response data.
 */
export function GetSchnorrPublicNonce(jsonObject: GetSchnorrPublicNonceRequest): GetSchnorrPublicNonceResponse;

/**
 * @param {SchnorrSignRequest} jsonObject - request data.
 * @return {SchnorrSignResponse} - response data.
 */
export function SchnorrSign(jsonObject: SchnorrSignRequest): SchnorrSignResponse;

/**
 * @param {SignClosingTransactionRequest} jsonObject - request data.
 * @return {SignClosingTransactionResponse} - response data.
 */
export function SignClosingTransaction(jsonObject: SignClosingTransactionRequest): SignClosingTransactionResponse;

/**
 * @param {SignFundTransactionRequest} jsonObject - request data.
 * @return {SignFundTransactionResponse} - response data.
 */
export function SignFundTransaction(jsonObject: SignFundTransactionRequest): SignFundTransactionResponse;

/**
 * @param {VerifyCetSignatureRequest} jsonObject - request data.
 * @return {VerifyCetSignatureResponse} - response data.
 */
export function VerifyCetSignature(jsonObject: VerifyCetSignatureRequest): VerifyCetSignatureResponse;

/**
 * @param {VerifyCetSignaturesRequest} jsonObject - request data.
 * @return {VerifyCetSignaturesResponse} - response data.
 */
export function VerifyCetSignatures(jsonObject: VerifyCetSignaturesRequest): VerifyCetSignaturesResponse;

/**
 * @param {VerifyFundTxSignatureRequest} jsonObject - request data.
 * @return {VerifyFundTxSignatureResponse} - response data.
 */
export function VerifyFundTxSignature(jsonObject: VerifyFundTxSignatureRequest): VerifyFundTxSignatureResponse;

/**
 * @param {VerifyMutualClosingTxSignatureRequest} jsonObject - request data.
 * @return {VerifyMutualClosingTxSignatureResponse} - response data.
 */
export function VerifyMutualClosingTxSignature(jsonObject: VerifyMutualClosingTxSignatureRequest): VerifyMutualClosingTxSignatureResponse;

/**
 * @param {VerifyRefundTxSignatureRequest} jsonObject - request data.
 * @return {VerifyRefundTxSignatureResponse} - response data.
 */
export function VerifyRefundTxSignature(jsonObject: VerifyRefundTxSignatureRequest): VerifyRefundTxSignatureResponse;

/** error class. */
export class CfdDlcError extends Error {
    /**
     * constructor.
     * @param {string} message - Error message.
     * @param {InnerErrorResponse} errorInformation - Error information data.
     * @param {Error} cause - Cause of the error.
     */
    constructor(message: string, errorInformation: InnerErrorResponse, cause: Error);
    /**
     * get error string.
     * @return {string} - string data.
     */
    toString(): string;
    /**
     * get error information.
     * @return {InnerErrorResponse} - InnerErrorResponse data.
     */
    getErrorInformation(): InnerErrorResponse;
    /**
     * get error cause.
     * @return {Error} - Error data.
     */
    getCause(): Error;
}
