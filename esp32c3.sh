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

# Fixed GCC
ESP_GCC_PATH="/opt/esp/tools/riscv32-esp-elf/esp-13.2.0_20240530/riscv32-esp-elf/bin"
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-ar ${ESP_GCC_PATH}/riscv64-unknown-elf-ar
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-gcc ${ESP_GCC_PATH}/riscv64-unknown-elf-gcc
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-ld ${ESP_GCC_PATH}/riscv64-unknown-elf-ld
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-nm ${ESP_GCC_PATH}/riscv64-unknown-elf-nm
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-objcopy ${ESP_GCC_PATH}/riscv64-unknown-elf-objcopy
ln -s ${ESP_GCC_PATH}/riscv32-esp-elf-strip ${ESP_GCC_PATH}/riscv64-unknown-elf-strip

# Patch apps
cd apps
git apply ../patch/esp32c3-apps.diff

mkdir -p netutils/homekit
cd netutils/homekit
cp ../../../patch/homekit/* .
git clone https://github.com/apple/HomeKitADK
cd HomeKitADK
git apply ../0001_patch_nuttx.patch
cd ..
cd ../..

mkdir -p netutils/mdns
cd netutils/mdns
cp ../../../patch/mdns/* .
tar xvf tinysvcmdns-2018-01-16.tar.gz
cd tinysvcmdns
git apply ../0001_patch_nuttx.patch
cp mdnsd.h ../../../include/netutils
cd ..
cd ../..

cd ..
cd nuttx

# Optional
cp ../patch/mbedtls_sslutils.c arch/risc-v/src/common/espressif
cp ../patch/sslutil.h arch/risc-v/src/common/espressif
cp ../patch/esp32c3_attr.h arch/risc-v/src/esp32c3
cp ../patch/esp32c3_textheap.c arch/risc-v/src/esp32c3
mkdir -p boards/risc-v/esp32c3/esp32c3-generic/src/etc/init.d
cp ../patch/rcS boards/risc-v/esp32c3/esp32c3-generic/src/etc/init.d
mkdir -p ../out

# Current
git apply ../patch/esp32c3-nuttx.diff
./tools/configure.sh esp32c3-generic:sta_softap
cat ../esp32c3.conf >> .config
make olddefconfig
set -e
make || true
git apply --directory=arch/risc-v/src/esp32c3/esp-hal-3rdparty ../patch/esp32c3-mbedtls.diff
make
cp nuttx.bin ../out/nuttx-esp32c3.bin
echo nuttx-esp32c3.bin >> ../out/status.txt
git log -1 --pretty=" * nuttx:%H (%cs)" >> ../out/status.txt
git -C arch/risc-v/src/esp32c3/esp-hal-3rdparty log -1 --pretty=" * hal:%H (%cs)" >> ../out/status.txt
imgtool dumpinfo nuttx.bin | grep img_size | awk -F ' ' '{print " * " "firmware:" 0 + $2 " (" $2 ")"}' >> ../out/status.txt
riscv32-esp-elf-objdump -h nuttx | grep .[di]ram | awk -F ' ' '{print "0x" $3}' | awk '{s+=$1} END {print " * " "free:" 16384 + 393216 - s "\n * " "used:" s}' >> ../out/status.txt

# Clean
make distclean
git reset --hard

# HAL-060724
git apply ../patch/esp32c3-nuttx-hal060724.diff
./tools/configure.sh esp32c3-generic:sta_softap
cat ../esp32c3.conf >> .config
make olddefconfig
set -e
make || true
git apply --directory=arch/risc-v/src/esp32c3/esp-hal-3rdparty ../patch/esp32c3-mbedtls-hal060724.diff
make
cp nuttx.bin ../out/nuttx-esp32c3-hal060724.bin
echo nuttx-esp32c3-hal060724.bin >> ../out/status.txt
git log -1 --pretty=" * nuttx:%H (%cs)" >> ../out/status.txt
git -C arch/risc-v/src/esp32c3/esp-hal-3rdparty log -1 --pretty=" * hal:%H (%cs)" >> ../out/status.txt
imgtool dumpinfo nuttx.bin | grep img_size | awk -F ' ' '{print " * " "firmware:" 0 + $2 " (" $2 ")"}' >> ../out/status.txt
riscv32-esp-elf-objdump -h nuttx | grep .[di]ram | awk -F ' ' '{print "0x" $3}' | awk '{s+=$1} END {print " * " "free:" 16384 + 393216 - s "\n * " "used:" s}' >> ../out/status.txt

cd ..
