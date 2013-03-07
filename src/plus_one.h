#include <vector>
using namespace std;

class Solution {

public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      digits[i] += carry;
      if (digits[i] >= 10) {
        digits[i] -= 10;
        carry = 1;
      } else {
        carry = 0;
        break;
      }
    }
    if (carry > 0) {
      digits.insert(digits.begin(), carry);
    }
    return digits;
  }
};
