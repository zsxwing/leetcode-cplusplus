class Solution {
public:
  string longestPalindrome(string s) {
    string t = "^#";
    for (int i = 0; i < s.size(); i++) {
      t += s[i];
      t += '#';
    }
    t += '$';

    int* p = new int[t.size()];
    p[1] = 1;
    int id = 1;
    int rightIndex = 2;
    for (int i = 2; i < t.size() - 1; i++) {
      if (rightIndex > i) {
        p[i] = min(p[2 * id - i], rightIndex - i);
      } else {
        p[i] = 1;
      }
      while (t[i + p[i]] == t[i - p[i]]) {
        p[i]++;
      }
      if (rightIndex < i + p[i]) {
        rightIndex = i + p[i];
        id = i;
      }
    }

    int maxIndex = max_element(p + 1, p + (t.size() - 1)) - p;
    int length = p[maxIndex] - 1;
    int startIndex = (maxIndex - p[maxIndex]) / 2;

    delete[] p;
    return s.substr(startIndex, length);
  }
};
