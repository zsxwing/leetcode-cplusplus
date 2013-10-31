class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector < vector<int> > matrix(n, vector<int>(n, 0));
    int current = 0;
    int begin = 0;
    int end = n - 1;
    while (begin <= end) {
      for (int i = begin; i <= end; i++) {
        matrix[begin][i] = ++current;
      }

      for (int i = begin + 1; i < end; i++) {
        matrix[i][end] = ++current;
      }

      if (begin != end) {
        for (int i = end; i >= begin; i--) {
          matrix[end][i] = ++current;
        }
        for (int i = end - 1; i > begin; i--) {
          matrix[i][begin] = ++current;
        }
      }
      begin++;
      end--;
    }
    return matrix;
  }
};
