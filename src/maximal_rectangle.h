class Solution {
private:
  int largestRectangleArea(vector<int>& height) {
    stack<int> p;
    int i = 0;
    int maxArea = 0;
    while (i < height.size()) {
      if (p.empty() || height[p.top()] <= height[i]) {
        p.push(i++);
      } else {
        int pos = p.top();
        p.pop();
        maxArea = max(maxArea,
            (p.empty() ? i : (i - p.top() - 1)) * height[pos]);
      }
    }
    return maxArea;
  }

public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> height(n + 1, 0);
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          height[j]++;
        } else {
          height[j] = 0;
        }
      }
      maxArea = max(maxArea, largestRectangleArea(height));
    }
    return maxArea;
  }
};
