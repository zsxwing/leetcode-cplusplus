class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    stack<int> p;
    int maxArea = 0;
    height.push_back(0);
    int i = 0;
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
};
