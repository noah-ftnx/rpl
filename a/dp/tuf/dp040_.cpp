#include <vector>
using namespace std;

int BF(int idx, bool can_buy, const int &fee, vector<int> &prices) {
  const int P = (int) prices.size();
  // base case: considered all the prices
  if (idx==P) return 0; // no longer make a profit

  if (can_buy) {
    int buy=-prices[idx]+BF(idx+1, false, fee, prices);
    int dontBuy=BF(idx+1, true, fee, prices);
    return max(buy, dontBuy);
  } else { // can sell
    int sell= prices[idx]-fee+BF(idx+1, true, fee, prices);
    int dontSell=BF(idx+1, false, fee, prices);
    return max(sell, dontSell);
  }
}

int maximumProfitBF(int fee, vector<int> &prices) {
  return BF(0, true, fee, prices);
}



int MMZ(int idx, bool can_buy, const int &fee, vector<int> &prices,
        vector<vector<int>> &dp) {
  const int P = (int) prices.size();
  // base case: considered all the prices
  if (idx==P) return 0; // no longer make a profit

  if (dp[idx][can_buy]!=-1) return dp[idx][can_buy];

  if (can_buy) {
    int buy=-prices[idx]+MMZ(idx+1, false, fee, prices, dp);
    int dontBuy=MMZ(idx+1, true, fee, prices, dp);
    return dp[idx][can_buy]=max(buy, dontBuy);
  } else { // can sell
    int sell= prices[idx]-fee+MMZ(idx+1, true, fee, prices, dp);
    int dontSell=MMZ(idx+1, false, fee, prices, dp);
    return dp[idx][can_buy]=max(sell, dontSell);
  }
}

int maximumProfitMMZ(int fee, vector<int> &prices) {
  const int P = (int) prices.size();
  vector<vector<int>> dp (P+1, vector<int>(2, -1));
  return MMZ(0, true, fee, prices, dp);
}



int maximumProfitBU(int fee, vector<int> &prices) {
  const int P = (int) prices.size();
  vector<vector<int>> dp (P+1, vector<int>(2, 0));

  // base case: considered all the prices
  // dp[P][.]=0  // no longer make a profit (dealt w/ dp init)

  for (int idx=P-1; idx>=0; idx--) {
    // BUY:
    int buy=-prices[idx]+dp[idx+1][0];
    int dontBuy=dp[idx+1][1];
    dp[idx][1]=max(buy, dontBuy);

    // SELL:
    int sell= prices[idx]-fee+dp[idx+1][1];
    int dontSell=dp[idx+1][0];
    dp[idx][0]=max(sell, dontSell);
  }

  return dp[0][1];
}



int maximumProfitOPT(int fee, vector<int> &prices) {
  const int P = (int) prices.size();
  vector<int> prev, cur(2, 0);

  // base case: considered all the prices
  // dp[P][.]=0  // no longer make a profit (dealt w/ dp init)

  for (int idx=P-1; idx>=0; idx--) {
    prev=cur;
    // BUY:
    int buy=-prices[idx]+prev[0];
    int dontBuy=prev[1];
    cur[1]=max(buy, dontBuy);

    // SELL:
    int sell= prices[idx]-fee+prev[1];
    int dontSell=prev[0];
    cur[0]=max(sell, dontSell);
  }
  return cur[1];
}



int maximumProfitOPT2(int fee, vector<int> &prices) {
  const int P = (int) prices.size();
  vector<int> row(2, 0);

  // base case: considered all the prices
  // dp[P][.]=0  // no longer make a profit (dealt w/ dp init)

  for (int idx=P-1; idx>=0; idx--) {
    // BUY:
    int buy=-prices[idx]+row[0]; // STALE LEFT DATA
    int dontBuy=row[1];

    // SELL:
    int sell= prices[idx]-fee+row[1];
    int dontSell=row[0];

    // updating
    row[0]=max(sell, dontSell);
    row[1]=max(buy, dontBuy);
  }
  return row[1];
}













#include "test/dp040.h"
int main() {
  run_tests("BF", maximumProfitBF);
  run_tests("MMZ", maximumProfitMMZ);
  run_tests("BU", maximumProfitBU);
  run_tests("OPT", maximumProfitOPT);
  run_tests("OPT2", maximumProfitOPT2);

  print_report();
  return 0;
}