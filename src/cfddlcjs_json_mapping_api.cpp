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

std::string JsonMappingApi::CreateCetAdaptorSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateCetAdaptorSignatureRequest,
                        api::json::CreateCetAdaptorSignatureResponse,
                        api::CreateCetAdaptorSignatureRequestStruct,
                        api::CreateCetAdaptorSignatureResponseStruct>(
      request_message, DlcTransactionsApi::CreateCetAdaptorSignature);
}

std::string JsonMappingApi::CreateCetAdaptorSignatures(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::CreateCetAdaptorSignaturesRequest,
                        api::json::CreateCetAdaptorSignaturesResponse,
                        api::CreateCetAdaptorSignaturesRequestStruct,
                        api::CreateCetAdaptorSignaturesResponseStruct>(
      request_message, DlcTransactionsApi::CreateCetAdaptorSignatures);
}

std::string JsonMappingApi::SignCet(const std::string &request_message) {
  return ExecuteJsonApi<api::json::SignCetRequest, api::json::SignCetResponse,
                        api::SignCetRequestStruct, api::SignCetResponseStruct>(
      request_message, DlcTransactionsApi::SignCet);
}

std::string JsonMappingApi::VerifyCetAdaptorSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::VerifyCetAdaptorSignatureRequest,
                        api::json::VerifyCetAdaptorSignatureResponse,
                        api::VerifyCetAdaptorSignatureRequestStruct,
                        api::VerifyCetAdaptorSignatureResponseStruct>(
      request_message, DlcTransactionsApi::VerifyCetAdaptorSignature);
}

std::string JsonMappingApi::VerifyCetAdaptorSignatures(
    const std::string &request_message) {
  return ExecuteJsonApi<api::json::VerifyCetAdaptorSignaturesRequest,
                        api::json::VerifyCetAdaptorSignaturesResponse,
                        api::VerifyCetAdaptorSignaturesRequestStruct,
                        api::VerifyCetAdaptorSignaturesResponseStruct>(
      request_message, DlcTransactionsApi::VerifyCetAdaptorSignatures);
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

void JsonMappingApi::LoadFunctions(RequestFunctionMap *request_map,
                                   ResponseOnlyFunctionMap *response_only_map) {
  if (request_map != nullptr) {
    request_map->emplace("CreateFundTransaction",
                         JsonMappingApi::CreateFundTransaction);
    request_map->emplace("GetRawFundTxSignature",
                         JsonMappingApi::GetRawFundTxSignature);
    request_map->emplace("AddSignatureToFundTransaction",
                         JsonMappingApi::AddSignatureToFundTransaction);
    request_map->emplace("SignFundTransaction",
                         JsonMappingApi::SignFundTransaction);
    request_map->emplace("VerifyFundTxSignature",
                         JsonMappingApi::VerifyFundTxSignature);
    request_map->emplace("CreateRefundTransaction",
                         JsonMappingApi::CreateRefundTransaction);
    request_map->emplace("CreateCet", JsonMappingApi::CreateCet);
    request_map->emplace("CreateDlcTransactions",
                         JsonMappingApi::CreateDlcTransactions);
    request_map->emplace("CreateCetAdaptorSignature",
                         JsonMappingApi::CreateCetAdaptorSignature);
    request_map->emplace("CreateCetAdaptorSignatures",
                         JsonMappingApi::CreateCetAdaptorSignatures);
    request_map->emplace("SignCet", JsonMappingApi::SignCet);
    request_map->emplace("VerifyCetAdaptorSignature",
                         JsonMappingApi::VerifyCetAdaptorSignature);
    request_map->emplace("VerifyCetAdaptorSignatures",
                         JsonMappingApi::VerifyCetAdaptorSignatures);
    request_map->emplace("GetRawRefundTxSignature",
                         JsonMappingApi::GetRawRefundTxSignature);
    request_map->emplace("AddSignaturesToRefundTx",
                         JsonMappingApi::AddSignaturesToRefundTx);
    request_map->emplace("VerifyRefundTxSignature",
                         JsonMappingApi::VerifyRefundTxSignature);
  }
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
