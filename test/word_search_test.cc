#include "common.h"
#include "word_search.h"
#include <gtest/gtest.h>

TEST(WordSearch, exist) {
  Solution s;
  vector<vector<char> > board;
  vector<char> row;
  row.push_back('a');
  board.push_back(row);
  ASSERT_EQ(false, s.exist(board,"ab"));
}

