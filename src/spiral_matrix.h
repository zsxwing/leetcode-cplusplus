class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> re;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return re;
    }
    int beginX = 0;
    int endX = matrix.size() - 1;
    int beginY = 0;
    int endY = matrix[0].size() - 1;
    while (beginX <= endX && beginY <= endY) {
      for (int i = beginY; i <= endY; i++) {
        re.push_back(matrix[beginX][i]);
      }
      for (int i = beginX + 1; i < endX; i++) {
        re.push_back(matrix[i][endY]);
      }
      if (beginX != endX) {
        for (int i = endY; i >= beginY; i--) {
          re.push_back(matrix[endX][i]);
        }
      }
      if (beginY != endY) {
        for (int i = endX - 1; i > beginX; i--) {
          re.push_back(matrix[i][beginY]);
        }
      }
      beginX++;
      endX--;
      beginY++;
      endY--;
    }
    return re;
  }
};
