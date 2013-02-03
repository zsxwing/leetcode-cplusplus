class Solution {
public:
  bool isPalindrome(int x) {
    if (x == 0) {
      return true;
    }
    if (x < 0 || x % 10 == 0) {
      return false;
    }
    int y = 0;
    do {
      if (y == (x / 10)) {
        return true;
      }
      y = y * 10 + x % 10;
      x /= 10;
    } while (y < x);
    return y == x;
  }
};
