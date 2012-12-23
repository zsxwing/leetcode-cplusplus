#include "common.h"
#include "edit_distance.h"
#include <gtest/gtest.h>

TEST(EditDistance, minDistance) {
  Solution s;
  ASSERT_EQ(0, s.minDistance("",""));
  ASSERT_EQ(1, s.minDistance("a",""));
  ASSERT_EQ(1, s.minDistance("","a"));
  ASSERT_EQ(0, s.minDistance("a","a"));
  ASSERT_EQ(1, s.minDistance("a","ab"));
  ASSERT_EQ(3, s.minDistance("sea", "ate"));
}
