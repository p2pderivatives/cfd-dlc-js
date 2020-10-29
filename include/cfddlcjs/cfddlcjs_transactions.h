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
#include "cfdcore/cfdcore_schnorrsig.h"
#include "cfddlcjs/cfddlcjs_struct.h"

namespace cfd {
namespace dlc {
namespace js {
namespace api {

using cfd::core::ByteData256;
using cfd::core::ExtPrivkey;
using cfd::core::ExtPubkey;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::SchnorrPubkey;
using cfd::core::SchnorrSignature;

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
  static CreateDlcTransactionsResponseStruct CreateDlcTransactions(
      const CreateDlcTransactionsRequestStruct& request);
  static CreateCetAdaptorSignatureResponseStruct CreateCetAdaptorSignature(
      const CreateCetAdaptorSignatureRequestStruct& request);
  static CreateCetAdaptorSignaturesResponseStruct CreateCetAdaptorSignatures(
      const CreateCetAdaptorSignaturesRequestStruct& request);
  static GetRawRefundTxSignatureResponseStruct GetRawRefundTxSignature(
      const GetRawRefundTxSignatureRequestStruct& request);
  static SignCetResponseStruct SignCet(const SignCetRequestStruct& request);
  static VerifyCetAdaptorSignatureResponseStruct VerifyCetAdaptorSignature(
      const VerifyCetAdaptorSignatureRequestStruct& request);
  static VerifyCetAdaptorSignaturesResponseStruct VerifyCetAdaptorSignatures(
      const VerifyCetAdaptorSignaturesRequestStruct& request);
  static AddSignaturesToRefundTxResponseStruct AddSignaturesToRefundTx(
      const AddSignaturesToRefundTxRequestStruct& request);
  static VerifyRefundTxSignatureResponseStruct VerifyRefundTxSignature(
      const VerifyRefundTxSignatureRequestStruct& request);

 private:
  DlcTransactionsApi();
  static std::vector<Pubkey> ParsePubkeys(std::vector<std::string> input);
  static std::vector<SchnorrPubkey> ParseSchnorrPubkeys(
      std::vector<std::string> input);
  static std::vector<SchnorrSignature> ParseSchnorrSignatures(
      std::vector<std::string> input);
  static std::vector<ByteData256> HashMessages(std::vector<std::string> input);
  static std::vector<std::vector<ByteData256>> HashMessages(
      std::vector<MessagesStruct> input);
};

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

#endif  // CFDDLCJS_CFDDLCJS_TRANSACTIONS_H_
