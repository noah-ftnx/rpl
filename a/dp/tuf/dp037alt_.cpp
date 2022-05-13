#include <vector>
using namespace std;

long BF(int idx, int tra, vector<int>& prices) {
  const int P = (int) prices.size();

  // consumed all transactions
  // or considered all stock prices
  if (tra==0 || idx==P) return 0;

  if (tra%2==0) { // buy
    int buy=-prices[idx]+BF(idx+1, tra-1, prices);
    int dontBuy=BF(idx+1, tra, prices);
    return max(buy, dontBuy);
  } else { // sell
    int sell=prices[idx]+BF(idx+1, tra-1, prices);
    int dontSell=BF(idx+1, tra, prices);
    return max(sell, dontSell);
  }
}

long getMaximumProfitBF(vector<int>& prices) {
  // 0, 1, 2, 3:
  // 4: buy  1 even
  // 3: sell 1 odd
  // 2: buy  2 even
  // 1: sell 2 odd
  // 0: base case
  return BF(0, 4, prices);
}



long MMZ(int idx, int tra, vector<int>& prices, vector<vector<long>> &dp) {
  const int P = (int) prices.size();

  // consumed all transactions
  // or considered all stock prices
  if (tra==0 || idx==P) return 0;
  else if (dp[idx][tra]!=-1) return dp[idx][tra];

  if (tra%2==0) { // buy
    int buy=-prices[idx]+MMZ(idx+1, tra-1, prices, dp);
    int dontBuy=MMZ(idx+1, tra, prices, dp);
    return dp[idx][tra]=(max(buy, dontBuy));
  } else { // sell
    int sell=prices[idx]+MMZ(idx+1, tra-1, prices, dp);
    int dontSell=MMZ(idx+1, tra, prices, dp);
    return dp[idx][tra]=(max(sell, dontSell));
  }
}

long getMaximumProfitMMZ(vector<int>& prices) {
  // 0, 1, 2, 3:
  // 4: buy  1 even
  // 3: sell 1 odd
  // 2: buy  2 even
  // 1: sell 2 odd
  // 0: base case
  const int P = (int) prices.size();
  if (P<=1) return 0;
  vector<vector<long>> dp(P+1, vector<long>(5, -1));
 return MMZ(0, 4, prices, dp);
}



long getMaximumProfitBU(vector<int>& prices) {
  // 0, 1, 2, 3:
  // 4: buy  1 even
  // 3: sell 1 odd
  // 2: buy  2 even
  // 1: sell 2 odd
  // 0: base case
  const int P = (int) prices.size();
  if (P<=1) return 0;
  vector<vector<long>> dp(P+1, vector<long>(5, 0));

  // base cases
  // dp[idx][0] : consumed all transactions
  // dp[P][tra]: considered all stock prices

  for (int idx=P-1; idx>=0; idx--) {
    for (int tra=1; tra<=4; tra++)
      if (tra%2==0) { // buy
        int buy=-prices[idx]+dp[idx+1][tra-1];
        int dontBuy=dp[idx+1][tra];
        dp[idx][tra]=max(buy, dontBuy);
      } else { // sell
        int sell=prices[idx]+dp[idx+1][tra-1];
        int dontSell=dp[idx+1][tra];
        dp[idx][tra]=max(sell, dontSell);
      }
  }
  return dp[0][4];
}



long getMaximumProfitOPT(vector<int>& prices) {
  // 0, 1, 2, 3:
  // 4: buy  1 even
  // 3: sell 1 odd
  // 2: buy  2 even
  // 1: sell 2 odd
  // 0: base case
  const int P = (int) prices.size();
  if (P<=1) return 0;
  vector<long> prev, cur(5, 0);

  // base cases
  // dp[idx][0] : consumed all transactions
  // dp[P][tra]: considered all stock prices

  for (int idx=P-1; idx>=0; idx--) {
    prev=cur;
    for (int tra=1; tra<=4; tra++)
      if (tra%2==0) { // buy
        int buy=-prices[idx]+prev[tra-1];
        int dontBuy=prev[tra];
        cur[tra]=max(buy, dontBuy);
      } else { // sell
        int sell=prices[idx]+prev[tra-1];
        int dontSell=prev[tra];
        cur[tra]=max(sell, dontSell);
      }
  }
  return cur[4];
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