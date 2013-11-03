class Solution {
public:
  int numTrees(int n) {
    int c = 1;
    for (int i = 2; i <= n; i++) {
      c = c * 2 * (2 * i - 1) / (i + 1);
    }
    return c;
  }
};
