import util from "util";
import inquirer from "inquirer";
import { InitialInputs, InitialInputNames } from "./prompts/Initial";
import { OutcomeInputs, OutcomeInputNames } from "./prompts/Outcomes";
import Contract from "./models/Contract";
import datepicker from "inquirer-datepicker";
import Outcome from "./models/Outcome";
import OfferMessage from "./models/OfferMessage";
import Oracle from "./models/Oracle";
import DlcParty from "./models/DlcParty";
import Amount from "./models/Amount";
import { v4 as uuidv4 } from "uuid";
import Client, { ClientConstructorOption } from "bitcoin-core";

export function CreateWalletClient(walletName: string) {
  const clientConfig: ClientConstructorOption = {};
  clientConfig.network = "regtest";
  clientConfig.username = "user";
  clientConfig.password = "pass";
  clientConfig.port = 18443;
  clientConfig.useWalletURL = true;
  clientConfig.wallet = walletName;

  return new Client(clientConfig);
}

const aliceClient = CreateWalletClient("alice");
const bobClient = CreateWalletClient("bob");
const alice = new DlcParty(aliceClient, "alice");
const bob = new DlcParty(bobClient, "bob");
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
    contract.maturityTime = values[InitialInputNames.Maturity];
    contract.refundLockTime =
      Date.parse(values[InitialInputNames.Refund]) / 1000;
    contract.cetCsvDelay = values[InitialInputNames.CsvDelay];
  });
}

async function GetOutcomes() {
  const values = await inquirer.prompt(OutcomeInputs);
  const addMore = values[OutcomeInputNames.AddMore];
  const localAmount = Amount.FromBitcoin(values[OutcomeInputNames.LocalPayout]);
  const remoteAmount = Amount.FromBitcoin(
    values[OutcomeInputNames.RemotePayout]
  );
  const message = values[OutcomeInputNames.Message];
  const outcome = new Outcome(message, localAmount, remoteAmount);
  contract.outcomes.push(outcome);

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

async function DecideOutcome(): Promise<{ outcome: Outcome; index: number }> {
  const name = "Outcome choice";
  const answers = await inquirer.prompt([
    {
      name,
      message: "Choose the outcome of the event",
      type: "list",
      choices: contract.outcomes.map((outcome, index) => {
        return {
          name: outcome.message,
          short: outcome.message,
          value: { outcome, index },
        };
      }),
    },
  ]);
  return answers[name];
}

async function DecideClosing(outcome: Outcome, index: number): Promise<number> {
  const name = "Closing choice";
  const answers = await inquirer.prompt([
    {
      name,
      message: "Choose the closing method",
      type: "list",
      choices: [
        {
          name: "Collaborative closing",
          value: 0,
        },
        {
          name: "Unilateral closing by Alice",
          value: 1,
        },
        {
          name: "Unilateral closing by Bob",
          value: 2,
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
    const { outcome, index } = await DecideOutcome();
    const closingType = await DecideClosing(outcome, index);
    if (closingType === 0) {
      const mutualClosingMessage = alice.CreateMutualClosingMessage(outcome);
      await bob.OnMutualClosingMessage(mutualClosingMessage);
    } else {
      const signature = oracle.GetSignature(outcome.message);
      if (closingType === 1) {
        await alice.ExecuteUnilateralClose(signature, index);
      } else {
        await bob.ExecuteUnilateralClose(signature, index);
      }
    }
  }
  await PrintBalances();
});
