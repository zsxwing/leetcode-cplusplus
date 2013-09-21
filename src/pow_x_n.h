class Solution {
public:
  double pow(double x, int n) {
    bool overflow = false;
    if (n == INT_MIN) {
      overflow = true;
      n++;
    }
    bool positive = n >= 0;
    n = abs(n);
    double re = 1;
    double pow = x;
    while (n) {
      if (n & 1) {
        re *= pow;
      }
      n >>= 1;
      pow *= pow;
    }
    if (positive) {
      return re;
    } else {
      return overflow ? 1 / (re * x) : 1 / re;
    }
  }
};
