#!/bin/bash -u

# while :; do sleep 10; done
export WORKDIR_ROOT=/tmp/workspace
export WORK_DIR=cfd-dlc-js/integration_tests/
export WORKDIR_PATH=/${WORKDIR_ROOT}/${WORK_DIR}

bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir stop > /dev/null 2>&1

cd /${WORKDIR_ROOT}
if [ ! -d ${WORK_DIR} ]; then
  mkdir ${WORK_DIR}
fi

cd ${WORKDIR_PATH}
rm -rf bitcoind_datadir
rm -rf elementsd_datadir

mkdir bitcoind_datadir
chmod 777 bitcoind_datadir
# cp /root/.bitcoin/bitcoin.conf bitcoind_datadir/
cp ./__tests__/bitcoin.conf bitcoind_datadir/
mkdir elementsd_datadir
chmod 777 elementsd_datadir
# cp /root/.elements/elements.conf elementsd_datadir/
cp ./__tests__/elements.conf elementsd_datadir/

# boot daemon
bitcoind --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir
bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
while [ $? -ne 0 ]
do
  bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
done
echo "start bitcoin node"

# elementsd -chain=liquidregtest -datadir=${WORKDIR_PATH}/elementsd_datadir
# elements-cli -chain=liquidregtest -datadir=${WORKDIR_PATH}/elementsd_datadir ping > /dev/null 2>&1
# while [ $? -ne 0 ]
# do
#   elements-cli -chain=liquidregtest -datadir=${WORKDIR_PATH}/elementsd_datadir ping > /dev/null 2>&1
# done
# echo "start elements node"