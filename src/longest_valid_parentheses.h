class Solution {
public:
  int longestValidParentheses(string s) {
    int longest = 0;
    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        int prev = i - 1;
        while (prev >= 0) {
          if (s[prev] == '(') {
            dp[i] = i - prev + 1 + (prev > 0 ? dp[prev - 1] : 0);
            longest = max(dp[i], longest);
            break;
          } else if (dp[prev] == 0) {
            break;
          }
          prev = prev - dp[prev];
        }
      }
    }
    return longest;
  }
};
