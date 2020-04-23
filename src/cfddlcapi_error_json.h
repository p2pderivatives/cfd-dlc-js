// Copyright 2019 CryptoGarage
/**
 * @file cfddlcapi_error_json.h
 *
 * @brief JSONマッピングファイル
 */
#ifndef CFD_JS_SRC_CFDAPI_ERROR_JSON_H_
#define CFD_JS_SRC_CFDAPI_ERROR_JSON_H_

#include "cfdcore/cfdcore_exception.h"
#include "cfd_dlc_js_api_json_autogen.h"  // NOLINT
#include "cfddlcjs/cfddlcjs_struct.h"

namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

using cfd::core::CfdException;
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// @formatter:off

// ------------------------------------------------------------------------
// ErrorResponse
// ------------------------------------------------------------------------
/**
 * @brief ErrorResponse
 */
class ErrorResponse : public ErrorResponseBase {
 public:
  /**
   * @brief CfdExceptionをErrorResponseに変換する.
   * @param cfde CfdException object
   * @return ErrorResponse object
   */
  static const ErrorResponse ConvertFromCfdException(const CfdException& cfde);

  /**
   * @brief InnerErrorResponseStructをErrorResponseに変換する.
   * @param[in] data  InnerErrorResponse struct
   * @return ErrorResponse object
   */
  static const ErrorResponse ConvertFromStruct(
      const InnerErrorResponseStruct& data);
};

// @formatter:on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ERROR_JSON_H_
