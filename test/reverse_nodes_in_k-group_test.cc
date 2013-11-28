#include "common.h"
#include "reverse_nodes_in_k-group.h"
#include <gtest/gtest.h>

TEST(ReverseNodesInKGroup, reverseKGroup) {
  ListNode a1(1);
  ListNode a2(2);
  ListNode a3(3);
  a1.next = &a2;
  a2.next = &a3;

  Solution s;
  ListNode *re = s.reverseKGroup(&a1, 2);

  ASSERT_EQ(&a2, re);
  ASSERT_EQ(&a1, re->next);
  ASSERT_EQ(&a3, re->next->next);
  ASSERT_EQ(NULL, re->next->next->next);
}
