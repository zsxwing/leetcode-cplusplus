class Solution {
public:
  int removeDuplicates(int A[], int n) {
    bool twice = false;
    int last = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 || A[i] != A[i - 1]) {
        A[last++] = A[i];
        twice = false;
      } else if (!twice) {
        twice = true;
        A[last++] = A[i];
      }
    }
    return last;
  }
};
