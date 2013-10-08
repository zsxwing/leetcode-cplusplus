class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int row = 0; row < n / 2; row++) {
      for (int i = row; i < n - row - 1; i++) {
        int temp = matrix[row][i];
        matrix[row][i] = matrix[n - i - 1][row];
        matrix[n - i - 1][row] = matrix[n - row - 1][n - i - 1];
        matrix[n - row - 1][n - i - 1] = matrix[i][n - row - 1];
        matrix[i][n - row - 1] = temp;
      }
    }
  }
};
