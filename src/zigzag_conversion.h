#include <string>
using namespace std;

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows == 1) {
      return s;
    }
    string r;
    for (int row = 0; row < nRows; row++) {
      int i = row;
      while (i < s.size()) {
        r += s[i];
        if (row != 0 && row != nRows - 1) {
          int neighbor = (i + 2 * (nRows - 1) - 2 * row);
          if (neighbor < s.size()) {
            r += s[neighbor];
          }
        }
        i += 2 * (nRows - 1);
      }
    }
    return r;
  }
};
