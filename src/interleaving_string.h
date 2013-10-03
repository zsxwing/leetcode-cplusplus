class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    vector<bool> dp(s2.size() + 1, false);
    for (int i = 0; i <= s1.length(); i++) {
      for (int j = 0; j <= s2.length(); j++) {
        dp[j] = (i == 0 && j == 0)
            || (i != 0 && s1[i - 1] == s3[i + j - 1] && dp[j])
            || (j != 0 && s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
      }
    }
    return dp[s2.size()];
  }
};
