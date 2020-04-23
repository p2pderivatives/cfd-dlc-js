// Copyright 2019 CryptoGarage
/**
 * @file cfddlcjs_transactions.h
 *
 * @brief Create DLC transactions using cfd-dlc-api
 *
 * JSON format API
 */

#ifndef CFDDLCJS_CFDDLCJS_TRANSACTIONS_H_
#define CFDDLCJS_CFDDLCJS_TRANSACTIONS_H_

#include <functional>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_hdwallet.h"
#include "cfdcore/cfdcore_key.h"
#include "cfddlcjs/cfddlcjs_struct.h"

namespace cfd {
namespace dlc {
namespace js {
namespace api {

using cfd::core::ExtPrivkey;
using cfd::core::ExtPubkey;
using cfd::core::Privkey;
using cfd::core::Pubkey;

class DlcTransactionsApi {
 public:
  static CreateFundTransactionResponseStruct CreateFundTransaction(
      const CreateFundTransactionRequestStruct& request);
  static SignFundTransactionResponseStruct SignFundTransaction(
      const SignFundTransactionRequestStruct& request);
  static GetRawFundTxSignatureResponseStruct GetRawFundTxSignature(
      const GetRawFundTxSignatureRequestStruct& request);
  static AddSignatureToFundTransactionResponseStruct
  AddSignatureToFundTransaction(
      const AddSignatureToFundTransactionRequestStruct& request);
  static VerifyFundTxSignatureResponseStruct VerifyFundTxSignature(
      const VerifyFundTxSignatureRequestStruct& request);
  static CreateCetResponseStruct CreateCet(
      const CreateCetRequestStruct& request);
  static CreateRefundTransactionResponseStruct CreateRefundTransaction(
      const CreateRefundTransactionRequestStruct& request);
  static CreateClosingTransactionResponseStruct CreateClosingTransaction(
      const CreateClosingTransactionRequestStruct& request);
  static SignClosingTransactionResponseStruct SignClosingTransaction(
      const SignClosingTransactionRequestStruct& request);
  static CreateDlcTransactionsResponseStruct CreateDlcTransactions(
      const CreateDlcTransactionsRequestStruct& request);
  static CreatePenaltyTransactionResponseStruct CreatePenaltyTransaction(
      const CreatePenaltyTransactionRequestStruct& request);
  static CreateMutualClosingTransactionResponseStruct
  CreateMutualClosingTransaction(
      const CreateMutualClosingTransactionRequestStruct& request);
  static GetRawCetSignatureResponseStruct GetRawCetSignature(
      const GetRawCetSignatureRequestStruct& request);
  static GetRawCetSignaturesResponseStruct GetRawCetSignatures(
      const GetRawCetSignaturesRequestStruct& request);
  static GetRawMutualClosingTxSignatureResponseStruct
  GetRawMutualClosingTxSignature(
      const GetRawMutualClosingTxSignatureRequestStruct& request);
  static GetRawRefundTxSignatureResponseStruct GetRawRefundTxSignature(
      const GetRawRefundTxSignatureRequestStruct& request);
  static AddSignaturesToCetResponseStruct AddSignaturesToCet(
      const AddSignaturesToCetRequestStruct& request);
  static VerifyCetSignatureResponseStruct VerifyCetSignature(
      const VerifyCetSignatureRequestStruct& request);
  static VerifyCetSignaturesResponseStruct VerifyCetSignatures(
      const VerifyCetSignaturesRequestStruct& request);
  static AddSignaturesToMutualClosingTxResponseStruct
  AddSignaturesToMutualClosingTx(
      const AddSignaturesToMutualClosingTxRequestStruct& request);
  static VerifyMutualClosingTxSignatureResponseStruct
  VerifyMutualClosingTxSignature(
      const VerifyMutualClosingTxSignatureRequestStruct& request);
  static AddSignaturesToRefundTxResponseStruct AddSignaturesToRefundTx(
      const AddSignaturesToRefundTxRequestStruct& request);
  static VerifyRefundTxSignatureResponseStruct VerifyRefundTxSignature(
      const VerifyRefundTxSignatureRequestStruct& request);
  static SchnorrSignResponseStruct SchnorrSign(
      const SchnorrSignRequestStruct& request);
  static GetSchnorrPublicNonceResponseStruct GetSchnorrPublicNonce(
      const GetSchnorrPublicNonceRequestStruct& request);

 private:
  DlcTransactionsApi();
  static std::vector<Pubkey> ParsePubkeys(std::vector<std::string> input);
};

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

#endif  // CFDDLCJS_CFDDLCJS_TRANSACTIONS_H_
