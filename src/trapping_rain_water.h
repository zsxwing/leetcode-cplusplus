class Solution {
public:
  int trap(int A[], int n) {
    if (n == 0)
      return 0;
    int maxIndex = distance(A, max_element(A, A + n));
    int water = 0;
    int height = A[0];
    for (int i = 1; i < maxIndex; i++) {
      if (A[i] > height) {
        height = A[i];
      } else {
        water += height - A[i];
      }
    }
    height = A[n - 1];
    for (int i = n - 2; i > maxIndex; i--) {
      if (A[i] > height) {
        height = A[i];
      } else {
        water += height - A[i];
      }
    }
    return water;
  }
};
