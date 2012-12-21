#include "common.h"
#include "balanced_binary_tree.h"
#include <gtest/gtest.h>

TEST(BalancedBinaryTree, isBalanced) {
  Solution s;
  TreeNode root(1);
  ASSERT_TRUE(s.isBalanced(&root));
}

