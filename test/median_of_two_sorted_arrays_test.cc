#include "common.h"
#include "median_of_two_sorted_arrays.h"
#include <gtest/gtest.h>

TEST(MedianOfTwoSortedArrays, findMedianSortedArrays) {
  Solution s;
  int A[] = { 1, 2 };
  int B[] = { 1, 2, 3 };
  s.findMedianSortedArrays(A, 2, B, 3);
}

