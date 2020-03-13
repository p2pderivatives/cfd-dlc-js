#!/bin/sh

if [ ! -d "tmp" ]; then
	mkdir tmp
	pushd tmp
	git clone git@github.com:cryptogarageinc/cfd-dlc.git
	pushd cfd-dlc
	git checkout vWIP
	popd
fi
docker-compose up --build
