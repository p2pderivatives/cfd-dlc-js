#!/bin/bash -euC

bitcoind=$(command -v bitcoind)
bitcoincli=$(command -v bitcoin-cli)
net="regtest"
conf="bitcoin.${net}.conf"
datadir="bitcoind"
opts=( -datadir=./"${datadir}" -conf=$conf )

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

echo "Creating or loading wallets"

aliceWalletFile="./${datadir}/${net}/wallets/alice"
if [ ! -d "${aliceWalletFile}" ]; then
  $bitcoincli "${opts[@]}" -named createwallet wallet_name=alice descriptors=false passphrase=alice
else
  $bitcoincli "${opts[@]}" loadwallet "alice"
fi

bobWalletFile="./${datadir}/${net}/wallets/bob"
if [ ! -d "${bobWalletFile}" ]; then
  $bitcoincli "${opts[@]}" -named createwallet wallet_name=bob descriptors=false passphrase=bob
else
  $bitcoincli "${opts[@]}" loadwallet "bob"
fi

aliceAddress=$($bitcoincli "${opts[@]}" -rpcwallet=alice getnewaddress bec32)
$bitcoincli "${opts[@]}" generatetoaddress 101 ${aliceAddress} &> /dev/null

bobAddress=$($bitcoincli "${opts[@]}" -rpcwallet=bob getnewaddress bec32)
$bitcoincli "${opts[@]}" generatetoaddress 101 ${bobAddress} &> /dev/null
