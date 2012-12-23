#include "common.h"
#include "interleaving_string.h"
#include <gtest/gtest.h>

TEST(InterleavingString, isInterleave) {
  Solution s;
  ASSERT_TRUE(s.isInterleave("aabcc","dbbca","aadbbcbcac"));
  ASSERT_FALSE(s.isInterleave("aabcc","dbbca","aadbbbaccc"));
}
