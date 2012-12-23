#include "common.h"
#include "rotate_list.h"
#include <gtest/gtest.h>

TEST(RotateList, rotateRight) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  ListNode three(3);
  ListNode four(4);
  ListNode five(5);
  one.next = &two;
  two.next = &three;
  three.next = &four;
  four.next = &five;
  ListNode *rotate = s.rotateRight(&one, 2);
  ASSERT_EQ(&four, rotate);
  ASSERT_EQ(&five, rotate=rotate->next);
  ASSERT_EQ(&one, rotate=rotate->next);
  ASSERT_EQ(&two, rotate=rotate->next);
  ASSERT_EQ(&three, rotate=rotate->next);
  ASSERT_EQ(NULL, rotate->next);
}

TEST(RotateList, rotateRightWithNull) {
  Solution s;
  ASSERT_EQ(NULL, s.rotateRight(NULL, 2));
}

TEST(RotateList, rotateRightWithOneNodeList) {
  Solution s;
  ListNode one(1);
  ASSERT_EQ(&one, s.rotateRight(&one, 97));
}

TEST(RotateList, rotateRightWithK0) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  one.next = &two;
  ListNode *rotate = s.rotateRight(&one, 0);
  ASSERT_EQ(&one, rotate);
  ASSERT_EQ(&two, rotate=rotate->next);
  ASSERT_EQ(NULL, rotate->next);
}

TEST(RotateList, rotateRightWithK1) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  one.next = &two;
  ListNode *rotate = s.rotateRight(&one, 1);
  ASSERT_EQ(&two, rotate);
  ASSERT_EQ(&one, rotate=rotate->next);
  ASSERT_EQ(NULL, rotate->next);
}

TEST(RotateList, rotateRightWithK2) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  one.next = &two;
  ListNode *rotate = s.rotateRight(&one, 2);
  ASSERT_EQ(&one, rotate);
  ASSERT_EQ(&two, rotate=rotate->next);
  ASSERT_EQ(NULL, rotate->next);
}

TEST(RotateList, rotateRightWithK3) {
  Solution s;
  ListNode one(1);
  ListNode two(2);
  one.next = &two;
  ListNode *rotate = s.rotateRight(&one, 3);
  ASSERT_EQ(&two, rotate);
  ASSERT_EQ(&one, rotate=rotate->next);
  ASSERT_EQ(NULL, rotate->next);
}
