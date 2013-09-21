class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int middle = low + (high - low) / 2;
      if (A[middle] < target) {
        low = middle + 1;
      } else if (A[middle] > target) {
        high = middle - 1;
      } else {
        return middle;
      }
    }
    return low;
  }
};
