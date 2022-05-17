# DLC CLI

In this part we will use the code we previously implemented to create a simple CLI application that sets up a DLC and then executes it.
To do so we make use of the `inquirer` library to retrieve the parameters from the user.
Of course in a real application, you would retrieve the parameters from the different parties, but hopefully this will give you a sense of how things work.

Before starting, add the following code in the root `index.ts` file:

```typescript
import inquirer from "inquirer";
import datepicker from "inquirer-datepicker";

// To be able to input dates
inquirer.registerPrompt("datepicker", datepicker);
```

## Creating the parties

We start by instanciating two DLC parties in the main `index.ts` file, Alice and Bob, as well as a wallet for each of them (we assume that the wallets exist on the bitcoind instance we communicate with, we will set that up later on).
We use hard coded values for the bitcoind configuration, feel free to change them to fit your setting.
We also instantiate an `Oracle` object and a `Contract`.

```typescript
import DlcParty from "./models/DlcParty";
import Oracle from "./models/Oracle";
import Contract from "./models/Contract";
import { v4 as uuidv4 } from "uuid";
import Client, { ClientConstructorOption } from "bitcoin-core";

export function CreateWalletClient(walletName: string) {
  const clientConfig: ClientOption = {
    baseURL: `http://localhost:18443/wallet/${walletName}`,
  };
  clientConfig.auth = { username: "user", password: "pass" };

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
```

## Initial inputs

First we add a `prompts` folder from the root to store the questions we will ask to the user (we will only use that for when we have many questions, it can also be done inline).
We then create an `Initial.ts` file inside it that contains the set of initial questions:

```typescript
import inquirer from "inquirer";

export enum InitialInputNames {
  LocalCollateral = "Local Collateral",
  RemoteCollateral = "Remote Collateral",
  Refund = "RefundTime",
  FeeRate = "Fee Rate",
}

export const InitialInputs: inquirer.Question[] = [
  {
    type: "number",
    name: InitialInputNames.LocalCollateral,
    message: "Enter local collateral",
    default: 1,
  },
  {
    type: "number",
    name: InitialInputNames.RemoteCollateral,
    message: "Enter remote collateral",
    default: 1,
  },
  {
    type: "datepicker",
    name: InitialInputNames.Refund,
    message: "Choose refund date and time",
  },
  {
    type: "number",
    name: InitialInputNames.FeeRate,
    message: "Enter fee rate",
    default: 2,
  },
];
```

Using this, we go back to the main `index.ts` file to create a prompt:

```typescript
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
```

You will need the following imports:

```typescript
import inquirer from "inquirer";
import { InitialInputs, InitialInputNames } from "./prompts/Initial";
import Amount from "./models/Amount";
```

This initializes our contract, but we also need to get a set of possible outcomes.
Create an `Outcomes.ts` file in the `prompts` folder:

```typescript
import inquirer from "inquirer";

export enum OutcomeInputNames {
  Message = "Message",
  LocalPayout = "Local Payout",
  RemotePayout = "Remote Payout",
  AddMore = "Add more",
}

