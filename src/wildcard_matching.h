class Solution {
private:
  int minLenOfP(const char *p) {
    int len = 0;
    while (*p) {
      if (*p != '*') {
        len++;
      }
      p++;
    }
    return len;
  }

  bool isMatchWithDP(const char *s, const char *p) {
    if (s == NULL || p == NULL)
      return false;

    int sLength = strlen(s);
    if (sLength < minLenOfP(p)) {
      return false;
    }

    bool *match = new bool[sLength + 1];
    fill(match, match + (sLength + 1), false);
    match[0] = true;
    for (int j = 1, pLength = strlen(p); j <= pLength; j++) {
      for (int i = sLength; i > 0; i--) {
        if (p[j - 1] == '*') {
          for (int k = i; k >= 0; k--) {
            if (match[k]) {
              match[i] = true;
              break;
            }
          }
        } else {
          match[i] = (p[j - 1] == '?' || s[i - 1] == p[j - 1]) && match[i - 1];
        }
      }
      match[0] = match[0] && p[j - 1] == '*';
    }
    bool re = match[sLength];
    delete[] match;
    return re;
  }

public:
  bool isMatch(const char *s, const char *p) {
    while (*s && *p) {
      if (*p == '*') {
        return isMatchWithDP(s, p);
      }
      if (*p != '?' && *s != *p) {
        return false;
      }
      s++;
      p++;
    }
    if (*p == '*') {
      return isMatchWithDP(s, p);
    }
    return *s == '\0' && *p == '\0';
  }
};

