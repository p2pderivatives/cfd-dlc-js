// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_utility.cpp
 *
 * @brief cfd-apiで利用する共通系クラスの実装ファイル
 */
#include <string>
#include <vector>

#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_exception.h"
#include "cfdcore/cfdcore_logger.h"
#include "cfdcore/cfdcore_util.h"

#include "cfd/cfd_common.h"
#include "cfddlcjs_internal.h"  // NOLINT

namespace cfd {
namespace dlc {
namespace js {
namespace api {

using cfd::core::CfdException;

// 実体定義用(多重定義防止のためCPP側に定義)
InnerErrorResponseStruct ConvertCfdExceptionToStruct(const CfdException& cfde) {
  InnerErrorResponseStruct result;
  result.code = cfde.GetErrorCode();
  result.type = cfde.GetErrorType();
  result.message = cfde.what();
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
