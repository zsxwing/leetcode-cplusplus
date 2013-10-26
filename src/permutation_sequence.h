class Solution {
private:
  int prod(int n) {
    int prod = 1;
    for (int i = 1; i <= n; i++) {
      prod *= i;
    }
    return prod;
  }

public:
  string getPermutation(int n, int k) {
    vector<int> digits;
    for (int i = 1; i <= n; i++) {
      digits.push_back(i);
    }
    string num = "";
    k--;
    while (digits.size() > 1) {
      int p = prod(digits.size() - 1);
      auto i = digits.begin() + (k / p);
      num += '0' + *i;
      digits.erase(i);
      k %= p;
    }
    num += '0' + digits[0];
    return num;
  }
};
