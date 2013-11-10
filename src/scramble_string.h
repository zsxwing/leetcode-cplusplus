class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }
    int len = s1.size();
    vector < vector<vector<bool> >
        > dp(len, vector < vector<bool> > (len, vector<bool>(len + 1, false)));
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        dp[i][j][1] = s1[i] == s2[j];
      }
    }
    for (int l = 2; l <= len; l++) {
      for (int i = 0; i <= len - l; i++) {
        for (int j = 0; j <= len - l; j++) {
          for (int p = 1; p < l; p++) {
            if ((dp[i][j][p] && dp[i + p][j + p][l - p])
                || (dp[i][j + l - p][p] && dp[i + p][j][l - p])) {
              dp[i][j][l] = true;
              break;
            }
          }
        }
      }
    }
    return dp[0][0][len];
  }
};
