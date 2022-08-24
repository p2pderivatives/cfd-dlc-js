// Copyright 2019 CryptoGarage
/**
 * @file cfddlcjs_transaction.cpp
 *
 * @brief cfd-dlc-apiで利用するTransaction作成の実装ファイル
 */

#include "cfddlcjs/cfddlcjs_transactions.h"

#include <sstream>
#include <vector>

#include "cfdcore/cfdcore_key.h"
#include "cfddlc/cfddlc_transactions.h"
#include "cfddlcjs/cfddlcjs_struct.h"
#include "cfddlcjs_internal.h"  // NOLINT

namespace cfd {
namespace dlc {
namespace js {
namespace api {

using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::HashUtil;
using cfd::core::Privkey;
using cfd::core::Txid;
using cfd::core::TxIn;
using cfd::dlc::DlcManager;
using cfd::dlc::DlcOutcome;
using cfd::dlc::DlcTransactions;

TxOut GetChangeOutput(const std::string& address_string, int64_t amount_int) {
  Address address(address_string);
  auto amount = Amount::CreateBySatoshiAmount(amount_int);
  return TxOut(amount, address);
}

NetType ParseNetType(std::string input) {
  if (input == "mainnet") {
    return NetType::kMainnet;
  } else if (input == "testnet") {
    return NetType::kTestnet;
  } else if (input == "regtest") {
    return NetType::kRegtest;
  }

  throw CfdException(CfdError::kCfdIllegalArgumentError,
                     "Unsupported network type");
}

static TxInputInfo ParseTxInRequest(TxInInfoRequestStruct& input_info) {
  Txid txid(input_info.txid);
  if (input_info.redeem_script != "") {
    TxIn input(txid, input_info.vout, 0, Script(input_info.redeem_script));
    return {input, input_info.max_witness_length};
  } else {
    TxIn input(txid, input_info.vout, 0);
    return {input, input_info.max_witness_length};
  }
}

CreateFundTransactionResponseStruct DlcTransactionsApi::CreateFundTransaction(
    const CreateFundTransactionRequestStruct& request) {
  auto call_func = [](const CreateFundTransactionRequestStruct& request)
      -> CreateFundTransactionResponseStruct {
    CreateFundTransactionResponseStruct response;
    auto offer_pubkey = Pubkey(request.offer_pubkey);
    auto offer_change_script_pubkey =
        Script(request.offer_change_script_pubkey);
    auto offer_change_serial_id = request.offer_change_serial_id;
    auto offer_payout_script_pubkey =
        Script(request.offer_payout_script_pubkey);
    auto offer_payout_serial_id = request.offer_payout_serial_id;

    auto accept_pubkey = Pubkey(request.accept_pubkey);
    auto accept_change_script_pubkey =
        Script(request.accept_change_script_pubkey);
    auto accept_change_serial_id = request.offer_change_serial_id;
    auto accept_payout_script_pubkey =
        Script(request.accept_payout_script_pubkey);
    auto accept_payout_serial_id = request.offer_payout_serial_id;
    auto option_premium = Amount::CreateBySatoshiAmount(request.option_premium);
    auto option_dest =
        request.option_dest == "" ? Address() : Address(request.option_dest);

    std::vector<TxInputInfo> offer_inputs;

    for (auto input_request : request.offer_inputs) {
      offer_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<TxInputInfo> accept_inputs;

    for (auto input_request : request.accept_inputs) {
      accept_inputs.push_back(ParseTxInRequest(input_request));
    }

    PartyParams offer_params = {
        offer_pubkey,           offer_change_script_pubkey,
        offer_change_serial_id, offer_payout_script_pubkey,
        offer_payout_serial_id, offer_inputs,
    };

    PartyParams accept_params = {
        accept_pubkey,           offer_change_script_pubkey,
        accept_change_serial_id, offer_payout_script_pubkey,
        accept_payout_serial_id, offer_inputs,
    };

    auto transaction = DlcManager::CreateFundTransaction(
        offer_params, accept_params, request.fee_rate,
        request.fund_output_serial_id, option_dest, option_premium);
    response.hex = transaction.GetHex();
    return response;
  };
  CreateFundTransactionResponseStruct result;
  result = ExecuteStructApi<CreateFundTransactionRequestStruct,
                            CreateFundTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignFundTransactionResponseStruct DlcTransactionsApi::SignFundTransaction(
    const SignFundTransactionRequestStruct& request) {
  auto call_func = [](const SignFundTransactionRequestStruct& request)
      -> SignFundTransactionResponseStruct {
    SignFundTransactionResponseStruct response;
    auto transaction = TransactionController(request.fund_tx_hex);
    auto privkey = Privkey(request.privkey);
    auto prev_tx_id = Txid(request.prev_tx_id);
    auto value = Amount::CreateBySatoshiAmount(request.amount);

    DlcManager::SignFundTransactionInput(&transaction, privkey, prev_tx_id,
                                         request.prev_vout, value);
    response.hex = transaction.GetHex();
    return response;
  };
  SignFundTransactionResponseStruct result;
  result = ExecuteStructApi<SignFundTransactionRequestStruct,
                            SignFundTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawFundTxSignatureResponseStruct DlcTransactionsApi::GetRawFundTxSignature(
    const GetRawFundTxSignatureRequestStruct& request) {
  auto call_func = [](const GetRawFundTxSignatureRequestStruct& request)
      -> GetRawFundTxSignatureResponseStruct {
    GetRawFundTxSignatureResponseStruct response;
    TransactionController fund_tx(request.fund_tx_hex);
    Privkey privkey(request.privkey);
    Txid prev_txid(request.prev_tx_id);
    auto amount = Amount::CreateBySatoshiAmount(request.amount);
    auto signature = DlcManager::GetRawFundingTransactionInputSignature(
        fund_tx, privkey, prev_txid, request.prev_vout, amount);
    response.hex = signature.GetHex();
    return response;
  };
  GetRawFundTxSignatureResponseStruct result;
  result = ExecuteStructApi<GetRawFundTxSignatureRequestStruct,
                            GetRawFundTxSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignatureToFundTransactionResponseStruct
DlcTransactionsApi::AddSignatureToFundTransaction(
    const AddSignatureToFundTransactionRequestStruct& request) {
  auto call_func = [](const AddSignatureToFundTransactionRequestStruct& request)
      -> AddSignatureToFundTransactionResponseStruct {
    AddSignatureToFundTransactionResponseStruct response;
    TransactionController fund_tx(request.fund_tx_hex);
    Pubkey pubkey(request.pubkey);
    Txid prev_txid(request.prev_tx_id);
    ByteData signature(request.signature);
    DlcManager::AddSignatureToFundTransaction(&fund_tx, signature, pubkey,
                                              prev_txid, request.prev_vout);
    response.hex = fund_tx.GetHex();
    return response;
  };
  AddSignatureToFundTransactionResponseStruct result;
  result = ExecuteStructApi<AddSignatureToFundTransactionRequestStruct,
                            AddSignatureToFundTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyFundTxSignatureResponseStruct DlcTransactionsApi::VerifyFundTxSignature(
    const VerifyFundTxSignatureRequestStruct& request) {
  auto call_func = [](const VerifyFundTxSignatureRequestStruct& request)
      -> VerifyFundTxSignatureResponseStruct {
    VerifyFundTxSignatureResponseStruct response;
    TransactionController fund_tx(request.fund_tx_hex);
    ByteData signature(request.signature);
    Pubkey pubkey(request.pubkey);
    Txid prev_txid(request.prev_tx_id);
    auto amount = Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyFundTxSignature(
        fund_tx, signature, pubkey, prev_txid, request.prev_vout, amount);
    return response;
  };
  VerifyFundTxSignatureResponseStruct result;
  result = ExecuteStructApi<VerifyFundTxSignatureRequestStruct,
                            VerifyFundTxSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateCetResponseStruct DlcTransactionsApi::CreateCet(
    const CreateCetRequestStruct& request) {
  auto call_func =
      [](const CreateCetRequestStruct& request) -> CreateCetResponseStruct {
    CreateCetResponseStruct response;
    auto offer_fund_pubkey = Pubkey(request.offer_fund_pubkey);
    auto offer_final_address = Address(request.offer_final_address);
    auto accept_final_address = Address(request.accept_final_address);
    auto offer_payout = Amount::CreateBySatoshiAmount(request.offer_payout);
    auto accept_payout = Amount::CreateBySatoshiAmount(request.accept_payout);
    auto fund_tx_id = Txid(request.fund_tx_id);

    TxOut offer_output(offer_payout, offer_final_address);
    TxOut accept_output(accept_payout, accept_final_address);

    auto transaction =
        DlcManager::CreateCet(offer_output, request.offer_payout_serial_id,
                              accept_output, request.accept_payout_serial_id,
                              fund_tx_id, request.fund_vout, request.lock_time);

    response.hex = transaction.GetHex();
    return response;
  };
  CreateCetResponseStruct result;
  result = ExecuteStructApi<CreateCetRequestStruct, CreateCetResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateRefundTransactionResponseStruct
DlcTransactionsApi::CreateRefundTransaction(
    const CreateRefundTransactionRequestStruct& request) {
  auto call_func = [](const CreateRefundTransactionRequestStruct& request)
      -> CreateRefundTransactionResponseStruct {
    CreateRefundTransactionResponseStruct response;
    auto offer_final_script_pubkey = Script(request.offer_final_script_pubkey);
    auto accept_final_script_pubkey =
        Script(request.accept_final_script_pubkey);
    auto offer_amount = Amount::CreateBySatoshiAmount(request.offer_amount);
    auto accept_amount = Amount::CreateBySatoshiAmount(request.accept_amount);
    auto fund_tx_id = Txid(request.fund_tx_id);

    auto transaction = DlcManager::CreateRefundTransaction(
        offer_final_script_pubkey, accept_final_script_pubkey, offer_amount,
        accept_amount, request.lock_time, fund_tx_id, request.fund_vout);

    response.hex = transaction.GetHex();
    return response;
  };
  CreateRefundTransactionResponseStruct result;
  result = ExecuteStructApi<CreateRefundTransactionRequestStruct,
                            CreateRefundTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateDlcTransactionsResponseStruct DlcTransactionsApi::CreateDlcTransactions(
    const CreateDlcTransactionsRequestStruct& request) {
  auto call_func = [](const CreateDlcTransactionsRequestStruct& request)
      -> CreateDlcTransactionsResponseStruct {
    std::vector<DlcOutcome> outcomes;
    for (auto outcome_request : request.payouts) {
      DlcOutcome outcome;
      outcome.local_payout =
          Amount::CreateBySatoshiAmount(outcome_request.offer);
      outcome.remote_payout =
          Amount::CreateBySatoshiAmount(outcome_request.accept);
      outcomes.push_back(outcome);
    }

    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    Script offer_payout_script_pubkey(request.offer_payout_script_pubkey);
    Script accept_payout_script_pubkey(request.accept_payout_script_pubkey);
    auto offer_input_amount =
        Amount::CreateBySatoshiAmount(request.offer_input_amount);
    auto offer_collateral_amount =
        Amount::CreateBySatoshiAmount(request.offer_collateral_amount);
    auto accept_input_amount =
        Amount::CreateBySatoshiAmount(request.accept_input_amount);
    auto accept_collateral_amount =
        Amount::CreateBySatoshiAmount(request.accept_collateral_amount);
    uint64_t refund_locktime = request.refund_locktime;
    uint64_t fund_lock_time = request.fund_lock_time;
    uint64_t cet_lock_time = request.cet_lock_time;
    auto option_premium = Amount::CreateBySatoshiAmount(request.option_premium);
    auto option_dest =
        request.option_dest == "" ? Address() : Address(request.option_dest);

    std::vector<TxInputInfo> offer_inputs;

    for (auto input_request : request.offer_inputs) {
      offer_inputs.push_back(ParseTxInRequest(input_request));
    }

    std::vector<TxInputInfo> accept_inputs;

    for (auto input_request : request.accept_inputs) {
      accept_inputs.push_back(ParseTxInRequest(input_request));
    }

    uint32_t fee_rate = request.fee_rate;

    Script offer_change_script_pubkey(request.offer_change_script_pubkey);
    Script accept_change_script_pubkey(request.accept_change_script_pubkey);
    PartyParams offer_params = {offer_fund_pubkey,
                                offer_change_script_pubkey,
                                request.offer_change_serial_id,
                                offer_payout_script_pubkey,
                                request.offer_payout_serial_id,
                                offer_inputs,
                                offer_input_amount,
                                offer_collateral_amount};
    PartyParams accept_params = {offer_fund_pubkey,
                                 accept_change_script_pubkey,
                                 request.accept_change_serial_id,
                                 accept_payout_script_pubkey,
                                 request.accept_payout_serial_id,
                                 accept_inputs,
                                 accept_input_amount,
                                 accept_collateral_amount};
    auto transactions = DlcManager::CreateDlcTransactions(
        outcomes, offer_params, accept_params, refund_locktime, fee_rate,
        request.fund_output_serial_id, option_dest, option_premium,
        fund_lock_time, cet_lock_time);
    CreateDlcTransactionsResponseStruct result;
    result.fund_tx_hex = transactions.fund_transaction.GetHex();
    result.refund_tx_hex = transactions.refund_transaction.GetHex();
    for (auto cet : transactions.cets) {
      result.cets_hex.push_back(cet.GetHex());
    }
    result.fund_vout = transactions.fund_vout;
    return result;
  };
  CreateDlcTransactionsResponseStruct result;
  result = ExecuteStructApi<CreateDlcTransactionsRequestStruct,
                            CreateDlcTransactionsResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

std::vector<Pubkey> DlcTransactionsApi::ParsePubkeys(
    std::vector<std::string> input) {
  std::vector<Pubkey> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = Pubkey(input[i]);
  }
  return output;
}

std::vector<SchnorrPubkey> DlcTransactionsApi::ParseSchnorrPubkeys(
    std::vector<std::string> input) {
  std::vector<SchnorrPubkey> output;
  for (int i = 0; i < input.size(); i++) {
    output.push_back(SchnorrPubkey(input[i]));
  }
  return output;
}

std::vector<SchnorrSignature> DlcTransactionsApi::ParseSchnorrSignatures(
    std::vector<std::string> input) {
  std::vector<SchnorrSignature> output;
  for (int i = 0; i < input.size(); i++) {
    output.push_back(SchnorrSignature(input[i]));
  }
  return output;
}

std::vector<ByteData256> DlcTransactionsApi::HashMessages(
    std::vector<std::string> input) {
  std::vector<ByteData256> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = HashUtil::Sha256(input[i]);
  }
  return output;
}

std::vector<std::vector<ByteData256>> DlcTransactionsApi::HashMessages(
    std::vector<MessagesStruct> input) {
  std::vector<std::vector<ByteData256>> output(input.size());
  for (int i = 0; i < input.size(); i++) {
    output[i] = HashMessages(input[i].messages);
  }
  return output;
}

CreateCetAdaptorSignatureResponseStruct
DlcTransactionsApi::CreateCetAdaptorSignature(
    const CreateCetAdaptorSignatureRequestStruct& request) {
  auto call_func = [](const CreateCetAdaptorSignatureRequestStruct& request)
      -> CreateCetAdaptorSignatureResponseStruct {
    CreateCetAdaptorSignatureResponseStruct response;
    TransactionController cet(request.cet_hex);
    Privkey privkey(request.privkey);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);

    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
        offer_fund_pubkey, accept_fund_pubkey);

    auto hashed_msgs = HashMessages(request.messages);

    auto adaptor_signature = DlcManager::CreateCetAdaptorSignature(
        cet, oracle_pubkey, oracle_r_values, privkey, fund_script,
        fund_input_amount, hashed_msgs);
    response.signature = adaptor_signature.GetData().GetHex();
    return response;
  };
  CreateCetAdaptorSignatureResponseStruct result;
  result = ExecuteStructApi<CreateCetAdaptorSignatureRequestStruct,
                            CreateCetAdaptorSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateCetAdaptorSignaturesResponseStruct
DlcTransactionsApi::CreateCetAdaptorSignatures(
    const CreateCetAdaptorSignaturesRequestStruct& request) {
  auto call_func = [](const CreateCetAdaptorSignaturesRequestStruct& request)
      -> CreateCetAdaptorSignaturesResponseStruct {
    CreateCetAdaptorSignaturesResponseStruct response;
    std::vector<TransactionController> cets;
    cets.reserve(request.cets_hex.size());
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);

    for (auto cet_hex : request.cets_hex) {
      cets.push_back(TransactionController(cet_hex));
    }

    auto hashed_messages = HashMessages(request.messages_list);

    Privkey privkey(request.privkey);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
        offer_fund_pubkey, accept_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto adaptor_signatures = DlcManager::CreateCetAdaptorSignatures(
        cets, oracle_pubkey, oracle_r_values, privkey, fund_script,
        fund_input_amount, hashed_messages);
    response.adaptor_signatures.reserve(adaptor_signatures.size());

    for (auto signature : adaptor_signatures) {
      response.adaptor_signatures.push_back(signature.GetData().GetHex());
    }

    return response;
  };
  CreateCetAdaptorSignaturesResponseStruct result;
  result = ExecuteStructApi<CreateCetAdaptorSignaturesRequestStruct,
                            CreateCetAdaptorSignaturesResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignCetResponseStruct DlcTransactionsApi::SignCet(
    const SignCetRequestStruct& request) {
  auto call_func =
      [](const SignCetRequestStruct& request) -> SignCetResponseStruct {
    SignCetResponseStruct response;
    TransactionController cet(request.cet_hex);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    AdaptorSignature adaptor_signature(request.adaptor_signature);
    auto oracle_signatures = ParseSchnorrSignatures(request.oracle_signatures);
    Privkey privkey(request.fund_privkey);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
        offer_fund_pubkey, accept_fund_pubkey);
    Txid fund_tx_id(request.fund_tx_id);
    auto fund_amount = Amount::CreateBySatoshiAmount(request.fund_input_amount);

    DlcManager::SignCet(&cet, adaptor_signature, oracle_signatures, privkey,
                        fund_script, fund_tx_id, request.fund_vout,
                        fund_amount);
    response.hex = cet.GetHex();
    return response;
  };
  SignCetResponseStruct result;
  result = ExecuteStructApi<SignCetRequestStruct, SignCetResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyCetAdaptorSignaturesResponseStruct
DlcTransactionsApi::VerifyCetAdaptorSignatures(
    const VerifyCetAdaptorSignaturesRequestStruct& request) {
  auto call_func = [](const VerifyCetAdaptorSignaturesRequestStruct& request)
      -> VerifyCetAdaptorSignaturesResponseStruct {
    VerifyCetAdaptorSignaturesResponseStruct response;
    size_t nb = request.cets_hex.size();
    if (nb != request.adaptor_signatures.size() ||
        nb != request.messages_list.size()) {
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Number of transactions and number of signatures differs.");
    }

    std::vector<TransactionController> cets;
    std::vector<AdaptorSignature> adaptor_signatures;
    std::vector<std::vector<ByteData256>> msgs;
    cets.reserve(nb);
    adaptor_signatures.reserve(nb);
    msgs.reserve(nb);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);
    auto pubkey =
        request.verify_accept ? accept_fund_pubkey : offer_fund_pubkey;
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);

    for (size_t i = 0; i < nb; i++) {
      cets.push_back(TransactionController(request.cets_hex[i]));
      adaptor_signatures.push_back(
          AdaptorSignature(request.adaptor_signatures[i]));
      msgs.push_back(HashMessages(request.messages_list[i].messages));
    }

    auto fund_script = DlcManager::CreateFundTxLockingScript(
        offer_fund_pubkey, accept_fund_pubkey);

    response.valid = DlcManager::VerifyCetAdaptorSignatures(
        cets, adaptor_signatures, msgs, pubkey, oracle_pubkey, oracle_r_values,
        fund_script, fund_input_amount);
    return response;
  };
  VerifyCetAdaptorSignaturesResponseStruct result;
  result = ExecuteStructApi<VerifyCetAdaptorSignaturesRequestStruct,
                            VerifyCetAdaptorSignaturesResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyCetAdaptorSignatureResponseStruct
DlcTransactionsApi::VerifyCetAdaptorSignature(
    const VerifyCetAdaptorSignatureRequestStruct& request) {
  auto call_func = [](const VerifyCetAdaptorSignatureRequestStruct& request)
      -> VerifyCetAdaptorSignatureResponseStruct {
    VerifyCetAdaptorSignatureResponseStruct response;
    TransactionController cet(request.cet_hex);
    AdaptorSignature adaptor_signature(request.adaptor_signature);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    SchnorrPubkey oracle_pubkey(request.oracle_pubkey);
    auto pubkey =
        request.verify_accept ? accept_fund_pubkey : offer_fund_pubkey;
    auto oracle_r_values = ParseSchnorrPubkeys(request.oracle_r_values);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto fund_script = DlcManager::CreateFundTxLockingScript(
        offer_fund_pubkey, accept_fund_pubkey);
    auto msg = HashMessages(request.messages);

    response.valid = DlcManager::VerifyCetAdaptorSignature(
        adaptor_signature, cet, pubkey, oracle_pubkey, oracle_r_values,
        fund_script, fund_input_amount, msg);
    return response;
  };
  VerifyCetAdaptorSignatureResponseStruct result;
  result = ExecuteStructApi<VerifyCetAdaptorSignatureRequestStruct,
                            VerifyCetAdaptorSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawRefundTxSignatureResponseStruct
DlcTransactionsApi::GetRawRefundTxSignature(
    const GetRawRefundTxSignatureRequestStruct& request) {
  auto call_func = [](const GetRawRefundTxSignatureRequestStruct& request)
      -> GetRawRefundTxSignatureResponseStruct {
    GetRawRefundTxSignatureResponseStruct response;
    TransactionController refund_tx(request.refund_tx_hex);
    Privkey privkey(request.privkey);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto signature = DlcManager::GetRawRefundTxSignature(
        refund_tx, privkey, offer_fund_pubkey, accept_fund_pubkey,
        fund_input_amount, fund_txid, request.fund_vout);
    response.hex = signature.GetHex();
    return response;
  };
  GetRawRefundTxSignatureResponseStruct result;
  result = ExecuteStructApi<GetRawRefundTxSignatureRequestStruct,
                            GetRawRefundTxSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignaturesToRefundTxResponseStruct
DlcTransactionsApi::AddSignaturesToRefundTx(
    const AddSignaturesToRefundTxRequestStruct& request) {
  auto call_func = [](const AddSignaturesToRefundTxRequestStruct& request)
      -> AddSignaturesToRefundTxResponseStruct {
    AddSignaturesToRefundTxResponseStruct response;
    TransactionController refund_tx(request.refund_tx_hex);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto signatures_str = request.signatures;
    std::vector<ByteData> signatures(request.signatures.size());

    for (int i = 0; i < signatures_str.size(); i++) {
      signatures[i] = ByteData(signatures_str[i]);
    }

    DlcManager::AddSignaturesToRefundTx(&refund_tx, offer_fund_pubkey,
                                        accept_fund_pubkey, signatures,
                                        fund_txid, request.fund_vout);
    response.hex = refund_tx.GetHex();
    return response;
  };
  AddSignaturesToRefundTxResponseStruct result;
  result = ExecuteStructApi<AddSignaturesToRefundTxRequestStruct,
                            AddSignaturesToRefundTxResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyRefundTxSignatureResponseStruct
DlcTransactionsApi::VerifyRefundTxSignature(
    const VerifyRefundTxSignatureRequestStruct& request) {
  auto call_func = [](const VerifyRefundTxSignatureRequestStruct& request)
      -> VerifyRefundTxSignatureResponseStruct {
    VerifyRefundTxSignatureResponseStruct response;
    TransactionController refund_tx(request.refund_tx_hex);
    ByteData signature(request.signature);
    Pubkey offer_fund_pubkey(request.offer_fund_pubkey);
    Pubkey accept_fund_pubkey(request.accept_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyRefundTxSignature(
        refund_tx, signature, offer_fund_pubkey, accept_fund_pubkey,
        fund_input_amount, request.verify_accept, fund_txid, request.fund_vout);
    return response;
  };
  VerifyRefundTxSignatureResponseStruct result;
  result = ExecuteStructApi<VerifyRefundTxSignatureRequestStruct,
                            VerifyRefundTxSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
