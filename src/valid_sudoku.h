class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    bool rows[9][9] = { false };
    bool columns[9][9] = { false };
    bool cells[9][9] = { false };
    for (int row = 0; row < 9; row++) {
      for (int column = 0; column < 9; column++) {
        if (board[row][column] == '.') {
          continue;
        }
        int num = board[row][column] - '1';
        if (rows[row][num] || columns[column][num]
            || cells[row / 3 * 3 + column / 3][num]) {
          return false;
        }
        rows[row][num] = columns[column][num] =
            cells[row / 3 * 3 + column / 3][num] = true;
      }
    }
    return true;
  }
};

