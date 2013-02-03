class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    if (A == NULL || n == 0) {
      return 1;
    }
    for (int i = 0; i < n; i++) {
      if (A[i] <= 0) {
        // Set to a irrelevant number so that we can ignore them.
        A[i] = n + 1;
      }
    }
    for (int i = 0; i < n; i++) {
      // If A[i] appears, we set the number in A[i] - 1 to the opposite number.
      int index = abs(A[i]) - 1;
      if (index < n && A[index] > 0) {
        A[index] = -A[index];
      }
    }
    // After the traversal, if a positive number i (1 <= i <= n) does not exists, then A[i-1] must be positive.
    // So the first i satisfying A[i-1] > 0 is the answer.
    for (int i = 0; i < n; i++) {
      if (A[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
