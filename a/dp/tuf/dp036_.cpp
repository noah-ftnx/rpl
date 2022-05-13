#include  <vector>
using namespace std;

int BF(int idx, bool can_buy, vector<int> &prices) {
  const int P = (int) prices.size();

  if (idx==P) {
    // base case: considered all stocks
    // cannot make any more profit
    // if holding a stock: it's ok. there'll be at least one
    // better path that didn't buy that stock
    return 0;
  }

  if (can_buy) {
    // case 1: buy the stock (charged for stock)
    int buy = -prices[idx] + BF(idx+1, false, prices);

    // case 2: skip buying this price
    int dontBuy = 0 + BF(idx+1, true, prices);

    return max(buy, dontBuy);
  } else { // can sell (but cannot buy)
    // case 1: sell the stock (get some money)
    int sell = prices[idx] + BF(idx+1, true, prices);
    // case 2: don't sell the stock
    int dontSell = 0 + BF(idx+1, false, prices);
    return max(sell, dontSell);
  }
}

long getMaximumProfitBF(vector<int> &prices) {
  return BF(0, true, prices);
}



int MMZ(int idx, bool can_buy, vector<int> &prices,
        vector<vector<int>> &dp) {
  const int P = (int) prices.size();

  if (idx==P) {  // base case: considered all stocks
    return 0;
  } else if (dp[idx][can_buy]!=-1) return dp[idx][can_buy];

  if (can_buy) {
    // case 1: buy the stock (charged for stock)
    int buy = -prices[idx] + MMZ(idx+1, false, prices, dp);

    // case 2: skip buying this price
    int dontBuy = 0 + MMZ(idx+1, true, prices, dp);

    return dp[idx][can_buy]=max(buy, dontBuy);
  } else { // can sell (but cannot buy)
    // case 1: sell the stock (get some money)
    int sell = prices[idx] + MMZ(idx+1, true, prices, dp);
    // case 2: don't sell the stock
    int dontSell = 0 + MMZ(idx+1, false, prices, dp);
    return dp[idx][can_buy]=max(sell, dontSell);
  }
}

long getMaximumProfitMMZ(vector<int> &prices) {
  const int P = (int) prices.size();
  vector<vector<int>> dp (P+1, vector<int>(2, -1));
  return MMZ(0, true, prices, dp);
}



long getMaximumProfitBU(vector<int> &prices) {
  const int P = (int) prices.size();
  vector<vector<int>> dp (P+1, vector<int>(2, 0));

  // base case: considered all stocks
  // idx==P: 0 (covered by initialization)

  for (int idx=P-1; idx>=0; idx--) {
    // CHECK BUY:
    // case 1: buy the stock (charged for stock)
    int buy = -prices[idx] + dp[idx+1][false];
    // case 2: skip buying this price
    int dontBuy = 0 + dp[idx+1][true];

    dp[idx][1]=max(buy, dontBuy);

    // CHECK SELL:
    // case 1: sell the stock (get some money)
    int sell = prices[idx] + dp[idx+1][true];
    // case 2: don't sell the stock
    int dontSell = 0 + dp[idx+1][false];
    dp[idx][0]=max(sell, dontSell);
  }
  return dp[0][true];
}



long getMaximumProfitOPT(vector<int> &prices) {
  const int P = (int) prices.size();
  vector<int> prev(2,0), cur(2, 0);

  // base case: considered all stocks
  // idx==P: 0 (covered by initialization)

  for (int idx=P-1; idx>=0; idx--) {
    prev=cur;

    // BUY:
    // case 1: buy the stock (charged for stock)
    int buy = -prices[idx] + prev[0];
    // case 2: skip buying this price
    int dontBuy = 0 + prev[1];

    cur[1]=max(buy, dontBuy);

    // SELL:
    // case 1: sell the stock (get some money)
    int sell = prices[idx] + prev[1];
    // case 2: don't sell the stock
    int dontSell = 0 + prev[0];
    cur[0]=max(sell, dontSell);
  }
  return cur[true];
}



#include "test/dp036.h"
int main() {
  run_tests("BF", getMaximumProfitBF);
  run_tests("MMZ", getMaximumProfitMMZ);
  run_tests("BU", getMaximumProfitBU);
  run_tests("OPT", getMaximumProfitOPT);

  print_report();
  return 0;
}