#!/bin/bash -e

cd $( dirname $0 ) && rm -rf gtest-1.6.0 && unzip gtest-1.6.0.zip
g++ -Igtest-1.6.0/include -Igtest-1.6.0 -c gtest-1.6.0/src/gtest-all.cc gtest-1.6.0/src/gtest_main.cc
ar -rv libgtest.a gtest-all.o gtest_main.o
rm -rf gtest-all.o gtest_main.o
[[ -e "../lib/" ]] || mkdir ../lib/
mv libgtest.a ../lib/

