class Solution {
public:
  string addBinary(string a, string b) {
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    string re;
    while (i >= 0 || j >= 0 || carry > 0) {
      int digitA = i < 0 ? 0 : (a[i] - '0');
      int digitB = j < 0 ? 0 : (b[j] - '0');
      re += '0' + ((digitA + digitB + carry) % 2);
      carry = (digitA + digitB + carry) / 2;
      i--;
      j--;
    }
    reverse(re.begin(), re.end());
    return re;
  }
};
