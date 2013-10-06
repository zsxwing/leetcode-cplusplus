#include "common.h"
#include "maximum_subarray.h"
#include <gtest/gtest.h>

TEST(MaximumSubarray,maxSubArray) {
  Solution s;
  int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  ASSERT_EQ(6, s.maxSubArray(A,9));
}


