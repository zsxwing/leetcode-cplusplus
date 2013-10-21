class Solution {
public:
  bool search(int A[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (A[mid] == target) {
        return true;
      }
      if (A[left] < A[mid]) {
        if (A[left] <= target && target < A[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (A[left] > A[mid]) {
        if (A[mid] < target && target <= A[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        left++;
      }
    }
    return false;
  }
};
