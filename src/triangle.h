class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    size_t n = triangle.size();
    if (n == 0) {
      return 0;
    }
    vector<int> minSums(n, 0);
    minSums[0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      minSums[i] = minSums[i - 1] + triangle[i][i];
      for (int j = i - 1; j >= 1; j--) {
        minSums[j] = min(minSums[j - 1], minSums[j]) + triangle[i][j];
      }
      minSums[0] += triangle[i][0];
    }
    return *min_element(minSums.begin(), minSums.end());
  }
};
