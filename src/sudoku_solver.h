class Solution {
private:
  bool isValid(vector<vector<char> > &board, int row, int column, char c) {
    int cellRow = row - row % 3;
    int cellColumn = column - column % 3;
    for (int i = 0; i < 9; i++) {
      if (board[i][column] == c || board[row][i] == c
          || board[cellRow + i / 3][cellColumn + i % 3] == c) {
        return false;
      }
    }
    return true;
  }

  bool trySolveSudoku(vector<vector<char> > &board, int pos) {
    while (pos < 81) {
      if (board[pos / 9][pos % 9] == '.') {
        break;
      }
      pos++;
    }
    if (pos == 81) {
      return true;
    }
    int row = pos / 9;
    int column = pos % 9;
    for (char k = '1'; k <= '9'; k++) {
      if (isValid(board, row, column, k)) {
        board[row][column] = k;
        if (trySolveSudoku(board, pos + 1)) {
          return true;
        }
      }
    }
    board[row][column] = '.';
    return false;
  }

public:
  void solveSudoku(vector<vector<char> > &board) {
    trySolveSudoku(board, 0);
  }
};
