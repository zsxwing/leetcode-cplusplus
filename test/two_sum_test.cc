#include "common.h"
#include "two_sum.h"
#include <gtest/gtest.h>

TEST(TwoSum, twoSum) {
  Solution s;
  vector<int> numbers;
  numbers.push_back(2);
  numbers.push_back(7);
  numbers.push_back(11);
  numbers.push_back(15);

  vector<int> expected;
  expected.push_back(1);
  expected.push_back(2);

  ASSERT_EQ(expected, s.twoSum(numbers, 9));
}
