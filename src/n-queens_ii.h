class Solution {
private:
  void totalNQueens(int row, int leftDiagonal, int rightDiagonal, int upper,
      int *total) {
    if (row != upper) {
      int validPositions = upper & (~(row | leftDiagonal | rightDiagonal));
      while (validPositions) {
        int position = validPositions & (-validPositions);
        validPositions = validPositions - position;
        totalNQueens(row + position, (leftDiagonal + position) >> 1,
            (rightDiagonal + position) << 1, upper, total);
      }
    } else {
      ++*total;
    }
  }

public:
  int totalNQueens(int n) {
    int total = 0;
    totalNQueens(0, 0, 0, (1 << n) - 1, &total);
    return total;
  }
};
