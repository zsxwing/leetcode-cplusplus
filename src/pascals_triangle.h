class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector < vector<int> > pascal;
    if (numRows == 0) {
      return pascal;
    }
    vector<int> row(1, 1);
    pascal.push_back(row);
    for (int i = 1; i < numRows; i++) {
      vector<int> &lastRow = pascal.back();
      vector<int> row;
      row.push_back(1);
      for (int j = 1; j < i; j++) {
        row.push_back(lastRow[j - 1] + lastRow[j]);
      }
      row.push_back(1);
      pascal.push_back(row);
    }
    return pascal;
  }
};
