// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_json_mapping_api.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <functional>
#include <string>

#include "cfd_dlc_js_api_json_autogen.h"  // NOLINT
#include "cfdcore/cfdcore_exception.h"
#include "cfddlcapi_error_json.h"  // NOLINT
#include "cfddlcjs/cfddlcjs_api_common.h"
#include "cfddlcjs/cfddlcjs_api_json.h"
#include "cfddlcjs/cfddlcjs_transactions.h"

// using

// -----------------------------------------------------------------------------
// API wrapper for node addon
// -----------------------------------------------------------------------------

namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::dlc::js::api::json::ErrorResponse;

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] request_message     リクエストされたjson文字列
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename RequestType, typename ResponseType,
          typename RequestStructType, typename ResponseStructType>
std::string ExecuteJsonApi(
    const std::string &request_message,
    std::function<ResponseStructType(const RequestStructType &)>
        call_function) {
  // リクエストjson_strから、モデルへ変換
  RequestType req;
  try {
    req.Deserialize(request_message);
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    return res.Serialize();
  } catch (...) {
    CfdException ex(CfdError::kCfdOutOfRangeError,
                    "JSON value convert error. Value out of range.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
  }
  RequestStructType request = req.ConvertToStruct();
  ResponseStructType response = call_function(request);
  std::string json_message;
  if (response.error.code == 0) {
    ResponseType res;
    res.ConvertFromStruct(response);
    json_message = res.Serialize();
  } else {
    json_message = ErrorResponse::ConvertFromStruct(response.error).Serialize();
  }

  // utf-8
  return json_message;
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

std::string JsonMappingApi::CreateFundTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateFundTransactionRequest,
                        api::json::CreateFundTransactionResponse,
                        api::CreateFundTransactionRequestStruct,
                        api::CreateFundTransactionResponseStruct>(
      request_message, DlcTransactionsApi::CreateFundTransaction);
}

std::string JsonMappingApi::GetRawFundTxSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::GetRawFundTxSignatureRequest,
                        api::json::GetRawFundTxSignatureResponse,
                        api::GetRawFundTxSignatureRequestStruct,
                        api::GetRawFundTxSignatureResponseStruct>(
      request_message, DlcTransactionsApi::GetRawFundTxSignature);
}

std::string JsonMappingApi::AddSignatureToFundTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::AddSignatureToFundTransactionRequest,
                        api::json::AddSignatureToFundTransactionResponse,
                        api::AddSignatureToFundTransactionRequestStruct,
                        api::AddSignatureToFundTransactionResponseStruct>(
      request_message, DlcTransactionsApi::AddSignatureToFundTransaction);
}

std::string JsonMappingApi::SignFundTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::SignFundTransactionRequest,
                        api::json::SignFundTransactionResponse,
                        api::SignFundTransactionRequestStruct,
                        api::SignFundTransactionResponseStruct>(
      request_message, DlcTransactionsApi::SignFundTransaction);
}

std::string JsonMappingApi::VerifyFundTxSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::VerifyFundTxSignatureRequest,
                        api::json::VerifyFundTxSignatureResponse,
                        api::VerifyFundTxSignatureRequestStruct,
                        api::VerifyFundTxSignatureResponseStruct>(
      request_message, DlcTransactionsApi::VerifyFundTxSignature);
}

std::string JsonMappingApi::CreateRefundTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateRefundTransactionRequest,
                        api::json::CreateRefundTransactionResponse,
                        api::CreateRefundTransactionRequestStruct,
                        api::CreateRefundTransactionResponseStruct>(
      request_message, DlcTransactionsApi::CreateRefundTransaction);
}

std::string JsonMappingApi::CreateCet(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateCetRequest, api::json::CreateCetResponse,
      api::CreateCetRequestStruct, api::CreateCetResponseStruct>(
      request_message, DlcTransactionsApi::CreateCet);
}

std::string JsonMappingApi::CreateDlcTransactions(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateDlcTransactionsRequest,
                        api::json::CreateDlcTransactionsResponse,
                        api::CreateDlcTransactionsRequestStruct,
                        api::CreateDlcTransactionsResponseStruct>(
      request_message, DlcTransactionsApi::CreateDlcTransactions);
}

std::string JsonMappingApi::CreateClosingTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateClosingTransactionRequest,
                        api::json::CreateClosingTransactionResponse,
                        api::CreateClosingTransactionRequestStruct,
                        api::CreateClosingTransactionResponseStruct>(
      request_message, DlcTransactionsApi::CreateClosingTransaction);
}

std::string JsonMappingApi::CreatePenaltyTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreatePenaltyTransactionRequest,
                        api::json::CreatePenaltyTransactionResponse,
                        api::CreatePenaltyTransactionRequestStruct,
                        api::CreatePenaltyTransactionResponseStruct>(
      request_message, DlcTransactionsApi::CreatePenaltyTransaction);
}

