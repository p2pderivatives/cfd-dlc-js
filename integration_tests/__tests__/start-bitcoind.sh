#!/bin/bash -u

# while :; do sleep 10; done
export WORKDIR_ROOT=$1
export WORK_DIR=$2
export WORKDIR_PATH=/${WORKDIR_ROOT}/${WORK_DIR}


bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir stop > /dev/null 2>&1

cd /${WORKDIR_ROOT}
if [ ! -d ${WORK_DIR} ]; then
  mkdir ${WORK_DIR}
fi

cd ${WORKDIR_PATH}
rm -rf bitcoind_datadir

mkdir bitcoind_datadir
chmod 777 bitcoind_datadir
cp ./__tests__/bitcoin.conf bitcoind_datadir/

# boot daemon
bitcoind --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir
bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
while [ $? -ne 0 ]
do
  bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
done
echo "start bitcoin node"
