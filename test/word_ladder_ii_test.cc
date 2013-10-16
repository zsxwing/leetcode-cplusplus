#include "common.h"
#include "word_ladder_ii.h"
#include <gtest/gtest.h>

TEST(WordLoaderII, findLadders) {
  Solution s;
  unordered_set<string> dict;
  dict.insert("a");
  dict.insert("b");
  dict.insert("c");
  vector<vector<string> > res;
  vector<string> v;
  v.push_back("a");
  v.push_back("c");
  res.push_back(v);
  ASSERT_EQ(res, s.findLadders("a","c",dict));
}

TEST(WordLoaderII, findLadders1) {
  Solution s;
  unordered_set<string> dict;
  dict.insert("hot");
  dict.insert("dog");
  vector<vector<string> > res;
  ASSERT_EQ(res, s.findLadders("hot","dog",dict));
}

TEST(WordLoaderII, findLadders2) {
  Solution s;
  unordered_set<string> dict;
  dict.insert("ted");
  dict.insert("tex");
  dict.insert("red");
  dict.insert("tax");
  dict.insert("tad");
  dict.insert("den");
  dict.insert("rex");
  dict.insert("pee");
  vector<vector<string> > res;
  {
    vector<string> v;
    v.push_back("red");
    v.push_back("ted");
    v.push_back("tad");
    v.push_back("tax");
    res.push_back(v);
  }
  {
    vector<string> v;
    v.push_back("red");
    v.push_back("ted");
    v.push_back("tex");
    v.push_back("tax");
    res.push_back(v);
  }
  {
    vector<string> v;
    v.push_back("red");
    v.push_back("rex");
    v.push_back("tex");
    v.push_back("tax");
    res.push_back(v);
  }
  ASSERT_EQ(res, s.findLadders("red","tax",dict));
}

