#include "common.h"
#include "sum_root_to_leaf_numbers.h"
#include <gtest/gtest.h>

TEST(SumRootToLeafNum, sumNumbers) {
  Solution s;
  TreeNode one(1);
  TreeNode nine(9);
  nine.right = &one;
  TreeNode zero(0);
  TreeNode four(4);
  four.left = &nine;
  four.right = &zero;
  ASSERT_EQ(531, s.sumNumbers(&four));
}
