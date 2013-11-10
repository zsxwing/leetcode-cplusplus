#include "common.h"
#include "reverse_linked_list_ii.h"
#include <gtest/gtest.h>

TEST(ReverseLinkedListII, reverseBetween) {
  Solution s;
  ListNode one(-1);
  ListNode two(-3);
  one.next = &two;
  ListNode *rotate = s.reverseBetween(&one, 1, 2);
  ASSERT_EQ(-3, rotate->val);
  ASSERT_EQ(-1, rotate->next->val);
  ASSERT_EQ(NULL, rotate->next->next);
}

TEST(ReverseLinkedListII, reverseBetween1) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  ListNode three(3);
  one.next = &two;
  two.next = &three;
  ListNode *rotate = s.reverseBetween(&one, 2, 3);
  ASSERT_EQ(1, rotate->val);
  ASSERT_EQ(3, rotate->next->val);
  ASSERT_EQ(2, rotate->next->next->val);
  ASSERT_EQ(NULL, rotate->next->next->next);
}

