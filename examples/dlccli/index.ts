import { Client, ClientOption } from "bitcoin-simple-rpc";
import inquirer from "inquirer";
import datepicker from "inquirer-datepicker";
import util from "util";
import { v4 as uuidv4 } from "uuid";
import Amount from "./models/Amount";
import Contract from "./models/Contract";
import DlcParty from "./models/DlcParty";
import OfferMessage from "./models/OfferMessage";
import Oracle from "./models/Oracle";
import Payout from "./models/Payout";
import { InitialInputNames, InitialInputs } from "./prompts/Initial";
import { OutcomeInputNames, OutcomeInputs } from "./prompts/Outcomes";

export function CreateWalletClient(walletName: string) {
  const clientConfig: ClientOption = {
    baseURL: `http://localhost:18443/wallet/${walletName}`,
  };
  clientConfig.auth = { username: "user", password: "pass" };

  return new Client(clientConfig);
}

const aliceClient = CreateWalletClient("alice");
const bobClient = CreateWalletClient("bob");
const alice = new DlcParty(aliceClient);
const bob = new DlcParty(bobClient);
const oracle = new Oracle("Olivia");

const contract = new Contract();
contract.id = uuidv4();
contract.oracleInfo = oracle.GetOracleInfo();

// To be able toinput dates
inquirer.registerPrompt("datepicker", datepicker);

async function GetInitialInputs() {
  return inquirer.prompt(InitialInputs).then(async (values) => {
    contract.localCollateral = Amount.FromBitcoin(
      values[InitialInputNames.LocalCollateral]
    );
    contract.remoteCollateral = Amount.FromBitcoin(
      values[InitialInputNames.RemoteCollateral]
    );
    contract.feeRate = values[InitialInputNames.FeeRate];
    contract.refundLockTime =
      Date.parse(values[InitialInputNames.Refund]) / 1000;
  });
}

async function GetOutcomes() {
  const values = await inquirer.prompt(OutcomeInputs);
  const addMore = values[OutcomeInputNames.AddMore];
  const localAmount = Amount.FromBitcoin(
    values[OutcomeInputNames.LocalPayout]
  );
  const remoteAmount = Amount.FromBitcoin(
    values[OutcomeInputNames.RemotePayout]
  );
  const message = values[OutcomeInputNames.Message];
  const payout = new Payout(localAmount, remoteAmount);
  contract.payouts.push(payout);
  contract.messages.push(message);

  if (addMore) {
    await GetOutcomes();
  }
}

async function ProposeContractToBob(offerMessage: OfferMessage) {
  console.log("Contract received: ");
  console.log(util.inspect(offerMessage, false, null, true));
  const name = "Accept";
  const values = await inquirer.prompt([
    {
      type: "confirm",
      name,
      message: "Do you want to accept this contract?",
      default: false,
    },
  ]);
  return values[name];
}

async function DecideOutcome(): Promise<{ message: string; index: number }> {
  const name = "Outcome choice";
  const answers = await inquirer.prompt([
    {
      name,
      message: "Choose the outcome of the event",
      type: "list",
      choices: contract.messages.map((message, index) => {
        return {
          name: message,
          short: message,
          value: { message, index },
        };
      }),
    },
  ]);
  return answers[name];
}

async function DecideClosing(message: string, index: number): Promise<number> {
  const name = "Closing choice";
  const answers = await inquirer.prompt([
    {
      name,
      message: "Choose the closing method",
      type: "list",
      choices: [
        {
          name: "Alice closes",
          value: 0,
        },
        {
          name: "Bob closes",
          value: 1,
        },
      ],
    },
  ]);
  return answers["Closing choice"];
}

async function PrintBalances() {
  const aliceBalance = await alice.walletClient.getBalance("*", 1);
  const bobBalance = await bob.walletClient.getBalance("*", 1);
  console.log("Alice balance: ", aliceBalance);
  console.log("Bob balance: ", bobBalance);
}

alice.GenerateBlocks(101).then(async () => {
  await PrintBalances();
  await GetInitialInputs();
  await GetOutcomes();
  const offerMessage = await alice.InitiateContract(contract);
  const accepted = await ProposeContractToBob(offerMessage);
  if (accepted) {
    const acceptMessage = await bob.OnOfferMessage(offerMessage);
    const signMessage = alice.OnAcceptMessage(acceptMessage);
    await bob.OnSignMessage(signMessage);
    const { message, index } = await DecideOutcome();
    const signature = oracle.GetSignature(message);
    const closingType = await DecideClosing(message, index);
    if (closingType === 0) {
      await alice.SignAndBroadcastCet(index, signature);
    } else {
      await bob.SignAndBroadcastCet(index, signature);
    }
  }
  await PrintBalances();
});
