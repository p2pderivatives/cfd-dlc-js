FROM cryptogarageinc/cfd-dlc-ci:v0.0.1

ENV WORKSPACE /tmp/workspace
WORKDIR ${WORKSPACE}

ENV GPG_KEY_SERVER hkp://keyserver.ubuntu.com:80

# setup bitcoin
ARG BITCOIN_VERSION=0.18.1
ENV BITCOIN_TARBALL bitcoin-${BITCOIN_VERSION}-x86_64-linux-gnu.tar.gz
ENV BITCOIN_URL_BASE https://bitcoincore.org/bin/bitcoin-core-${BITCOIN_VERSION}
ENV BITCOIN_PGP_KEY 01EA5486DE18A882D4C2684590C8019E36C2E964
RUN wget -qO ${BITCOIN_TARBALL} ${BITCOIN_URL_BASE}/${BITCOIN_TARBALL} \
    && gpg --keyserver ${GPG_KEY_SERVER} --recv-keys ${BITCOIN_PGP_KEY} \
    && wget -qO SHA256SUMS.asc ${BITCOIN_URL_BASE}/SHA256SUMS.asc \
    && gpg --verify SHA256SUMS.asc \
    && sha256sum --ignore-missing --check SHA256SUMS.asc \
    && tar -xzvf ${BITCOIN_TARBALL} --directory=/opt/ \
    && ln -sfn /opt/bitcoin-${BITCOIN_VERSION}/bin/* /usr/bin \
    && rm -f ${BITCOIN_TARBALL} SHA256SUMS.asc

# install node
RUN wget -qO - https://deb.nodesource.com/setup_12.x | bash && \
    apt-get install -y nodejs

WORKDIR ${WORKSPACE}/cfd-dlc-js
