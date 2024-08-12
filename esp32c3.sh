#!/usr/bin/env bash

git submodule update --init tools

cd tools/kconfig-frontends
touch aclocal.m4 Makefile.am configure Makefile.in
./configure --enable-mconf
make
make install
ldconfig
cd ../..

apt update
apt install genromfs xxd
pip install imgtool

git submodule update --init apps
git submodule update --init nuttx

ESP_GCC_PATH="/opt/esp/tools/riscv32-esp-elf/esp-13.2.0_20240530/riscv32-esp-elf/bin"
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-ar ${ESP_GCC_PATH}/riscv64-unknown-elf-ar
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-gcc ${ESP_GCC_PATH}/riscv64-unknown-elf-gcc
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-ld ${ESP_GCC_PATH}/riscv64-unknown-elf-ld
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-nm ${ESP_GCC_PATH}/riscv64-unknown-elf-nm
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-objcopy ${ESP_GCC_PATH}/riscv64-unknown-elf-objcopy
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-strip ${ESP_GCC_PATH}/riscv64-unknown-elf-strip

cd apps
git apply ../esp32c3-apps.diff
cd ..

cd nuttx
./tools/configure.sh esp32c3-generic:wifi
cat ../esp32c3.conf >> .config
git apply ../esp32c3-nuttx.diff
cp ../esp_net_sockets.c arch/risc-v/src/common/espressif
cp ../mbedtls_sslutils.c arch/risc-v/src/common/espressif
cp ../sslutil.h arch/risc-v/src/common/espressif
cp ../esp32c3_attr.h arch/risc-v/src/esp32c3
cp ../esp32c3_textheap.c arch/risc-v/src/esp32c3
mkdir -p boards/risc-v/esp32c3/esp32c3-generic/src/etc/init.d
cp ../rcS boards/risc-v/esp32c3/esp32c3-generic/src/etc/init.d
make olddefconfig
make
cd ..

mkdir out
cp nuttx/nuttx.bin out/nuttx-esp32c3.bin
