class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0) {
      return false;
    }
    int columns = matrix[0].size();
    int low = 0;
    int high = matrix.size() * columns - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int midValue = matrix[mid / columns][mid % columns];
      if (midValue < target) {
        low = mid + 1;
      } else if (midValue > target) {
        high = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
