class Solution {
private:
  bool isOutOfBoard(vector<vector<char> > &board, int x, int y) {
    int w = board[0].size();
    int h = board.size();
    return x<0 || x>=w || y<0 || y>=h;
  }

  void flipEdge(vector<vector<char> > &board, int x, int y) {
    if(isOutOfBoard(board, x, y)){
      return;
    }
    if(board[y][x] == 'O') {
      board[y][x] = '+';
      flipEdge(board, x-1, y);
      flipEdge(board, x+1, y);
      flipEdge(board, x, y-1);
      flipEdge(board, x, y+1);
    }
  }
 
public:
  /**
   *     x
   *   -----w
   *   |XOXO
   * y |OXXX
   *   |XXXX
   *   h
   * h = 3, w = 4
   */
  void solve(vector<vector<char> > &board) {
    if(board.size() == 0 || board[0].size() == 0) {
      return;
    }
    int w = board[0].size();
    int h = board.size();
    for(int x=0;x<w;x++) {
      flipEdge(board, x, 0);
      flipEdge(board, x, h-1);
    }
    for(int y=0;y<h;y++) {
      flipEdge(board, 0, y);
      flipEdge(board, w-1, y);
    }

    for(int y=0;y<h;y++) {
      for(int x=0;x<w;x++) {
        if(board[y][x] =='O') {
          board[y][x] = 'X';
        }
        else if(board[y][x] == '+') {
          board[y][x] ='O';
        }
      }
    }
  }
};
