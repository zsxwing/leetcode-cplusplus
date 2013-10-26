class Solution {
private:
  bool isPalindrome(const char *s, int begin, int end) {
    for (int i = 0; i < (end - begin) / 2; i++) {
      if (s[begin + i] != s[end - i - 1]) {
        return false;
      }
    }
    return true;
  }

  void searchPalindromePartition(const char *s, int begin, int end,
      vector<vector<string> > &re, vector<string> &partition) {
    if (begin == end) {
      re.push_back(partition);
      return;
    } else if (begin == end - 1) {
      partition.push_back(string(s + begin, end - begin));
      re.push_back(partition);
      partition.pop_back();
      return;
    }
    for (int i = begin + 1; i <= end; i++) {
      if (isPalindrome(s, begin, i)) {
        partition.push_back(string(s + begin, i - begin));
        searchPalindromePartition(s, i, end, re, partition);
        partition.pop_back();
      }
    }
  }

public:
  vector<vector<string> > partition(string s) {
    vector < vector<string> > re;
    vector < string > partition;
    searchPalindromePartition(s.c_str(), 0, s.size(), re, partition);
    return re;
  }
};
