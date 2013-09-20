class Solution {
public:
  vector<string> letterCombinations(string digits) {
    string dict[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
        "wxyz" };
    vector < string > res;
    res.push_back("");
    for (int i = 0; i < digits.size(); i++) {
      int digit = digits[i] - '0';
      vector < string > candidates;
      for (int j = 0; j < dict[digit].size(); j++) {
        for (int k = 0; k < res.size(); k++) {
          candidates.push_back(res[k] + dict[digit][j]);
        }
      }
      res = candidates;
    }
    return res;
  }
};
