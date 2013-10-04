class Solution {
public:
  int singleNumber(int A[], int n) {
    int bits[32] = { 0 };
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 32; k++) {
        if (A[i] & (1 << k)) {
          bits[k]++;
        }
      }
    }
    int ans = 0;
    for (int k = 0; k < 32; k++) {
      if (bits[k] % 3) {
        ans |= (1 << k);
      }
    }
    return ans;
  }
};
