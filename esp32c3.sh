#!/usr/bin/env bash

git submodule update --init tools

cd tools/kconfig-frontends
./configure --enable-mconf
make
make install
cd ../..

git submodule update --init apps
git submodule update --init nuttx

cd nuttx
./tools/configure.sh esp32c3-generic:wifi
cat ../esp32c3.conf | tee -a .config
git apply ../esp32c3.diff
make
