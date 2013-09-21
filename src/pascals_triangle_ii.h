class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> row;
    for (int i = 0; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        row[j] += row[j - 1];
      }
      row.push_back(1);
    }
    return row;
  }
};
