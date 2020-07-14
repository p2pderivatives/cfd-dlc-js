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
    fundVout?: number;
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
    fundVout?: number;
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
    fundVout?: number;
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

export interface CreateClosingTransactionRequest {
    address: string;
    amount: bigint | number;
    cetTxId: string;
    cetVout?: number;
}

export interface CreateClosingTransactionResponse {
    hex: string;
}

export interface PayoutRequest {
    local: bigint | number;
    remote: bigint | number;
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

export interface TxInRequestA {
    txid: string;
    vout: number;
}

export interface TxOutRequestA {
    amount: bigint | number;
    address: string;
}

export interface TxInRequestA {
    txid: string;
    vout: number;
}

export interface TxOutRequestA {
    amount: bigint | number;
    address: string;
}

export interface CreateFundTransactionRequest {
    localPubkey: string;
    remotePubkey: string;
    outputAmount: bigint | number;
    localInputs: TxInRequestA[];
    localChange: TxOutRequestA;
    remoteInputs: TxInRequestA[];
    remoteChange: TxOutRequestA;
    feeRate: bigint | number;
    optionDest?: string;
    optionPremium?: bigint | number;
}

export interface CreateFundTransactionResponse {
    hex: string;
}

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

export interface CreatePenaltyTransactionRequest {
    finalAddress: string;
    amount: bigint | number;
    cetTxId: string;
    cetVout?: number;
}

export interface CreatePenaltyTransactionResponse {
    hex: string;
}

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
    fundVout?: number;
    localFundPubkey: string;
    remoteFundPubkey: string;
    fundInputAmount: bigint | number;
}

export interface GetRawCetSignatureResponse {
    hex: string;
}

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
    csvDelay: bigint | number;
    oracleSigs: string[];
    cetTxId: string;
    cetVout?: number;
    amount: bigint | number;
}

export interface SignClosingTransactionResponse {
    hex: string;
}

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

export function GetRawCetSignatures(jsonObject: GetRawCetSignaturesRequest): GetRawCetSignaturesResponse;

export function GetRawFundTxSignature(jsonObject: GetRawFundTxSignatureRequest): GetRawFundTxSignatureResponse;

export function GetRawMutualClosingTxSignature(jsonObject: GetRawMutualClosingTxSignatureRequest): GetRawMutualClosingTxSignatureResponse;

export function GetRawRefundTxSignature(jsonObject: GetRawRefundTxSignatureRequest): GetRawRefundTxSignatureResponse;

export function GetSchnorrPublicNonce(jsonObject: GetSchnorrPublicNonceRequest): GetSchnorrPublicNonceResponse;

export function SchnorrSign(jsonObject: SchnorrSignRequest): SchnorrSignResponse;

export function SignClosingTransaction(jsonObject: SignClosingTransactionRequest): SignClosingTransactionResponse;

export function SignFundTransaction(jsonObject: SignFundTransactionRequest): SignFundTransactionResponse;

export function VerifyCetSignature(jsonObject: VerifyCetSignatureRequest): VerifyCetSignatureResponse;

export function VerifyCetSignatures(jsonObject: VerifyCetSignaturesRequest): VerifyCetSignaturesResponse;

export function VerifyFundTxSignature(jsonObject: VerifyFundTxSignatureRequest): VerifyFundTxSignatureResponse;

export function VerifyMutualClosingTxSignature(jsonObject: VerifyMutualClosingTxSignatureRequest): VerifyMutualClosingTxSignatureResponse;

export function VerifyRefundTxSignature(jsonObject: VerifyRefundTxSignatureRequest): VerifyRefundTxSignatureResponse;
