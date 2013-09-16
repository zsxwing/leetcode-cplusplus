class Solution {
public:
  int maxArea(vector<int> &height) {
    int start = 0;
    int end = height.size() - 1;
    int maxArea = 0;
    while (start < end) {
      if (height[start] < height[end]) {
        int area = (end - start) * height[start];
        if (area > maxArea) {
          maxArea = area;
        }
        start++;
      } else {
        int area = (end - start) * height[end];
        if (area > maxArea) {
          maxArea = area;
        }
        end--;
      }
    }
    return maxArea;
  }
};
