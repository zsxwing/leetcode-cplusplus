class Solution {
private:
  void search(string &s, int begin, vector<int> &solution,
      vector<string> &solutions) {
    if (begin == s.size() && solution.size() == 4) {
      stringstream s;
      s << solution[0] << '.' << solution[1] << '.' << solution[2] << '.'
          << solution[3];
      solutions.push_back(s.str());
      return;
    }
    if (s.length() - begin > (4 - solution.size()) * 3) {
      return;
    }
    if (s.length() - begin < 4 - solution.size()) {
      return;
    }
    int num = 0;
    for (int i = begin; i < min(begin + 3, (int) s.size()); i++) {
      num = num * 10 + s[i] - '0';
      if (num < 256) {
        solution.push_back(num);
        search(s, i + 1, solution, solutions);
        solution.pop_back();
      }
      if (num == 0) {
        break;
      }
    }
  }
public:
  vector<string> restoreIpAddresses(string s) {
    vector < string > solutions;
    vector<int> solution;
    search(s, 0, solution, solutions);
    return solutions;
  }
};
