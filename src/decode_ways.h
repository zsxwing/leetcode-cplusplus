class Solution {
public:
  int numDecodings(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int dp[s.size() + 1];
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    int i = 1;
    for (int i = 1; i < s.size(); i++) {
      dp[i + 1] = s[i] == '0' ? 0 : dp[i];
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        dp[i + 1] += dp[i - 1];
      }
    }
    return dp[s.size()];
  }
};
