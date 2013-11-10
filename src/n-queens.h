class Solution {

private:
  bool isValid(vector<int> &columns, int row, int column) {
    for (int i = 0; i < columns.size(); i++) {
      if (columns[i] == column || abs(row - i) == abs(column - columns[i])) {
        return false;
      }
    }
    return true;
  }

  void solveNQueens(vector<vector<string> > &re, vector<int> &columns, int row,
      int n) {
    if (row == n) {
      vector < string > solution;
      for (int i = 0; i < n; i++) {
        string line;
        int column = columns[i];
        line.append(column, '.');
        line += 'Q';
        line.append(n - column - 1, '.');
        solution.push_back(line);
      }
      re.push_back(solution);
    }

    for (int column = 0; column < n; column++) {
      if (isValid(columns, row, column)) {
        columns.push_back(column);
        solveNQueens(re, columns, row + 1, n);
        columns.pop_back();
      }
    }
  }

public:
  vector<vector<string> > solveNQueens(int n) {
    vector < vector<string> > re;
    vector<int> columns;
    solveNQueens(re, columns, 0, n);
    return re;
  }
};
