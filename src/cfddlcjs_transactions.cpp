// Copyright 2019 CryptoGarage
/**
 * @file cfddlcjs_transaction.cpp
 *
 * @brief cfd-dlc-apiで利用するTransaction作成の実装ファイル
 */

#include "cfddlcjs/cfddlcjs_transactions.h"

#include <iostream>
#include <vector>

#include "cfdcore/cfdcore_key.h"
#include "cfddlc/cfddlc_transactions.h"
#include "cfddlc/cfddlc_util.h"
#include "cfddlcjs/cfddlcjs_struct.h"
#include "cfddlcjs_internal.h"  // NOLINT

namespace cfd {
namespace dlc {
namespace js {
namespace api {

using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::ExtPubkey;
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

CreateFundTransactionResponseStruct DlcTransactionsApi::CreateFundTransaction(
    const CreateFundTransactionRequestStruct& request) {
  auto call_func = [](const CreateFundTransactionRequestStruct& request)
      -> CreateFundTransactionResponseStruct {
    CreateFundTransactionResponseStruct response;
    auto local_pubkey = Pubkey(request.local_pubkey);
    auto remote_pubkey = Pubkey(request.remote_pubkey);
    auto output_amount = Amount::CreateBySatoshiAmount(request.output_amount);
    auto option_premium = Amount::CreateBySatoshiAmount(request.option_premium);
    auto option_dest =
        request.option_dest == "" ? Address() : Address(request.option_dest);

    std::vector<TxIn> local_inputs;
    for (TxInRequestStruct txin_req : request.local_inputs) {
      auto txid = Txid(txin_req.txid);
      auto txin = TxIn(txid, txin_req.vout, 0);
      local_inputs.push_back(txin);
    }

    auto local_change_address = Address(request.local_change.address);
    std::vector<TxIn> remote_inputs;
    for (TxInRequestStruct txin_req : request.remote_inputs) {
      auto txid = Txid(txin_req.txid);
      auto txin = TxIn(txid, txin_req.vout, 0);
      remote_inputs.push_back(txin);
    }

    auto local_change = GetChangeOutput(request.local_change.address,
                                        request.local_change.amount);
    auto remote_change = GetChangeOutput(request.remote_change.address,
                                         request.remote_change.amount);
    auto transaction = DlcManager::CreateFundTransaction(
        local_pubkey, remote_pubkey, output_amount, local_inputs, local_change,
        remote_inputs, remote_change, request.fee_rate, option_dest,
        option_premium);
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
    auto local_fund_pubkey = Pubkey(request.local_fund_pubkey);
    auto local_sweep_pubkey = Pubkey(request.local_sweep_pubkey);
    auto oracle_pubkey = Pubkey(request.oracle_pubkey);
    auto oracle_r_points = ParsePubkeys(request.oracle_r_points);
    auto remote_sweep_pubkey = Pubkey(request.remote_sweep_pubkey);
    auto remote_final_address = Address(request.remote_final_address);
    auto local_payout = Amount::CreateBySatoshiAmount(request.local_payout);
    auto remote_payout = Amount::CreateBySatoshiAmount(request.remote_payout);
    auto fund_tx_id = Txid(request.fund_tx_id);

    auto transaction = DlcManager::CreateCet(
        local_fund_pubkey, local_sweep_pubkey, remote_sweep_pubkey,
        remote_final_address, oracle_pubkey, oracle_r_points, request.messages,
        request.csv_delay, local_payout, remote_payout, request.maturity_time,
        request.fee_rate, fund_tx_id, request.fund_vout);

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
    auto local_final_address = Address(request.local_final_address);
    auto remote_final_address = Address(request.remote_final_address);
    auto local_amount = Amount::CreateBySatoshiAmount(request.local_amount);
    auto remote_amount = Amount::CreateBySatoshiAmount(request.remote_amount);
    auto fund_tx_id = Txid(request.fund_tx_id);

    auto transaction = DlcManager::CreateRefundTransaction(
        local_final_address, remote_final_address, local_amount, remote_amount,
        request.lock_time, fund_tx_id, request.fund_vout);

    response.hex = transaction.GetHex();
    return response;
  };
  CreateRefundTransactionResponseStruct result;
  result = ExecuteStructApi<CreateRefundTransactionRequestStruct,
                            CreateRefundTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateClosingTransactionResponseStruct
DlcTransactionsApi::CreateClosingTransaction(
    const CreateClosingTransactionRequestStruct& request) {
  auto call_func = [](const CreateClosingTransactionRequestStruct& request)
      -> CreateClosingTransactionResponseStruct {
    CreateClosingTransactionResponseStruct response;
    auto address = Address(request.address);
    auto amount = Amount::CreateBySatoshiAmount(request.amount);
    auto cet_id = Txid(request.cet_tx_id);

    auto transaction = DlcManager::CreateClosingTransaction(
        address, amount, cet_id, request.cet_vout);
    response.hex = transaction.GetHex();
    return response;
  };
  CreateClosingTransactionResponseStruct result;
  result = ExecuteStructApi<CreateClosingTransactionRequestStruct,
                            CreateClosingTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignClosingTransactionResponseStruct DlcTransactionsApi::SignClosingTransaction(
    const SignClosingTransactionRequestStruct& request) {
  auto call_func = [](const SignClosingTransactionRequestStruct& request)
      -> SignClosingTransactionResponseStruct {
    SignClosingTransactionResponseStruct response;
    auto transaction = TransactionController(request.closing_tx_hex);
    auto privkey = Privkey(request.local_fund_privkey);
    auto local_sweep_pubkey = Pubkey(request.local_sweep_pubkey);
    auto remote_sweep_pubkey = Pubkey(request.remote_sweep_pubkey);
    auto oracle_pubkey = Pubkey(request.oracle_pubkey);
    auto oracle_r_points = ParsePubkeys(request.oracle_r_points);
    auto messages = request.messages;
    uint64_t delay = request.csv_delay;
    std::vector<ByteData> oracle_sigs;
    auto cet_id = Txid(request.cet_tx_id);
    auto value = Amount::CreateBySatoshiAmount(request.amount);

    for (auto sig : request.oracle_sigs) {
      oracle_sigs.push_back(ByteData(sig));
    }

    DlcManager::SignClosingTransactionInput(
        &transaction, privkey, local_sweep_pubkey, remote_sweep_pubkey,
        oracle_pubkey, oracle_r_points, messages, delay, oracle_sigs, value,
        cet_id, request.cet_vout);
    response.hex = transaction.GetHex();
    return response;
  };
  SignClosingTransactionResponseStruct result;
  result = ExecuteStructApi<SignClosingTransactionRequestStruct,
                            SignClosingTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateDlcTransactionsResponseStruct DlcTransactionsApi::CreateDlcTransactions(
    const CreateDlcTransactionsRequestStruct& request) {
  auto call_func = [](const CreateDlcTransactionsRequestStruct& request)
      -> CreateDlcTransactionsResponseStruct {
    std::vector<DlcOutcome> outcomes;
    for (auto outcome_request : request.outcomes) {
      DlcOutcome outcome;
      outcome.local_payout =
          Amount::CreateBySatoshiAmount(outcome_request.local);
      outcome.remote_payout =
          Amount::CreateBySatoshiAmount(outcome_request.remote);
      outcome.messages = outcome_request.messages;
      outcomes.push_back(outcome);
    }

    Pubkey oracle_pubkey(request.oracle_pubkey);
    auto oracle_r_points = ParsePubkeys(request.oracle_r_points);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Pubkey local_sweep_pubkey(request.local_sweep_pubkey);
    Pubkey remote_sweep_pubkey(request.remote_sweep_pubkey);
    Address local_final_address(request.local_final_address);
    Address remote_final_address(request.remote_final_address);
    auto local_input_amount =
        Amount::CreateBySatoshiAmount(request.local_input_amount);
    auto local_collateral_amount =
        Amount::CreateBySatoshiAmount(request.local_collateral_amount);
    auto remote_input_amount =
        Amount::CreateBySatoshiAmount(request.remote_input_amount);
    auto remote_collateral_amount =
        Amount::CreateBySatoshiAmount(request.remote_collateral_amount);
    uint64_t csv_delay = request.csv_delay;
    uint64_t refund_locktime = request.refund_locktime;
    auto option_premium = Amount::CreateBySatoshiAmount(request.option_premium);
    auto option_dest =
        request.option_dest == "" ? Address() : Address(request.option_dest);

    std::vector<TxIn> local_inputs;

    for (auto input_request : request.local_inputs) {
      Txid txid(input_request.txid);
      TxIn input(txid, input_request.vout, 0);
      local_inputs.push_back(input);
    }

    std::vector<TxIn> remote_inputs;

    for (auto input_request : request.remote_inputs) {
      Txid txid(input_request.txid);
      TxIn input(txid, input_request.vout, 0);
      remote_inputs.push_back(input);
    }

    uint32_t fee_rate = request.fee_rate;
    uint32_t maturity_time = request.maturity_time;

    Address local_change_address(request.local_change_address);
    Address remote_change_address(request.remote_change_address);
    auto transactions = DlcManager::CreateDlcTransactions(
        outcomes, oracle_pubkey, oracle_r_points, local_fund_pubkey,
        remote_fund_pubkey, local_sweep_pubkey, remote_sweep_pubkey,
        local_change_address, remote_change_address, local_final_address,
        remote_final_address, local_input_amount, local_collateral_amount,
        remote_input_amount, remote_collateral_amount, refund_locktime,
        csv_delay, local_inputs, remote_inputs, fee_rate, maturity_time,
        option_dest, option_premium);
    CreateDlcTransactionsResponseStruct result;
    result.fund_tx_hex = transactions.fund_transaction.GetHex();
    result.refund_tx_hex = transactions.refund_transaction.GetHex();
    for (size_t i = 0; i < transactions.local_cets.size(); i++) {
      result.local_cets_hex.push_back(transactions.local_cets[i].GetHex());
      result.remote_cets_hex.push_back(transactions.remote_cets[i].GetHex());
    }
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

GetRawCetSignatureResponseStruct DlcTransactionsApi::GetRawCetSignature(
    const GetRawCetSignatureRequestStruct& request) {
  auto call_func = [](const GetRawCetSignatureRequestStruct& request)
      -> GetRawCetSignatureResponseStruct {
    GetRawCetSignatureResponseStruct response;
    TransactionController cet(request.cet_hex);
    Privkey privkey(request.privkey);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto signature = DlcManager::GetRawCetSignature(
        cet, privkey, local_fund_pubkey, remote_fund_pubkey, fund_input_amount,
        fund_txid, request.fund_vout);
    response.hex = signature.GetHex();
    return response;
  };
  GetRawCetSignatureResponseStruct result;
  result = ExecuteStructApi<GetRawCetSignatureRequestStruct,
                            GetRawCetSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawCetSignaturesResponseStruct DlcTransactionsApi::GetRawCetSignatures(
    const GetRawCetSignaturesRequestStruct& request) {
  auto call_func = [](const GetRawCetSignaturesRequestStruct& request)
      -> GetRawCetSignaturesResponseStruct {
    GetRawCetSignaturesResponseStruct response;
    std::vector<TransactionController> cets;
    cets.reserve(request.cets_hex.size());

    for (auto cet_hex : request.cets_hex) {
      cets.push_back(TransactionController(cet_hex));
    }

    Privkey privkey(request.privkey);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto signatures = DlcManager::GetRawCetSignatures(
        cets, privkey, local_fund_pubkey, remote_fund_pubkey, fund_input_amount,
        fund_txid, request.fund_vout);
    response.hex.reserve(signatures.size());

    for (auto signature : signatures) {
      response.hex.push_back(signature.GetHex());
    }

    return response;
  };
  GetRawCetSignaturesResponseStruct result;
  result = ExecuteStructApi<GetRawCetSignaturesRequestStruct,
                            GetRawCetSignaturesResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignaturesToCetResponseStruct DlcTransactionsApi::AddSignaturesToCet(
    const AddSignaturesToCetRequestStruct& request) {
  auto call_func = [](const AddSignaturesToCetRequestStruct& request)
      -> AddSignaturesToCetResponseStruct {
    AddSignaturesToCetResponseStruct response;
    TransactionController cet(request.cet_hex);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto signatures_str = request.signatures;
    std::vector<ByteData> signatures(request.signatures.size());

    for (int i = 0; i < signatures_str.size(); i++) {
      signatures[i] = ByteData(signatures_str[i]);
    }

    DlcManager::AddSignaturesToCet(&cet, local_fund_pubkey, remote_fund_pubkey,
                                   signatures, fund_txid, request.fund_vout);
    response.hex = cet.GetHex();
    return response;
  };
  AddSignaturesToCetResponseStruct result;
  result = ExecuteStructApi<AddSignaturesToCetRequestStruct,
                            AddSignaturesToCetResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyCetSignaturesResponseStruct DlcTransactionsApi::VerifyCetSignatures(
    const VerifyCetSignaturesRequestStruct& request) {
  auto call_func = [](const VerifyCetSignaturesRequestStruct& request)
      -> VerifyCetSignaturesResponseStruct {
    VerifyCetSignaturesResponseStruct response;

    if (request.cets_hex.size() != request.signatures.size()) {
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Number of transactions and number of signatures differs.");
    }

    std::vector<TransactionController> cets;
    std::vector<ByteData> signatures;
    cets.reserve(request.cets_hex.size());
    signatures.reserve(request.signatures.size());
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);

    for (size_t i = 0; i < request.cets_hex.size(); i++) {
      cets.push_back(TransactionController(request.cets_hex[i]));
      signatures.push_back(ByteData(request.signatures[i]));
    }
    response.valid = DlcManager::VerifyCetSignatures(
        cets, signatures, local_fund_pubkey, remote_fund_pubkey,
        fund_input_amount, fund_txid, request.fund_vout, request.verify_remote);
    return response;
  };
  VerifyCetSignaturesResponseStruct result;
  result = ExecuteStructApi<VerifyCetSignaturesRequestStruct,
                            VerifyCetSignaturesResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyCetSignatureResponseStruct DlcTransactionsApi::VerifyCetSignature(
    const VerifyCetSignatureRequestStruct& request) {
  auto call_func = [](const VerifyCetSignatureRequestStruct& request)
      -> VerifyCetSignatureResponseStruct {
    VerifyCetSignatureResponseStruct response;
    TransactionController cet(request.cet_hex);
    ByteData signature(request.signature);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyCetSignature(
        cet, signature, local_fund_pubkey, remote_fund_pubkey,
        fund_input_amount, fund_txid, request.fund_vout, request.verify_remote);
    return response;
  };
  VerifyCetSignatureResponseStruct result;
  result = ExecuteStructApi<VerifyCetSignatureRequestStruct,
                            VerifyCetSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreatePenaltyTransactionResponseStruct
DlcTransactionsApi::CreatePenaltyTransaction(
    const CreatePenaltyTransactionRequestStruct& request) {
  auto call_func = [](const CreatePenaltyTransactionRequestStruct& request)
      -> CreatePenaltyTransactionResponseStruct {
    CreatePenaltyTransactionResponseStruct response;
    Address address(request.final_address);
    Txid cet_tx_id(request.cet_tx_id);
    auto amount = Amount::CreateBySatoshiAmount(request.amount);

    auto tx = DlcManager::CreatePenaltyTransaction(address, amount, cet_tx_id,
                                                   request.cet_vout);
    response.hex = tx.GetHex();
    return response;
  };
  CreatePenaltyTransactionResponseStruct result;
  result = ExecuteStructApi<CreatePenaltyTransactionRequestStruct,
                            CreatePenaltyTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateMutualClosingTransactionResponseStruct
DlcTransactionsApi::CreateMutualClosingTransaction(
    const CreateMutualClosingTransactionRequestStruct& request) {
  auto call_func =
      [](const CreateMutualClosingTransactionRequestStruct& request)
      -> CreateMutualClosingTransactionResponseStruct {
    CreateMutualClosingTransactionResponseStruct response;
    Address local_final_address(request.local_final_address);
    Address remote_final_address(request.remote_final_address);
    Txid fund_txid(request.fund_tx_id);
    auto local_amount = Amount::CreateBySatoshiAmount(request.local_amount);
    auto remote_amount = Amount::CreateBySatoshiAmount(request.remote_amount);

    auto tx = DlcManager::CreateMutualClosingTransaction(
        local_final_address, remote_final_address, local_amount, remote_amount,
        request.fee_rate, fund_txid, request.fund_vout);
    response.hex = tx.GetHex();
    return response;
  };
  CreateMutualClosingTransactionResponseStruct result;
  result = ExecuteStructApi<CreateMutualClosingTransactionRequestStruct,
                            CreateMutualClosingTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetRawMutualClosingTxSignatureResponseStruct
DlcTransactionsApi::GetRawMutualClosingTxSignature(
    const GetRawMutualClosingTxSignatureRequestStruct& request) {
  auto call_func =
      [](const GetRawMutualClosingTxSignatureRequestStruct& request)
      -> GetRawMutualClosingTxSignatureResponseStruct {
    GetRawMutualClosingTxSignatureResponseStruct response;
    TransactionController mutual_closing_hex(request.mutual_closing_hex);
    Privkey privkey(request.privkey);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto signature = DlcManager::GetRawMutualClosingTxSignature(
        mutual_closing_hex, privkey, local_fund_pubkey, remote_fund_pubkey,
        fund_input_amount, fund_txid, request.fund_vout);
    response.hex = signature.GetHex();
    return response;
  };
  GetRawMutualClosingTxSignatureResponseStruct result;
  result = ExecuteStructApi<GetRawMutualClosingTxSignatureRequestStruct,
                            GetRawMutualClosingTxSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignaturesToMutualClosingTxResponseStruct
DlcTransactionsApi::AddSignaturesToMutualClosingTx(
    const AddSignaturesToMutualClosingTxRequestStruct& request) {
  auto call_func =
      [](const AddSignaturesToMutualClosingTxRequestStruct& request)
      -> AddSignaturesToMutualClosingTxResponseStruct {
    AddSignaturesToMutualClosingTxResponseStruct response;
    TransactionController mutual_closing_tx_hex(request.mutual_closing_tx_hex);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto signatures_str = request.signatures;
    std::vector<ByteData> signatures(request.signatures.size());

    for (int i = 0; i < signatures_str.size(); i++) {
      signatures[i] = ByteData(signatures_str[i]);
    }

    DlcManager::AddSignaturesToMutualClosingTx(
        &mutual_closing_tx_hex, local_fund_pubkey, remote_fund_pubkey,
        signatures, fund_txid, request.fund_vout);
    response.hex = mutual_closing_tx_hex.GetHex();
    return response;
  };
  AddSignaturesToMutualClosingTxResponseStruct result;
  result = ExecuteStructApi<AddSignaturesToMutualClosingTxRequestStruct,
                            AddSignaturesToMutualClosingTxResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifyMutualClosingTxSignatureResponseStruct
DlcTransactionsApi::VerifyMutualClosingTxSignature(
    const VerifyMutualClosingTxSignatureRequestStruct& request) {
  auto call_func =
      [](const VerifyMutualClosingTxSignatureRequestStruct& request)
      -> VerifyMutualClosingTxSignatureResponseStruct {
    VerifyMutualClosingTxSignatureResponseStruct response;
    TransactionController mutual_closing(request.mutual_closing_hex);
    ByteData signature(request.signature);
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyMutualClosingTxSignature(
        mutual_closing, signature, local_fund_pubkey, remote_fund_pubkey,
        fund_input_amount, fund_txid, request.fund_vout, request.verify_remote);
    return response;
  };
  VerifyMutualClosingTxSignatureResponseStruct result;
  result = ExecuteStructApi<VerifyMutualClosingTxSignatureRequestStruct,
                            VerifyMutualClosingTxSignatureResponseStruct>(
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
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);
    auto signature = DlcManager::GetRawRefundTxSignature(
        refund_tx, privkey, local_fund_pubkey, remote_fund_pubkey,
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
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto signatures_str = request.signatures;
    std::vector<ByteData> signatures(request.signatures.size());

    for (int i = 0; i < signatures_str.size(); i++) {
      signatures[i] = ByteData(signatures_str[i]);
    }

    DlcManager::AddSignaturesToRefundTx(&refund_tx, local_fund_pubkey,
                                        remote_fund_pubkey, signatures,
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
    Pubkey local_fund_pubkey(request.local_fund_pubkey);
    Pubkey remote_fund_pubkey(request.remote_fund_pubkey);
    Txid fund_txid(request.fund_tx_id);
    auto fund_input_amount =
        Amount::CreateBySatoshiAmount(request.fund_input_amount);

    response.valid = DlcManager::VerifyRefundTxSignature(
        refund_tx, signature, local_fund_pubkey, remote_fund_pubkey,
        fund_input_amount, request.verify_remote, fund_txid, request.fund_vout);
    return response;
  };
  VerifyRefundTxSignatureResponseStruct result;
  result = ExecuteStructApi<VerifyRefundTxSignatureRequestStruct,
                            VerifyRefundTxSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SchnorrSignResponseStruct DlcTransactionsApi::SchnorrSign(
    const SchnorrSignRequestStruct& request) {
  auto call_func =
      [](const SchnorrSignRequestStruct& request) -> SchnorrSignResponseStruct {
    SchnorrSignResponseStruct response;
    Privkey privkey(request.privkey);
    Privkey k_value(request.k_value);

    auto signature = DlcUtil::SchnorrSign(privkey, k_value, request.message);
    response.hex = signature.GetHex();
    return response;
  };
  SchnorrSignResponseStruct result;
  result =
      ExecuteStructApi<SchnorrSignRequestStruct, SchnorrSignResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

GetSchnorrPublicNonceResponseStruct DlcTransactionsApi::GetSchnorrPublicNonce(
    const GetSchnorrPublicNonceRequestStruct& request) {
  auto call_func = [](const GetSchnorrPublicNonceRequestStruct& request)
      -> GetSchnorrPublicNonceResponseStruct {
    GetSchnorrPublicNonceResponseStruct response;
    Privkey k_value(request.k_value);

    auto public_nonce = DlcUtil::GetSchnorrPublicNonce(k_value);
    response.hex = public_nonce.GetHex();
    return response;
  };
  GetSchnorrPublicNonceResponseStruct result;
  result = ExecuteStructApi<GetSchnorrPublicNonceRequestStruct,
                            GetSchnorrPublicNonceResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
