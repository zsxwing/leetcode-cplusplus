#include "common.h"
#include "reorder_list.h"
#include <gtest/gtest.h>

TEST(ReorderList, reorderList) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  ListNode three(3);
  ListNode four(4);

  one.next = &two;
  two.next = &three;
  three.next = &four;
  s.reorderList(&one);

  EXPECT_EQ(&four, one.next);
  EXPECT_EQ(&two, four.next);
  EXPECT_EQ(&three, two.next);
  EXPECT_EQ(NULL, three.next);
}
