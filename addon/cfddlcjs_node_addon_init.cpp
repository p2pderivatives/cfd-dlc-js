// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <napi.h>  // NOLINT

#include "cfddlcjs/cfddlcjs_common.h"

// using
using Napi::CallbackInfo;
using Napi::Env;
using Napi::Function;
using Napi::Number;
using Napi::Object;
using Napi::String;
using Napi::TypeError;
using Napi::Value;

Object Init(Env env, Object exports) {
  cfd::dlc::js::api::json::InitializeJsonApi(env, &exports);
  return exports;
}

NODE_API_MODULE(cfd_dlc_js, Init)
