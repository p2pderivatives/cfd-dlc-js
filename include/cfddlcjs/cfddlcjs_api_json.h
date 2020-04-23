// Copyright 2019 CryptoGarage
/**
 * @file cfddlcjs_api_json.h
 *
 * @brief cfd-apiで利用するJsonApiクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_API_JSON_H_
#define CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_API_JSON_H_

#include <string>

#include "cfddlcjs/cfddlcjs_api_common.h"

/**
 * @brief cfdapi名前空間
 */
namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

/**
 * @brief 共通系の関数群クラス
 */
class CFD_DLC_JS_API_EXPORT JsonMappingApi {
 public:
  static std::string CreateFundTransaction(const std::string &request_message);

  static std::string SignFundTransaction(const std::string &request_message);

  static std::string GetRawFundTxSignature(const std::string &request_message);

  static std::string AddSignatureToFundTransaction(
      const std::string &request_message);

  static std::string VerifyFundTxSignature(const std::string &request_message);

  static std::string CreateCet(const std::string &request_message);

  static std::string CreateRefundTransaction(
      const std::string &request_message);

  static std::string CreateClosingTransaction(
      const std::string &request_message);

  static std::string CreateMutualClosingTransaction(
      const std::string &request_message);

  static std::string CreatePenaltyTransaction(
      const std::string &request_message);

  static std::string SignClosingTransaction(const std::string &request_message);

  static std::string CreateDlcTransactions(const std::string &request_message);
  static std::string GetRawCetSignature(const std::string &request_message);
  static std::string GetRawCetSignatures(const std::string &request_message);
  static std::string AddSignaturesToCet(const std::string &request_message);
  static std::string VerifyCetSignature(const std::string &request_message);
  static std::string VerifyCetSignatures(const std::string &request_message);
  static std::string GetRawMutualClosingTxSignature(
      const std::string &request_message);
  static std::string AddSignaturesToMutualClosingTx(
      const std::string &request_message);
  static std::string VerifyMutualClosingTxSignature(
      const std::string &request_message);
  static std::string GetRawRefundTxSignature(
      const std::string &request_message);
  static std::string AddSignaturesToRefundTx(
      const std::string &request_message);
  static std::string VerifyRefundTxSignature(
      const std::string &request_message);
  static std::string SchnorrSign(const std::string &request_message);
  static std::string GetSchnorrPublicNonce(const std::string &request_message);

 private:
  JsonMappingApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

#endif  // CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_API_JSON_H_
