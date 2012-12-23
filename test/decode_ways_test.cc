#include "common.h"
#include "decode_ways.h"
#include <gtest/gtest.h>

TEST(DecodeWays, numDecodings) {
  Solution s;
  ASSERT_EQ(0, s.numDecodings(""));
  ASSERT_EQ(0, s.numDecodings("0"));
  ASSERT_EQ(1, s.numDecodings("10"));
  ASSERT_EQ(2, s.numDecodings("12"));
  ASSERT_EQ(1, s.numDecodings("27"));
  ASSERT_EQ(1769472,
      s.numDecodings("7541387519572282368613553811323167125532172369624572591562685959575371877973171856836975137559677665"));
}
