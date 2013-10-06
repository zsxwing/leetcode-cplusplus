class Solution {
private:
  int lowerBound(int A[], int low, int high, int target) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (A[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

  // Practice how to get the upper bound
  int upperBound(int A[], int low, int high, int target) {
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (A[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return high;
  }

public:
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> re;
    int begin = lowerBound(A, 0, n - 1, target);
    if (begin < n && A[begin] == target) {
      int end = lowerBound(A, begin + 1, n - 1, target + 1) - 1;
      re.push_back(begin);
      re.push_back(end);
    } else {
      re.push_back(-1);
      re.push_back(-1);
    }
    return re;
  }
};
