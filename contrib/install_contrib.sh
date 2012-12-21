#!/bin/sh

cd $( dirname $0 ) && rm -rf gtest-1.6.0 && unzip gtest-1.6.0.zip || exit $?
g++ -Igtest-1.6.0/include -Igtest-1.6.0 -c gtest-1.6.0/src/gtest-all.cc gtest-1.6.0/src/gtest_main.cc || exit $?
ar -rv libgtest.a gtest-all.o gtest_main.o || exit $?
rm -rf gtest-all.o gtest_main.o || exit $?
mkdir ../lib/
mv libgtest.a ../lib/ || exit $?

