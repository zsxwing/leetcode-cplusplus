#include "common.h"
#include "length_of_last_word.h"
#include <gtest/gtest.h>

TEST(LengthOfLastWord, lengthOfLastWord) {
  Solution s;
  ASSERT_EQ(0, s.lengthOfLastWord(""));
  ASSERT_EQ(0, s.lengthOfLastWord(" "));
  ASSERT_EQ(0, s.lengthOfLastWord("  "));
  ASSERT_EQ(1, s.lengthOfLastWord("  a"));
  ASSERT_EQ(1, s.lengthOfLastWord("a  "));
  ASSERT_EQ(1, s.lengthOfLastWord(" a "));
  ASSERT_EQ(1, s.lengthOfLastWord("a"));
}
