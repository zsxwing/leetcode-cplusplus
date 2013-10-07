class Solution {
public:
  // Try to implement without long
  int divide(int dividend, int divisor) {
    assert(divisor != 0);
    if (divisor == INT_MIN) {
      return dividend == INT_MIN ? 1 : 0;
    }
    bool negative = (dividend < 0) ^ (divisor < 0);
    divisor = abs(divisor);
    bool overflow = dividend == INT_MIN;
    if (overflow) {
      dividend += divisor;
    }
    dividend = abs(dividend);
    int pow = divisor;
    while ((pow << 1) > 0 && dividend >= (pow << 1)) {
      pow <<= 1;
    }
    int re = 0;
    while (pow >= divisor) {
      re <<= 1;
      if (dividend >= pow) {
        dividend -= pow;
        re += 1;
      }
      pow >>= 1;
    }
    if (overflow) {
      re += 1;
    }
    return negative ? -re : re;
  }
};
