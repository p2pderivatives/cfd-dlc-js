FROM debian:stable-slim

ENV WORKSPACE /tmp/workspace

# Pass ssh keys from the host machine using build-arg
ARG ssh_prv_key
ARG ssh_pub_key

RUN apt-get update -y && apt-get install -y \
    python3-dev \
    curl \
    git \
    build-essential \
    libssl-dev

# Install cmake 3.17.0-rc2
WORKDIR ${WORKSPACE}
RUN curl -L \
    https://github.com/Kitware/CMake/releases/download/v3.17.0-rc2/cmake-3.17.0-rc2.tar.gz \
    --output cmake-3.17.0-rc2.tar.gz
RUN tar -zxvf ./cmake-3.17.0-rc2.tar.gz

WORKDIR ${WORKSPACE}/cmake-3.17.0-rc2
RUN ./bootstrap && make && make install

# Install nodejs
RUN curl -sL https://deb.nodesource.com/setup_13.x | bash
RUN apt-get install -y nodejs

# Authorize SSH Host
RUN mkdir -p /root/.ssh && \
    chmod 0700 /root/.ssh && \
    ssh-keyscan github.com > /root/.ssh/known_hosts

# Add the keys and set permissions
RUN echo "$ssh_prv_key" > /root/.ssh/id_rsa && \
    echo "$ssh_pub_key" > /root/.ssh/id_rsa.pub && \
    chmod 600 /root/.ssh/id_rsa && \
    chmod 600 /root/.ssh/id_rsa.pub

WORKDIR ${WORKSPACE}/cfd-dlc-js
RUN git clone git@github.com:cryptogarageinc/cfd-dlc-js.git . && git checkout wip && npm install && npm run cmake_all

# Remove SSH keys
RUN rm -rf /root/.ssh/

CMD ["ts-node", "./wrap_js/compatibility_test.ts"]
