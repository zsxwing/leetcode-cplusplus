class Solution {
public:
  int sqrt(int n) {
    double delta = 10E-6;
    double x = 1.0;
    double y = x * x - n;
    while (abs(y) > delta) {
      x = x - y / (2 * x);
      y = x * x - n;
    }
    return x;
  }
};
