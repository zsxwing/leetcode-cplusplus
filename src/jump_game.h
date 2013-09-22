class Solution {
public:
  bool canJump(int A[], int n) {
    int far = 0;
    for (int i = 0; i < n && i <= far; i++) {
      far = max(far, i + A[i]);
    }
    return far >= n - 1;
  }
};
