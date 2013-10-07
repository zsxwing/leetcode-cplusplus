class Solution {
private:
  vector<string> searchWordBreak(string &s, unordered_set<string> &dict,
      unordered_map<string, vector<string>> &solutions) {
    auto iter = solutions.find(s);
    if (iter != solutions.end()) {
      return iter->second;
    }
    vector < string > solution;
    for (int i = 1; i < s.size(); i++) {
      string prefix = s.substr(0, i);
      if (dict.find(prefix) != dict.end()) {
        string subfix = s.substr(i, s.size() - i);
        vector < string > subSolution = searchWordBreak(subfix, dict,
            solutions);
        for (int j = 0; j < subSolution.size(); j++) {
          solution.push_back(prefix + " " + subSolution[j]);
        }
      }
    }
    if (dict.find(s) != dict.end()) {
      solution.push_back(s);
    }
    solutions[s] = solution;
    return solution;
  }

public:
  vector<string> wordBreak(string &s, unordered_set<string> &dict) {
    unordered_map < string, vector < string >> solutions;
    return searchWordBreak(s, dict, solutions);
  }
};
