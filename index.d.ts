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

export interface AddSignaturesToCetRequest {
    cetHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToCetResponse {
    hex: string;
}

export interface AddSignaturesToMutualClosingTxRequest {
    mutualClosingTxHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToMutualClosingTxResponse {
    hex: string;
}

export interface AddSignaturesToRefundTxRequest {
    refundTxHex: string;
    signatures: string[];
    fundTxId: string;
    fundVout: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
}

export interface AddSignaturesToRefundTxResponse {
    hex: string;
}

export interface CreateCetRequest {
    localFundPubkey: string;
    localSweepPubkey: string;
    remoteSweepPubkey: string;
    remoteFinalAddress: string;
    oraclePubkey: string;
    oracleRPoints: string[];
    messages: string[];
    delay: number;
    localPayout: bigint;
    remotePayout: bigint;
    fundTxId: string;
    fundVout: number;
    maturityTime: bigint;
}

export interface CreateCetResponse {
    hex: string;
}

export interface CreateClosingTransactionRequest {
    address: string;
    amount: bigint;
    cetTxId: string;
    cetVout: number;
}

export interface CreateClosingTransactionResponse {
    hex: string;
}

export interface PayoutRequest {
    local: bigint;
    remote: bigint;
    messages: string[];
}

export interface TxInRequest {
    txid: string;
    vout: number;
}

export interface TxInRequest {
    txid: string;
    vout: number;
}

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
    localInputAmount: bigint;
    localCollateralAmount: bigint;
    remoteInputAmount: bigint;
    remoteCollateralAmount: bigint;
    timeout: number;
    localInputs: TxInRequest[];
    localChangeAddress: string;
    remoteInputs: TxInRequest[];
    remoteChangeAddress: string;
    feeRate: number;
    maturityTime: bigint;
}

export interface CreateDlcTransactionsResponse {
    fundTxHex: string;
    closingCetsHex: string[];
    refundTxHex: string;
}

export interface TxInRequestA {
    txid: string;
    vout: number;
}

export interface TxOutRequestA {
    amount: bigint;
    address: string;
}

export interface TxInRequestA {
    txid: string;
    vout: number;
}

export interface TxOutRequestA {
    amount: bigint;
    address: string;
}

export interface CreateFundTransactionRequest {
    localPubkey: string;
    remotePubkey: string;
    outputAmount: bigint;
    localInputs: TxInRequestA[];
    localChange: TxOutRequestA;
    remoteInputs: TxInRequestA[];
    remoteChange: TxOutRequestA;
    nLockTime: bigint;
}

export interface CreateFundTransactionResponse {
    hex: string;
}

export interface CreateMutualClosingTransactionRequest {
    localFinalAddress: string;
    remoteFinalAddress: string;
    localAmount: bigint;
    remoteAmount: bigint;
    fundTxId: string;
    fundVout: number;
}

export interface CreateMutualClosingTransactionResponse {
    hex: string;
}

export interface CreatePenaltyTransactionRequest {
    finalAddress: string;
    amount: bigint;
    cetTxId: string;
    cetVout: number;
}

export interface CreatePenaltyTransactionResponse {
    hex: string;
}

export interface CreateRefundTransactionRequest {
    localFinalAddress: string;
    remoteFinalAddress: string;
    localAmount: bigint;
    remoteAmount: bigint;
    lockTime: bigint;
    fundTxId: string;
    fundVout: number;
}

export interface CreateRefundTransactionResponse {
    hex: string;
}

export interface InnerErrorResponse {
    code: number;
    type: string;
    message: string;
}

export interface ErrorResponse {
    error: InnerErrorResponse;
}

export interface GetRawCetSignatureRequest {
    cetHex: string;
    privkey: string;
    fundTxId: string;
    fundVout: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint;
}

export interface GetRawCetSignatureResponse {
    hex: string;
}

export interface GetRawFundTxSignatureRequest {
    fundTxHex: string;
    privkey: string;
    prevTxId: string;
    prevVout: number;
    amount: bigint;
}

export interface GetRawFundTxSignatureResponse {
    hex: string;
}

export interface GetRawMutualClosingTxSignatureRequest {
    mutualClosingHex: string;
    privkey: string;
    fundTxId: string;
    fundVout: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint;
}

export interface GetRawMutualClosingTxSignatureResponse {
    hex: string;
}

export interface GetRawRefundTxSignatureRequest {
    refundTxHex: string;
    privkey: string;
    fundTxId: string;
    fundVout: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint;
}

export interface GetRawRefundTxSignatureResponse {
    hex: string;
}

export interface GetSchnorrPublicNonceRequest {
    kValue: string;
}

export interface GetSchnorrPublicNonceResponse {
    hex: string;
}

export interface SchnorrSignRequest {
    privkey: string;
    kValue: string;
    message: string;
}

export interface SchnorrSignResponse {
    hex: string;
}

export interface SignClosingTransactionRequest {
    closingTxHex: string;
    localFundPrivkey: string;
    localSweepPubkey: string;
    remoteSweepPubkey: string;
    oraclePubkey: string;
    oracleRPoints: string[];
    messages: string[];
    delay: bigint;
    oracleSigs: string[];
    cetTxId: string;
    cetVout: number;
    amount: bigint;
}

export interface SignClosingTransactionResponse {
    hex: string;
}

export interface SignFundTransactionRequest {
    fundTxHex: string;
    privkey: string;
    prevTxId: string;
    prevVout: number;
    amount: bigint;
}

export interface SignFundTransactionResponse {
    hex: string;
}

export interface VerifyCetSignatureRequest {
    cetHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout: number;
    fundInputAmount: bigint;
    verifyRemote: boolean;
}

export interface VerifyCetSignatureResponse {
    valid: boolean;
}

export interface VerifyFundTxSignatureRequest {
    fundTxHex: string;
    signature: string;
    pubkey: string;
    prevTxId: string;
    prevVout: number;
    fundInputAmount: bigint;
}

export interface VerifyFundTxSignatureResponse {
    valid: boolean;
}

export interface VerifyMutualClosingTxSignatureRequest {
    cetHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout: number;
    fundInputAmount: bigint;
    verifyRemote: boolean;
}

export interface VerifyMutualClosingTxSignatureResponse {
    valid: boolean;
}

export interface VerifyRefundTxSignatureRequest {
    refundTxHex: string;
    signature: string;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundTxId: string;
    fundVout: number;
    fundInputAmount: bigint;
    verifyRemote: boolean;
}

export interface VerifyRefundTxSignatureResponse {
    valid: boolean;
}

export function AddSignatureToFundTransaction(jsonObject: AddSignatureToFundTransactionRequest): AddSignatureToFundTransactionResponse;

export function AddSignaturesToCet(jsonObject: AddSignaturesToCetRequest): AddSignaturesToCetResponse;

export function AddSignaturesToMutualClosingTx(jsonObject: AddSignaturesToMutualClosingTxRequest): AddSignaturesToMutualClosingTxResponse;

export function AddSignaturesToRefundTx(jsonObject: AddSignaturesToRefundTxRequest): AddSignaturesToRefundTxResponse;

export function CreateCet(jsonObject: CreateCetRequest): CreateCetResponse;

export function CreateClosingTransaction(jsonObject: CreateClosingTransactionRequest): CreateClosingTransactionResponse;

export function CreateDlcTransactions(jsonObject: CreateDlcTransactionsRequest): CreateDlcTransactionsResponse;

export function CreateFundTransaction(jsonObject: CreateFundTransactionRequest): CreateFundTransactionResponse;

export function CreateMutualClosingTransaction(jsonObject: CreateMutualClosingTransactionRequest): CreateMutualClosingTransactionResponse;

export function CreatePenaltyTransaction(jsonObject: CreatePenaltyTransactionRequest): CreatePenaltyTransactionResponse;

export function CreateRefundTransaction(jsonObject: CreateRefundTransactionRequest): CreateRefundTransactionResponse;

export function GetRawCetSignature(jsonObject: GetRawCetSignatureRequest): GetRawCetSignatureResponse;

export function GetRawFundTxSignature(jsonObject: GetRawFundTxSignatureRequest): GetRawFundTxSignatureResponse;

export function GetRawMutualClosingTxSignature(jsonObject: GetRawMutualClosingTxSignatureRequest): GetRawMutualClosingTxSignatureResponse;

export function GetRawRefundTxSignature(jsonObject: GetRawRefundTxSignatureRequest): GetRawRefundTxSignatureResponse;

export function GetSchnorrPublicNonce(jsonObject: GetSchnorrPublicNonceRequest): GetSchnorrPublicNonceResponse;

export function SchnorrSign(jsonObject: SchnorrSignRequest): SchnorrSignResponse;

export function SignClosingTransaction(jsonObject: SignClosingTransactionRequest): SignClosingTransactionResponse;

export function SignFundTransaction(jsonObject: SignFundTransactionRequest): SignFundTransactionResponse;

export function VerifyCetSignature(jsonObject: VerifyCetSignatureRequest): VerifyCetSignatureResponse;

export function VerifyFundTxSignature(jsonObject: VerifyFundTxSignatureRequest): VerifyFundTxSignatureResponse;

export function VerifyMutualClosingTxSignature(jsonObject: VerifyMutualClosingTxSignatureRequest): VerifyMutualClosingTxSignatureResponse;

export function VerifyRefundTxSignature(jsonObject: VerifyRefundTxSignatureRequest): VerifyRefundTxSignatureResponse;
