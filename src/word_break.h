class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    assert(!s.empty());
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++) {
      dp[i] = false;
      for (int j = 0; j < i; j++) {
        if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};
