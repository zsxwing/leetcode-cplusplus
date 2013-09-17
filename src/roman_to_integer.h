class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> symbols;
    symbols['M'] = 1000;
    symbols['D'] = 500;
    symbols['C'] = 100;
    symbols['L'] = 50;
    symbols['X'] = 10;
    symbols['V'] = 5;
    symbols['I'] = 1;

    int num = symbols[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; i--) {
      char c = s[i];
      char nextC = s[i + 1];
      if (symbols[c] < symbols[nextC]) {
        num -= symbols[c];
      } else {
        num += symbols[c];
      }
    }
    return num;
  }
};
