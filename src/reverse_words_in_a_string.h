class Solution {
private:
  void coalesceSpace(string &s) {
    auto start = s.begin();
    bool hasSpace = false;
    for (auto i = s.begin(); i != s.end(); ++i) {
      if (*i == ' ') {
        if (start == s.begin() || hasSpace) { // remove leading or redundant spaces
          continue;
        }
        hasSpace = true;
      } else {
        hasSpace = false;
      }
      *(start++) = *i;
    }
    if (start != s.begin() && *(start - 1) == ' ') { // remove trailing spaces
      --start;
    }
    s.resize(start - s.begin());
  }

public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    auto start = s.begin();
    auto i = s.begin();
    for (; i != s.end(); ++i) {
      if (*i == ' ') {
        reverse(start, i);
        start = i + 1;
      }
    }
    reverse(start, i);
    coalesceSpace(s);
  }
};
