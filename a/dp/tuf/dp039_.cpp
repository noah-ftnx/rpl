#include <vector>
using namespace std;

int BF(int idx, bool can_buy, vector<int> &prices) {
  // base cases:
  // considered all indices (P)
  const int P = (int) prices.size();
  if (idx>=P) return 0; // possible values: P, or P+1


  if (can_buy) {
    int buy=-prices[idx]+BF(idx+1, false, prices);
    int dontBuy=BF(idx+1, true, prices);
    return max(buy, dontBuy);
  } else { // can sell
    // enforcing cooldown on sell. (how about OOB?)
    int sell=prices[idx]+BF(idx+2, true, prices); // ENFORCE COOLDOWN!
    int dontSell=BF(idx+1, false, prices);
    return max(sell, dontSell);
  }
}

int stockProfitBF(vector<int> &prices){
  return BF(0, true, prices);
}



int MMZ(int idx, bool can_buy, vector<int> &prices, vector<vector<int>> &dp) {
  // base cases:
  // considered all indices (P)
  const int P = (int) prices.size();
  if (idx>=P) return 0; // possible values: P, or P+1

  if (dp[idx][can_buy]!=-1) return dp[idx][can_buy];

  if (can_buy) {
    int buy=-prices[idx]+MMZ(idx+1, false, prices, dp);
    int dontBuy=MMZ(idx+1, true, prices, dp);
    return dp[idx][can_buy]=max(buy, dontBuy);
  } else { // can sell
    // enforcing cooldown on sell. (how about OOB?)
    int sell=prices[idx]+MMZ(idx+2, true, prices, dp); // ENFORCE COOLDOWN!
    int dontSell=MMZ(idx+1, false, prices, dp);
    return dp[idx][can_buy]=max(sell, dontSell);
  }
}

int stockProfitMMZ(vector<int> &prices){
  const int P = (int) prices.size();
  vector<vector<int>> dp(P+2, vector<int>(2, -1));
  return MMZ(0, true, prices, dp);
}



int stockProfitBU(vector<int> &prices){
  const int P = (int) prices.size();
  vector<vector<int>> dp(P+2, vector<int>(2, 0));

  // base cases: considered all indices:
  // no more profit (handled by dp init)
  // dp[P][*]=0
  // dp[P+1][*]=0

  for (int idx=P-1; idx>=0; idx--) {

    // BUY CASE:
    int buy=-prices[idx]+dp[idx+1][0];
    int dontBuy=dp[idx+1][1];
    dp[idx][1]=max(buy, dontBuy);

    // SELL CASE:
    // enforcing cooldown on sell.
    int sell=prices[idx]+dp[idx+2][1];
    int dontSell=dp[idx+1][0];
    dp[idx][0]=max(sell, dontSell);
  }

  return dp[0][true];
}



int stockProfitOPT(vector<int> &prices){
  const int P = (int) prices.size();
  vector<int> prev2, prev1, cur(2, 0);
  prev2=prev1=cur;

  // base cases: considered all indices:
  // no more profit (handled by dp init)
  // dp[P][*]=0
  // dp[P+1][*]=0

  for (int idx=P-1; idx>=0; idx--) {
    prev2=prev1;
    prev1=cur;
    // BUY CASE:
    int buy=-prices[idx]+prev1[0];
    int dontBuy=prev1[1];
    cur[1]=max(buy, dontBuy);

    // SELL CASE:
    // enforcing cooldown on sell.
    int sell=prices[idx]+prev2[1];
    int dontSell=prev2[0];
    cur[0]=max(sell, dontSell);
  }
  return cur[true];
}



#include "test/dp039.h"
int main() {
  run_tests("BF", stockProfitBF);
  run_tests("MMZ", stockProfitMMZ);
  run_tests("BU", stockProfitBU);
  run_tests("OPT", stockProfitOPT);

  print_report();
  return 0;
}