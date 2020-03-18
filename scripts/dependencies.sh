#!/bin/bash
echo "This script will install developments dependency for chemistry-nao2gto on $(uname -r) environment"

# 3thd party libraries
cd libs/

# Catch2 Test Framework C++
git clone https://github.com/catchorg/Catch2.git
cd Catch2/
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install
cd ../

# DBG macro
git clone https://github.com/sharkdp/dbg-macro
sudo cp dbg-macro/dbg.h /usr/include/dbg.h

#
git clone https://github.com/zeux/pugixml
cd pugixml/
git checkout v1.10