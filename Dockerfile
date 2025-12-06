FROM debian:latest
RUN apt-get update && apt-get install --no-install-recommends -y \
    build-essential gcc unzip wget zip \
    gcc-avr binutils-avr avr-libc \
    dfu-programmer dfu-util \
    gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi \
    git avrdude ca-certificates \
    python3 python3-pip \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /qmk
RUN git clone https://github.com/qmk/qmk_firmware.git . \
    && git submodule init \
    && git submodule update --init --recursive
RUN python3 -m pip install --break-system-packages qmk && \
    python3 -m pip install --break-system-packages -r requirements.txt
ENV keyboard=tada68
ENV keymap=default
ENV output=hex
VOLUME /output

CMD make clean ; make ${keyboard}:${keymap} && mv /qmk/.build/* /output