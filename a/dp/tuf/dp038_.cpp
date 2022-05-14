#include <vector>
using namespace std;

int BF(int idx, int tra, vector<int> &prices) {
  const int P = (int) prices.size();

  // base cases: can make no more profit
  if (idx == P) return 0; 	// considered all stock prices
  else if (tra==0) return 0; // did all transactions

  if (tra % 2 == 0) { // can buy
    int buy=-prices[idx]+BF(idx+1, tra-1, prices);
    int dontBuy=0+BF(idx+1, tra, prices);
    return max(buy, dontBuy);
  } else { // can sell
    int sell=prices[idx]+BF(idx+1, tra-1, prices);
    int dontSell=0+BF(idx+1, tra, prices);
    return max(sell, dontSell);
  }
}

int maximumProfitBF(vector<int> &prices, int k) {
  if (k<=0) return 0;
  return BF(0, 2*k, prices);
}



int MMZ(int idx, int tra, vector<int> &prices, vector<vector<int>> &dp) {
  const int P = (int) prices.size();

  // base cases: can make no more profit
  if (idx == P) return 0; 	// considered all stock prices
  else if (tra==0) return 0; // did all transactions

  if (dp[idx][tra]!=-1) return dp[idx][tra];

  if (tra % 2 == 0) { // can buy
    int buy=-prices[idx]+MMZ(idx+1, tra-1, prices, dp);
    int dontBuy=0+MMZ(idx+1, tra, prices, dp);
    return dp[idx][tra]=max(buy, dontBuy);
  } else { // can sell
    int sell=prices[idx]+MMZ(idx+1, tra-1, prices, dp);
    int dontSell=0+MMZ(idx+1, tra, prices, dp);
    return dp[idx][tra]=max(sell, dontSell);
  }
}

int maximumProfitMMZ(vector<int> &prices, int k) {
  const int P = (int) prices.size();
  if (k<=0) return 0;
  int K = 2*k; // all (buy&sell) transactions
  vector<vector<int>> dp (P+1, vector<int>(K+1, -1));
  return MMZ(0, 2*k, prices, dp);
}



int maximumProfitBU(vector<int> &prices, int k) {
  const int P = (int) prices.size();
  if (k<=0) return 0;
  int K = 2*k; // all (buy&sell) transactions
  vector<vector<int>> dp (P+1, vector<int>(K+1, 0));

  // base cases: can make no more profit
  // dp[P][tra]=0: considered all stock prices
  // dp[idx][0]=0:	did all transactions

  for (int idx=P-1; idx>=0; idx--) {
    for (int tra=1; tra<=K; tra++) {

      if (tra % 2 == 0) { // can buy
        int buy=-prices[idx]+dp[idx+1][tra-1];
        int dontBuy=0+dp[idx+1][tra];
        dp[idx][tra]=max(buy, dontBuy);
      } else { // can sell
        int sell=prices[idx]+dp[idx+1][tra-1];
        int dontSell=0+dp[idx+1][tra];
        dp[idx][tra]=max(sell, dontSell);
      }
    }
  }
  return dp[0][K];
}



int maximumProfitOPT(vector<int> &prices, int k) {
  const int P = (int) prices.size();
  if (k<=0) return 0;
  int K = 2*k; // all (buy&sell) transactions
  vector<int> prev, cur(K+1, 0);

  // base cases: can make no more profit
  // dp[P][tra]=0: considered all stock prices
  // dp[idx][0]=0:	did all transactions

  for (int idx=P-1; idx>=0; idx--) {
    prev=cur;
    for (int tra=1; tra<=K; tra++) {

      if (tra % 2 == 0) { // can buy
        int buy=-prices[idx]+prev[tra-1];
        int dontBuy=0+prev[tra];
        cur[tra]=max(buy, dontBuy);
      } else { // can sell
        int sell=prices[idx]+prev[tra-1];
        int dontSell=0+prev[tra];
        cur[tra]=max(sell, dontSell);
      }
    }
  }
  return cur[K];
}



int maximumProfitOPT2(vector<int> &prices, int k) {
  const int P = (int) prices.size();
  if (k<=0) return 0;
  int K = 2*k; // all (buy&sell) transactions
  vector<int> row(K+1, 0);

  // base cases: can make no more profit
  // dp[P][tra]=0: considered all stock prices
  // dp[idx][0]=0:	did all transactions

  for (int idx=P-1; idx>=0; idx--) {
    for (int tra=K; tra>=1; tra--) {

      if (tra % 2 == 0) { // can buy
        int buy=-prices[idx]+row[tra-1];
        int dontBuy=0+row[tra];
        row[tra]=max(buy, dontBuy);
      } else { // can sell
        int sell=prices[idx]+row[tra-1];
        int dontSell=0+row[tra];
        row[tra]=max(sell, dontSell);
      }
    }
  }
  return row[K];
}



#include "test/dp038.h"
int main() {
  run_tests("BF", maximumProfitBF);
  run_tests("MMZ", maximumProfitMMZ);
  run_tests("BU", maximumProfitBU);
  run_tests("OPT", maximumProfitOPT);
  run_tests("OPT2", maximumProfitOPT2);

  print_report();
  return 0;
}