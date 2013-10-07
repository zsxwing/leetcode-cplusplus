#include "common.h"
#include "word_break_ii.h"
#include <gtest/gtest.h>

TEST(A, A) {
  Solution s;
  unordered_set<string> dict;
  dict.insert("a");
  s.wordBreak("a", dict);
}
