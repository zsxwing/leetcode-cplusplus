class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int elemCount = 0;
    for (int i = 0; i < n; i++) {
      if (A[i] == elem) {
        elemCount++;
      } else if (elemCount) {
        A[i - elemCount] = A[i];
      }
    }
    return n - elemCount;
  }
};
