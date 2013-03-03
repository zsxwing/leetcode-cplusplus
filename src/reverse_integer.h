class Solution {
public:
  int reverse(int x) {
    bool minus = false;
    if (x < 0) {
      x = -x;
      minus = true;
    }
    int y = 0;
    while (x) {
      y = y * 10 + x % 10;
      x /= 10;
    }
    return minus ? -y : y;
  }
};
