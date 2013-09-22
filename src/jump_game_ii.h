class Solution {
public:
  int jump(int A[], int n) {
    int step = 0;
    int current = 0;
    int next = 0;
    for (int i = 0; i < n; i++) {
      if (i > current) {
        current = next;
        step++;
      }
      next = max(next, i + A[i]);
    }
    return step;
  }
};
