#!/usr/bin/env bash

git submodule update --init tools

cd tools/kconfig-frontends
touch aclocal.m4 Makefile.am configure Makefile.in
./configure --enable-mconf
make
make install
ldconfig
cd ../..

git submodule update --init apps
git submodule update --init nuttx

ESP_GCC_PATH="/opt/esp/tools/riscv32-esp-elf/esp-13.2.0_20240530/riscv32-esp-elf/bin"
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-ar ${ESP_GCC_PATH}/riscv64-unknown-elf-ar
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-gcc ${ESP_GCC_PATH}/riscv64-unknown-elf-gcc
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-ld ${ESP_GCC_PATH}/riscv64-unknown-elf-ld
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-nm ${ESP_GCC_PATH}/riscv64-unknown-elf-nm
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-objcopy ${ESP_GCC_PATH}/riscv64-unknown-elf-objcopy
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-strip ${ESP_GCC_PATH}/riscv64-unknown-elf-strip

cd nuttx
./tools/configure.sh esp32c3-generic:wifi
cat ../esp32c3.conf >> .config
git apply ../esp32c3.diff
make olddefconfig
make
