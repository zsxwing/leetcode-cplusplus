#include "common.h"
#include "partition_list.h"
#include <gtest/gtest.h>

TEST(PartitionList, partition) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  ListNode two2(2);
  ListNode three(3);
  ListNode four(4);
  ListNode five(5);
  one.next = &four;
  four.next = &three;
  three.next = &two;
  two.next = &five;
  five.next = &two2;
  ListNode *partition = s.partition(&one, 3);
  ASSERT_EQ(&one, partition);
  ASSERT_EQ(&two, partition=partition->next);
  ASSERT_EQ(&two2, partition=partition->next);
  ASSERT_EQ(&four, partition=partition->next);
  ASSERT_EQ(&three, partition=partition->next);
  ASSERT_EQ(&five, partition= partition->next);
  ASSERT_EQ(NULL, partition=partition->next);
}

TEST(PartitionList, partitionWithEmptyList) {
  Solution s;
  ASSERT_EQ(NULL, s.partition(NULL, 2));
}
