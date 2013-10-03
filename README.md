leetcode-cplusplus
==================

My C++ solutions for [LeetCode Online Judge](http://oj.leetcode.com/).

## Build Status
[![Build Status](https://travis-ci.org/zsxwing/leetcode-cplusplus.png?branch=master)](https://travis-ci.org/zsxwing/leetcode-cplusplus)

## Requirements
* gcc >= 4.6
or
* clang >= 3.1

## Install gtest
I use google test library to write unit tests. So before building, you need to use the following commands to set up gtest.

```shell
chmod u+x contrib/install_contrib.sh
contrib/install_contrib.sh
```
## Generate a file for a question

```shell
./question.sh Some Question
```

The above command will generate two source file: src/some_question.h, test/some_question_test.cc. You can write your solution and unit tests directly.

## Build

If you are not using `g++`, you need to set `CXX` to the compiler which you are using. For example, `export CXX=clang++`.

After that, you can use the following command to build and test.
```shell
make
```

