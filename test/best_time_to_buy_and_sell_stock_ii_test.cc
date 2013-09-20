#include "common.h"
#include "best_time_to_buy_and_sell_stock_ii.h"
#include <gtest/gtest.h>

TEST(BestTimeToBuyAndSellStockII, maxProfit) {
  Solution s;
  vector<int> prices;
  ASSERT_EQ(0, s.maxProfit(prices));
}
