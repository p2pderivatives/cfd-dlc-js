FROM ubuntu:18.04

ENV WORKSPACE /tmp/workspace
WORKDIR ${WORKSPACE}

# 
RUN apt-get update -y && \
  apt-get install -y git wget curl python build-essential libusb-1.0-0-dev lcov && \
  rm -rf /var/lib/apt/lists/*

# install latest cmake
RUN wget https://github.com/Kitware/CMake/releases/download/v3.15.2/cmake-3.15.2-Linux-x86_64.tar.gz && \
  tar -xvf cmake-3.15.2-Linux-x86_64.tar.gz && \
  cp cmake-3.15.2-Linux-x86_64/bin/* /usr/local/bin && cp -r cmake-3.15.2-Linux-x86_64/share/* /usr/local/share && \
  rm -rf cmake-3.15.2-Linux-x86_64/ cmake-3.15.2-Linux-x86_64.tar.gz

# install nodejs
RUN curl -sL https://deb.nodesource.com/setup_13.x | bash
RUN apt-get install -y nodejs

#install ts-node
RUN npm install ts-node

# install cfd-js
RUN git clone https://github.com/cryptogarageinc/cfd-js
RUN cd cfd-js && npm install && npm link

# move mount directory
WORKDIR ${WORKSPACE}/cfd-dlc-js
