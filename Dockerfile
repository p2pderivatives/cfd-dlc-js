FROM cryptogarageinc/elements-testing:v0.18.1.3 as cpp

ENV WORKSPACE /tmp/workspace

# Pass ssh keys from the host machine using build-arg
ARG ssh_prv_key
ARG ssh_pub_key

# Authorize SSH Host
RUN mkdir -p /root/.ssh && \
    chmod 0700 /root/.ssh && \
    ssh-keyscan github.com > /root/.ssh/known_hosts

# Add the keys and set permissions
RUN echo "$ssh_prv_key" > /root/.ssh/id_rsa && \
    echo "$ssh_pub_key" > /root/.ssh/id_rsa.pub && \
    chmod 600 /root/.ssh/id_rsa && \
    chmod 600 /root/.ssh/id_rsa.pub

RUN npm install --global typescript ts-node

WORKDIR ${WORKSPACE}/cfd-dlc-js
COPY . .
RUN npm install && npm run cmake_all

# Remove SSH keys
# RUN rm -rf /root/.ssh/

CMD ["ts-node", "./wrap_js/compatibility_test.ts"]
