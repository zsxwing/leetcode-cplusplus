class Solution {
public:
  int reverse(int x) {
    // Minor revision for this question: if overflow, return
    // INT_MIN or INT_MAX
    if (x == INT_MIN) {
      return x;
    }
    bool overflow = false;
    bool negative = x < 0;
    x = abs(x);
    int y = 0;
    while (x) {
      if (INT_MAX / 10 < y) {
        overflow = true;
        break;
      }
      y *= 10;
      int mod = x % 10;
      if (INT_MAX - mod < y) {
        overflow = true;
        break;
      }
      y += mod;
      x /= 10;
    }
    if (overflow) {
      return negative ? INT_MIN : INT_MAX;
    }
    return negative ? -y : y;
  }
};
