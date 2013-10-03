leetcode-cplusplus
==================

My C++ solutions for [LeetCode Online Judge](http://oj.leetcode.com/).

## Requirements
* gcc >= 4.2

## Install gtest
I use google test library to write unit tests. So before building, you need to use the following commands to set up gtest.

```Shell
chmod u+x install_contrib.sh
contrib/install_contrib.sh
```
## Generate a file for a question

```Shell
./question.sh Some Question
```

The above command will generate two source file: src/some_question.h, test/some_question_test.cc. You can write your solution and unit tests directly.

== Build ==

'''Shell
make
'''

