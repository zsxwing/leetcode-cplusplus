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
    symbols['\0'] = 0;

    const char *str = s.c_str();
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = str[i];
      char nextC = str[i + 1];
      if (symbols[c] < symbols[nextC]) {
        num -= symbols[c];
      } else {
        num += symbols[c];
      }
    }
    return num;
  }
};
