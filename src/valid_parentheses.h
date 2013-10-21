class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        stack.push_back(s[i]);
      } else if (stack.empty()) {
        return false;
      } else {
        char left = stack.back();
        stack.pop_back();
        if (left == '(' && s[i] == ')') {
          continue;
        }
        if (left == '[' && s[i] == ']') {
          continue;
        }
        if (left == '{' && s[i] == '}') {
          continue;
        }
        return false;
      }
    }
    return stack.empty();
  }
};
