class Solution {
public:
  int minCut(string s) {
    if (s.empty()) {
      return 0;
    }
    vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
    vector<int> dp(s.size() + 1, -1);
    for (int i = 1; i <= s.size(); i++) {
      dp[i] = i - 1;
    }
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j <= i; j++) {
        if (s[i] == s[j] && (i - j < 2 || isPalindrome[j + 1][i - 1])) {
          isPalindrome[j][i] = true;
          dp[i + 1] = min(dp[i + 1], dp[j] + 1);
        }
      }
    }
    return dp[s.size()];
  }
};
