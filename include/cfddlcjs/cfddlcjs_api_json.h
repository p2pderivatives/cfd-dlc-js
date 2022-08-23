// Copyright 2019 CryptoGarage
/**
 * @file cfddlcjs_api_json.h
 *
 * @brief Define JsonApi class used in cfd-api.
 *
 * Provide JSON format API.
 */
#ifndef CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_API_JSON_H_
#define CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_API_JSON_H_

#include <functional>
#include <map>
#include <string>

#include "cfddlcjs/cfddlcjs_api_common.h"

/**
 * @brief cfdapi namespace
 */
namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

/// request and response function type.
using RequestFunction = std::function<std::string(const std::string &)>;
/// request and response function map.
using RequestFunctionMap = std::map<std::string, RequestFunction>;
/// response only function type.
using ResponseOnlyFunction = std::function<std::string()>;
/// response only function map.
using ResponseOnlyFunctionMap = std::map<std::string, ResponseOnlyFunction>;

/**
 * @brief Json mapped api class.
 */
class CFD_DLC_JS_API_EXPORT JsonMappingApi {
public:
  /**
   * @brief load functions.
   * @param[out] request_map        request-response function map.
   * @param[out] response_only_map  response-only function map.
   */
  static void LoadFunctions(RequestFunctionMap *request_map,
                            ResponseOnlyFunctionMap *response_only_map);

  static std::string CreateFundTransaction(const std::string &request_message);

  static std::string SignFundTransaction(const std::string &request_message);

  static std::string GetRawFundTxSignature(const std::string &request_message);

  static std::string AddSignatureToFundTransaction(
      const std::string &request_message);

  static std::string VerifyFundTxSignature(const std::string &request_message);

  static std::string CreateCet(const std::string &request_message);

  static std::string CreateRefundTransaction(
      const std::string &request_message);

  static std::string CreateDlcTransactions(const std::string &request_message);
  static std::string CreateCetAdaptorSignature(
      const std::string &request_message);
  static std::string CreateCetAdaptorSignatures(
      const std::string &request_message);
  static std::string SignCet(const std::string &request_message);
  static std::string VerifyCetAdaptorSignature(
      const std::string &request_message);
  static std::string VerifyCetAdaptorSignatures(
      const std::string &request_message);
  static std::string GetRawRefundTxSignature(
      const std::string &request_message);
  static std::string AddSignaturesToRefundTx(
      const std::string &request_message);
  static std::string VerifyRefundTxSignature(
      const std::string &request_message);

 private:
  JsonMappingApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

#endif  // CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_API_JSON_H_
