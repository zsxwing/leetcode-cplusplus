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

```bash
chmod u+x contrib/install_contrib.sh
contrib/install_contrib.sh
```
## Generate a file for a question

```bash
./question.sh Some Question
```

The above command will generate two source file: 
`src/some_question.h`: the solution you need to implement.
`test/some_question_test.cc`: you can write your unit tests here.

## Build

If you are not using `g++`, you need to set `CXX` to the compiler which you are using. For example, `export CXX=clang++`.

After that, you can use the following command to build and test.
```bash
make
```

