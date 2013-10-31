class Solution {
private:
  bool search(vector<vector<char> > &board, int row, int column, int x, int y,
      string &word, int index) {
    if (index == word.size()) {
      return true;
    }
    if (x < 0 || x >= row || y < 0 || y >= column) {
      return false;
    }
    if (board[x][y] == '*' || word[index] != board[x][y]) {
      return false;
    }
    char c = board[x][y];
    board[x][y] = '*';
    bool re = search(board, row, column, x + 1, y, word, index + 1)
        || search(board, row, column, x - 1, y, word, index + 1)
        || search(board, row, column, x, y + 1, word, index + 1)
        || search(board, row, column, x, y - 1, word, index + 1);
    board[x][y] = c;
    return re;
  }

public:
  bool exist(vector<vector<char> > &board, string word) {
    int row = board.size();
    int column = board[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        if (board[i][j] == word[0]) {
          if (search(board, row, column, i, j, word, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
