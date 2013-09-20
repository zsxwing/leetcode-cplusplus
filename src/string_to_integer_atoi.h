class Solution {
public:
  int atoi(const char *str) {
    int64_t i = 0;
    bool negative = false;
    while (*str == ' ') {
      str++;
    }
    if (*str == '+') {
      str++;
    } else if (*str == '-') {
      negative = true;
      str++;
    }
    while (*str >= '0' && *str <= '9') {
      i = i * 10 + *str - '0';
      if (negative && i > INT_MAX + 1LL) {
        return INT_MIN;
      }
      if (!negative && i > INT_MAX) {
        return INT_MAX;
      }
      str++;
    }
    if (negative) {
      i = -i;
    }
    return (int) i;
  }
};
