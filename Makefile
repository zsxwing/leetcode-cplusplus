
CXX:=g++

BUILD_DIR=build
LIB_DIR:=lib

INCLUDE_DIR:=include


TEST_INCLUDE_DIR:=$(INCLUDE_DIR) src contrib/gtest-1.6.0/include
TEST_LIB:=pthread gtest

TEST_INCLUDE_FLAG:=$(foreach d,$(TEST_INCLUDE_DIR),-I$(d))
TEST_LIB_FLAG:=-L$(LIB_DIR) $(foreach l,$(TEST_LIB),-l$(l))

include src/Makefile
include test/Makefile


