class Solution {
private:
  void generateParenthesis(vector<string>& ans, char *s, int left, int right,
      int n) {
    if (left == n) {
      fill(s + (left + right), s + (n << 1), ')');
      ans.push_back(string(s, n << 1));
      return;
    }
    s[left + right] = '(';
    generateParenthesis(ans, s, left + 1, right, n);
    if (left > right) {
      s[left + right] = ')';
      generateParenthesis(ans, s, left, right + 1, n);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector < string > ans;
    char *s = new char[n << 1];
    generateParenthesis(ans, s, 0, 0, n);
    delete[] s;
    return ans;
  }
};
