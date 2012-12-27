class Solution {

public:
  void sortColors(int A[], int n) {
    int firstOne = -1;
    int firstTwo = -1;
    for (int i = 0; i < n; i++) {
      if (A[i] == 0) {
        if (firstOne >= 0) {
          A[firstOne++] = 0;
          if (firstTwo >= 0) {
            A[firstTwo++] = 1;
            A[i] = 2;
          } else {
            A[i] = 1;
          }
        } else if (firstTwo >= 0) {
          A[firstTwo++] = 0;
          A[i] = 2;
        }
      } else if (A[i] == 1) {
        if (firstTwo >= 0) {
          if (firstOne < 0) {
            firstOne = firstTwo;
          }
          A[firstTwo++] = 1;
          A[i] = 2;
        } else if (firstOne < 0) {
          firstOne = i;
        }
      } else {
        if (firstTwo < 0) {
          firstTwo = i;
        }
      }
    }
  }
};
