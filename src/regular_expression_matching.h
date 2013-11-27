class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    vector < vector<bool> > dp(pLen + 1, vector<bool>(sLen + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= pLen; i++) {
      dp[i][0] = p[i - 1] == '*' && dp[i - 2][0];
      for (int j = 1; j <= sLen; j++) {
        if (p[i - 1] == '*') {
          if (dp[i - 2][j]) {
            dp[i][j] = true;
            continue;
          }
          for (int k = j; k > 0; k--) {
            if (p[i - 2] != '.' && p[i - 2] != s[k - 1]) {
              break;
            }
            if (dp[i - 2][k - 1]) {
              dp[i][j] = true;
              break;
            }
          }
        } else {
          dp[i][j] = dp[i - 1][j - 1]
              && (p[i - 1] == '.' || p[i - 1] == s[j - 1]);
        }
      }
    }
    return dp[pLen][sLen];
  }
};
