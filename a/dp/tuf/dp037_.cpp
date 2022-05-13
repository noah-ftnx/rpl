#include <vector>
using namespace std;

long BF(int idx, bool can_buy, int tra, vector<int>& prices) {
  const int P = (int) prices.size();
  // base cases:
  if (idx==P) {  // considered all stocks
    return 0; // can no longer make profit
  } else if (tra==0) {  // used all allowed transactions
    // tra is when we sell (close transaction)
    return 0;
  }

  if (can_buy) {
    int buy=-prices[idx]+BF(idx+1, false, tra, prices);
    int dontBuy=BF(idx+1, true, tra, prices);
    return max(buy, dontBuy);
  } else {  // can sell
    int sell=prices[idx]+BF(idx+1, true, tra-1, prices);
    int dontSell=BF(idx+1, false, tra, prices);
    return max(sell, dontSell);
  }
}

long getMaximumProfitBF(vector<int>& prices) {
  const int P = (int) prices.size();
  return BF(0, true, 2, prices);
}



long MMZ(int idx, bool can_buy, int tra, vector<int>& prices,
        vector<vector<vector<int>>> &dp) {
  const int P = (int) prices.size();
  // base cases:
  if (idx==P) {  // considered all stocks
    return 0; // can no longer make profit
  } else if (tra==0) {  // used all allowed transactions
    // tra is when we sell (close transaction)
    return 0;
  } else if (dp[idx][can_buy][tra]!=-1) return dp[idx][can_buy][tra];

  if (can_buy) {
    int buy=-prices[idx]+MMZ(idx+1, false, tra, prices, dp);
    int dontBuy=MMZ(idx+1, true, tra, prices, dp);
    return dp[idx][can_buy][tra]=max(buy, dontBuy);
  } else {  // can sell
    int sell=prices[idx]+MMZ(idx+1, true, tra-1, prices, dp);
    int dontSell=MMZ(idx+1, false, tra, prices, dp);
    return dp[idx][can_buy][tra]=max(sell, dontSell);
  }
}

long getMaximumProfitMMZ(vector<int>& prices) {
  const int P = (int) prices.size();
  vector<vector<vector<int>>> dp (P+1,
                                 vector<vector<int>> (2, vector<int>(3,-1)));
  return MMZ(0, true, 2, prices, dp);
}



long getMaximumProfitBU(vector<int>& prices) {
  const int P = (int) prices.size();
  vector<vector<vector<long>>> dp (P+1,
                                  vector<vector<long>> (2, vector<long>(3, 0)));

  // base cases:
  // dp[P][can_buy][tra]: considered all stocks (no more profit)
  // dp[idx][can_buy][0]: used all transactions

  for (int idx=P-1; idx>=0; idx--) {
    for (int tra=1; tra<3; tra++) { // run 2 times
      // BUY CASE:
      int buy=-prices[idx]+dp[idx+1][0][tra];
      int dontBuy=dp[idx+1][1][tra];
      dp[idx][1][tra]=max(buy, dontBuy);

      // SELL CASE:
      int sell=prices[idx]+dp[idx+1][1][tra-1];
      int dontSell=dp[idx+1][0][tra];
      dp[idx][0][tra]=max(sell, dontSell);
    }
  }
  return dp[0][1][2];
}



long getMaximumProfitOPT(vector<int>& prices) {
  const int P = (int) prices.size();
  vector<vector<long>> prev, cur(2, vector<long>(3, 0));

  // base cases:
  // cur[can_buy][tra]: considered all stocks (no more profit)
  // dp[idx][can_buy][0]: used all transactions (not accessing in loop)

  for (int idx=P-1; idx>=0; idx--) {
    prev=cur;
    for (int tra=1; tra<3; tra++) { // run 2 times
      // BUY CASE:
      int buy=-prices[idx]+prev[0][tra];
      int dontBuy=prev[1][tra];
      cur[1][tra]=max(buy, dontBuy);

      // SELL CASE:
      int sell=prices[idx]+prev[1][tra-1];
      int dontSell=prev[0][tra];
      cur[0][tra]=max(sell, dontSell);
    }
  }
  return cur[1][2];
}



#include "test/dp037.h"
int main() {
  run_tests("BF", getMaximumProfitBF);
  run_tests("MMZ", getMaximumProfitMMZ);
  run_tests("BU", getMaximumProfitBU);
  run_tests("OPT", getMaximumProfitOPT);

  print_report();
  return 0;
}