std::string JsonMappingApi::CreateMutualClosingTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateMutualClosingTransactionRequest,
                        api::json::CreateMutualClosingTransactionResponse,
                        api::CreateMutualClosingTransactionRequestStruct,
                        api::CreateMutualClosingTransactionResponseStruct>(
      request_message, DlcTransactionsApi::CreateMutualClosingTransaction);
}

std::string JsonMappingApi::SignClosingTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::SignClosingTransactionRequest,
                        api::json::SignClosingTransactionResponse,
                        api::SignClosingTransactionRequestStruct,
                        api::SignClosingTransactionResponseStruct>(
      request_message, DlcTransactionsApi::SignClosingTransaction);
}

std::string JsonMappingApi::GetRawCetSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::GetRawCetSignatureRequest,
                        api::json::GetRawCetSignatureResponse,
                        api::GetRawCetSignatureRequestStruct,
                        api::GetRawCetSignatureResponseStruct>(
      request_message, DlcTransactionsApi::GetRawCetSignature);
}

std::string JsonMappingApi::GetRawMutualClosingTxSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::GetRawMutualClosingTxSignatureRequest,
                        api::json::GetRawMutualClosingTxSignatureResponse,
                        api::GetRawMutualClosingTxSignatureRequestStruct,
                        api::GetRawMutualClosingTxSignatureResponseStruct>(
      request_message, DlcTransactionsApi::GetRawMutualClosingTxSignature);
}

std::string JsonMappingApi::AddSignaturesToCet(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::AddSignaturesToCetRequest,
                        api::json::AddSignaturesToCetResponse,
                        api::AddSignaturesToCetRequestStruct,
                        api::AddSignaturesToCetResponseStruct>(
      request_message, DlcTransactionsApi::AddSignaturesToCet);
}

std::string JsonMappingApi::VerifyCetSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::VerifyCetSignatureRequest,
                        api::json::VerifyCetSignatureResponse,
                        api::VerifyCetSignatureRequestStruct,
                        api::VerifyCetSignatureResponseStruct>(
      request_message, DlcTransactionsApi::VerifyCetSignature);
}

std::string JsonMappingApi::AddSignaturesToMutualClosingTx(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::AddSignaturesToMutualClosingTxRequest,
                        api::json::AddSignaturesToMutualClosingTxResponse,
                        api::AddSignaturesToMutualClosingTxRequestStruct,
                        api::AddSignaturesToMutualClosingTxResponseStruct>(
      request_message, DlcTransactionsApi::AddSignaturesToMutualClosingTx);
}

std::string JsonMappingApi::VerifyMutualClosingTxSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::VerifyMutualClosingTxSignatureRequest,
                        api::json::VerifyMutualClosingTxSignatureResponse,
                        api::VerifyMutualClosingTxSignatureRequestStruct,
                        api::VerifyMutualClosingTxSignatureResponseStruct>(
      request_message, DlcTransactionsApi::VerifyMutualClosingTxSignature);
}

std::string JsonMappingApi::GetRawRefundTxSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::GetRawRefundTxSignatureRequest,
                        api::json::GetRawRefundTxSignatureResponse,
                        api::GetRawRefundTxSignatureRequestStruct,
                        api::GetRawRefundTxSignatureResponseStruct>(
      request_message, DlcTransactionsApi::GetRawRefundTxSignature);
}

std::string JsonMappingApi::AddSignaturesToRefundTx(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::AddSignaturesToRefundTxRequest,
                        api::json::AddSignaturesToRefundTxResponse,
                        api::AddSignaturesToRefundTxRequestStruct,
                        api::AddSignaturesToRefundTxResponseStruct>(
      request_message, DlcTransactionsApi::AddSignaturesToRefundTx);
}

std::string JsonMappingApi::VerifyRefundTxSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::VerifyRefundTxSignatureRequest,
                        api::json::VerifyRefundTxSignatureResponse,
                        api::VerifyRefundTxSignatureRequestStruct,
                        api::VerifyRefundTxSignatureResponseStruct>(
      request_message, DlcTransactionsApi::VerifyRefundTxSignature);
}

std::string JsonMappingApi::SchnorrSign(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::SchnorrSignRequest, api::json::SchnorrSignResponse,
      api::SchnorrSignRequestStruct, api::SchnorrSignResponseStruct>(
      request_message, DlcTransactionsApi::SchnorrSign);
}

std::string JsonMappingApi::GetSchnorrPublicNonce(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::GetSchnorrPublicNonceRequest,
                        api::json::GetSchnorrPublicNonceResponse,
                        api::GetSchnorrPublicNonceRequestStruct,
                        api::GetSchnorrPublicNonceResponseStruct>(
      request_message, DlcTransactionsApi::GetSchnorrPublicNonce);
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
