FROM ubuntu:20.04
MAINTAINER Maximilian Metti, Arthur Bousquet


RUN sed -i 's/^#\s*\(deb.*main restricted\)$/\1/g' /etc/apt/sources.list && \
    sed -i 's/^#\s*\(deb.*universe\)$/\1/g' /etc/apt/sources.list && \
    sed -i 's/^#\s*\(deb.*multiverse\)$/\1/g' /etc/apt/sources.list && \
    apt-get update && \
    apt-get -y upgrade && \
    apt-get install -y software-properties-common && \
    add-apt-repository ppa:fenics-packages/fenics && \
    apt-get update && \
    apt-get -y install fenics python3-pip python3-matplotlib python3-numpy python3-scipy && \
    pip3 install jupyterlab && \
    pip3 install pyeafe
    

# RUN sed -i -e 's/http:\/\/archive\.ubuntu\.com\/ubuntu\//mirror:\/\/mirrors\.ubuntu\.com\/mirrors\.txt/' /etc/apt/sources.list
# RUN apt-get -y install python3-dev


# RUN groupadd -r pdelab && useradd -r -g pdelab pdelab
# USER pdelab
WORKDIR /home/pdelab/

# Clean up APT when done.
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# ENTRYPOINT pip install --upgrade -r requirements.txt --prefix=/usr/local && /bin/bash
