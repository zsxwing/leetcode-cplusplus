class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int len = 0;
    while (*s) {
      if (*s != ' ') {
        len++;
        s++;
      } else {
        s++;
        if (*s && *s != ' ') {
          len = 0;
        }
      }
    }
    return len;
  }
};
