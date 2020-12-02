FROM alpine/git AS git
RUN git clone https://github.com/qmk/qmk_firmware.git /qmk

FROM debian:jessie
RUN apt-get update && apt-get install --no-install-recommends -y build-essential \
    gcc \
    unzip \
    wget \
    zip \
    gcc-avr \
    binutils-avr \
    avr-libc \
    dfu-programmer \
    dfu-util \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    git \
    software-properties-common \
    avrdude \
    && rm -rf /var/lib/apt/lists/*

ENV keyboard=tada68
ENV keymap=default
ENV output=bin

VOLUME /output

WORKDIR /qmk 
COPY --from=git /qmk /qmk
RUN git submodule init && git submodule update --init --recursive

CMD make clean ; make ${keyboard}:${keymap}:${output} && mv /qmk/.build/${keyboard}_${keymap}.* /output
