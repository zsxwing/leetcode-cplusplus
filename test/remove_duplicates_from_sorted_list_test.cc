#include "common.h"
#include "remove_duplicates_from_sorted_list.h"
#include <gtest/gtest.h>

TEST(RemoveDuplicatesFromSortedList, deleteDuplicates) {
  ListNode head(1);
  ListNode tail(1);
  head.next = &tail;
  Solution s;
  ListNode *result = s.deleteDuplicates(&head);
  ASSERT_EQ(1, result->val);
  ASSERT_EQ(NULL, result->next);
}
