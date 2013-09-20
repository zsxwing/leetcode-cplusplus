class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int maxProfit = 0;
    int minPurchasePrice = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      maxProfit = max(prices[i] - minPurchasePrice, maxProfit);
      minPurchasePrice = min(prices[i], minPurchasePrice);
    }
    return maxProfit;
  }
};