export const OutcomeInputs: inquirer.Question[] = [
  {
    name: OutcomeInputNames.Message,
    message: "Enter the outcome message",
  },
  {
    name: OutcomeInputNames.LocalPayout,
    message: "Enter the local payout",
    type: "number",
  },
  {
    name: OutcomeInputNames.RemotePayout,
    message: "Enter the remote payout",
    type: "number",
  },
  {
    name: OutcomeInputNames.AddMore,
    message: "Enter another outcome?",
    type: "confirm",
    default: false,
  },
];
```

Back in `index.ts` we use this to get a set of outcomes.
As there usually are multiple outcomes, we recurse until the user has finished inputting them.

```typescript
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
  contract.messagesList.push({ messages: [message] });

  if (addMore) {
    await GetOutcomes();
  }
}
```

And add the required imports:

```typescript
import { OutcomeInputs, OutcomeInputNames } from "./prompts/Outcomes";
import Payout from "./models/Payout";
```

## Accepting or rejecting the contract

We now create a function to enable Bob to accept or reject the contract.
We display the contract and ask him whether to accept it or not:

```typescript

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
```

Add the necessary imports:

```typescript
import util from "util";
import OfferMessage from "./models/OfferMessage";
```

## Deciding the outcome

For the purpose of this simple application, we will let the user decide on the outcome:

```typescript
async function DecideOutcome(): Promise<{ message_string: string; index: number }> {
  const name = "Outcome choice";
  const answers = await inquirer.prompt([
    {
      name,
      message: "Choose the outcome of the event",
      type: "list",
      choices: contract.messagesList.map((message, index) => {
        const message_string = message['messages'][0];
        return {
          name: message_string,
          short: message_string,
          value: { message_string, index },
        };
      }),
    },
  ]);
  return answers[name];
}
```

## Decide how to close the contract

We will now create a function to let the user decide on who should close the contract.
Recall that both Alice and Bob can close the contract.

1. Closing by Alice
1. Closing by Bob

```typescript
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
```

## Putting everything together

Finally we can combine all the functions we just define.
We first add a small utility function to print the balance of Alice and Bob, and then generate 101 blocks to make sure that all the mining reward we generated for each parties is mature (otherwise it will be difficult to see the result of the DLC execution).
After we simply obtain the inputs by asking the user through the different prompts we previously defined, and use the answers to build the contract and messages:

```typescript
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
```

## Running the application

To run the application, we first need to start a bitcoind instance in regtest, and create the wallets for Alice and Bob.
You can use the following script to do so (put it in a `scripts` folder):

```bash
#!/bin/bash -euC

bitcoind=$(command -v bitcoind)
bitcoincli=$(command -v bitcoin-cli)
net="regtest"
conf="bitcoin.${net}.conf"
opts=( -datadir=./bitcoind -conf=$conf )

# start deamon if not running
function getnetworkinfo() {
  $bitcoincli "${opts[@]}" getnetworkinfo &> /dev/null
  echo $?
}

while [[ "$#" -ne "0" ]];do
  opts+=( ${1} )
  shift
done

if [[ "$(getnetworkinfo)" -ne "0" ]];then
  $bitcoind "${opts[@]}"

  # wait until accepting rpc requests
  cnt=0
  while true;do
    if [[ "$(getnetworkinfo)" -eq "0" ]];then
      break
    fi
    if [[ "$cnt" -gt "100" ]];then
      echo "Failed to start bitcoind. see debug.log for more details."
      exit 1
    fi
    sleep 0.1
    cnt=$(($cnt+1))
  done
else
  echo "Bitcoind is already running"
fi

function getblockcount() {
  echo $($bitcoincli "${opts[@]}" getblockcount)
}
height=$(getblockcount)
echo "Block Height: ${height}"

echo "Creating wallets"
$bitcoincli "${opts[@]}" createwallet "alice" "false" "false" "alice"
$bitcoincli "${opts[@]}" createwallet "bob" "false" "false" "bob"

aliceAddress=$($bitcoincli "${opts[@]}" -rpcwallet=alice getnewaddress bec32)
$bitcoincli "${opts[@]}" generatetoaddress 101 ${aliceAddress} &> /dev/null
bobAddress=$($bitcoincli "${opts[@]}" -rpcwallet=bob getnewaddress bec32)
$bitcoincli "${opts[@]}" generatetoaddress 101 ${bobAddress} &> /dev/null
```

You might need to give execution permission to the script:

```bash
chmod +x ./scripts/start_bitcoind.sh
```

(Don't execute scripts you don't trust! Verify the content of the script by yourself before running it, especially when working with Bitcoin!)

Create a folder `bitcoind` in the root of the project, put the following in a `bitcoin.regtest.conf` file:

```
rpcuser=user
rpcpassword=pass
regtest=1
daemon=1
addresstype=bech32
```

Note that it's important to use `bech32` addresses as DLC requires SegWit transactions to work.

Now you are ready to run, type `npm run example` and create your first DLC contract!
