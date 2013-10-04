class Solution {
public:
  int candy(vector<int> &ratings) {
    size_t n = ratings.size();
    vector<int> candies(n, 1);
    for (int k = 1, i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = ++k;
      } else {
        k = 1;
      }
    }
    for (int k = 1, i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candies[i] = max(candies[i], ++k);
      } else {
        k = 1;
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += candies[i];
    }
    return count;
  }
};
