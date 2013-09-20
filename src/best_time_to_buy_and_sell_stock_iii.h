class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }

    int *subfixProfit = new int[prices.size()];
    int maxPrice = prices[prices.size() - 1];
    subfixProfit[prices.size() - 1] = 0;
    for (int i = prices.size() - 2; i >= 0; i--) {
      subfixProfit[i] = max(subfixProfit[i + 1], maxPrice - prices[i]);
      maxPrice = max(prices[i], maxPrice);
    }

    int maxProfit = subfixProfit[0];
    int minPrice = prices[0];
    for (int i = 1; i < prices.size() - 1; i++) {
      maxProfit = max(prices[i] - minPrice + subfixProfit[i], maxProfit);
      minPrice = min(prices[i], minPrice);
    }

    delete[] subfixProfit;
    return maxProfit;
  }
};
