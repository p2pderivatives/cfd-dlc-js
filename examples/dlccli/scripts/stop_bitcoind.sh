#!/bin/bash -euC

bitcoincli=$(command -v bitcoin-cli)
net="regtest"
conf="bitcoin.${net}.conf"
opts=( -datadir=./bitcoind -conf=$conf )

$bitcoincli "${opts[@]}" stop
