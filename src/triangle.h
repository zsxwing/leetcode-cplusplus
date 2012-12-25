#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    if (n == 0) {
      return 0;
    }
    int *minSums = new int[n];
    minSums[0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      vector<int> row = triangle[i];
      minSums[i] = minSums[i - 1] + row[i];
      for (int j = i - 1; j >= 1; j--) {
        minSums[j] = min(minSums[j - 1], minSums[j]) + row[j];
      }
      minSums[0] += row[0];
    }
    int minSum = minSums[0];
    for (int i = 1; i < n; i++) {
      if (minSum > minSums[i]) {
        minSum = minSums[i];
      }
    }
    delete[] minSums;
    return minSum;
  }
};
