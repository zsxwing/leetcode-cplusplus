#include <string>
using namespace std;

class Solution {

private:
  int numDecodings(const char *s, int len) {
    if (*s == '\0' || *s == '0') {
      return 0;
    }
    int* dp = new int[len + 1];
    dp[0] = 1;
    dp[1] = 1;
    int i = 1;
    while (s[i] != '\0') {
      if (s[i] != '0') {
        dp[i + 1] = dp[i];
      } else {
        dp[i + 1] = 0;
      }
      if (s[i - 1] == '1') {
        dp[i + 1] += dp[i - 1];
      } else if (s[i - 1] == '2' && s[i] <= '6') {
        dp[i + 1] += dp[i - 1];
      }
      ++i;
    }
    int re = dp[len];
    delete[] dp;
    return re;
  }

public:
  int numDecodings(string s) {
    return numDecodings(s.c_str(), s.size());
  }
};
