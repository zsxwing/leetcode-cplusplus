#include "common.h"
#include "gray_code.h"
#include <gtest/gtest.h>

inline void assertVectorEq(const vector<int> & excepted,
    const vector<int>& actual) {
  ASSERT_EQ(excepted.size(), actual.size());
  for (int i = 0; i < excepted.size(); i++) {
    ASSERT_EQ(excepted[i], actual[i]);
  }
}

TEST(GrayCode, grayCode) {
  Solution s;
  vector<int> answer;

  answer.push_back(0);
  assertVectorEq(answer, s.grayCode(0));

  answer.push_back(1);
  assertVectorEq(answer, s.grayCode(1));

  answer.push_back(3);
  answer.push_back(2);
  assertVectorEq(answer, s.grayCode(2));
}
