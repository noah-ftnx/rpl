#include <vector>
#include <climits>
using namespace std;

int BF(int idx, int cap,
       vector<int> &profit, vector<int> &weight) {
  // base case:
  if (idx==0) { // considered all the input
    // cap: 3: item: 1.. I can pick 3
    // cap: 3: item: 2: I can pick just 2..
    // cap: 3: item is 4

    // if the weight>cap, we'll get a fraction
    // which will be the int 0, which is fine
    return profit[0]*(cap/weight[0]);
  }

  int pick=INT_MIN;
  if (cap-weight[idx]>=0)
    // allow re-picking
    pick=profit[idx]+BF(idx, cap-weight[idx], profit, weight);
  int skip=0+BF(idx-1, cap, profit, weight);

  return max(pick, skip);
}

int unboundedKnapsackBF(int n, int w, vector<int> &profit, vector<int> &weight) {
  return BF(n-1, w, profit, weight);
}



int MMZ(int idx, int cap,
        vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
  // base case:
  if (idx==0) { // considered all the input
    // cap: 3: item: 1.. I can pick 3
    // cap: 3: item: 2: I can pick just 2..
    // cap: 3: item is 4

    // if the weight>cap, we'll get a fraction
    // which will be the int 0, which is fine
    return profit[0]*(cap/weight[0]);
  } else if (dp[idx][cap]!=-1) return dp[idx][cap];

  // allow re-picking
  int pick=INT_MIN;
  if (cap-weight[idx]>=0)
    pick=profit[idx]+MMZ(idx, cap-weight[idx], profit, weight, dp);
  int skip=0+MMZ(idx-1, cap, profit, weight, dp);

  return dp[idx][cap]=max(pick, skip);
}

int unboundedKnapsackMMZ(int n, int w, vector<int> &profit, vector<int> &weight) {
  vector<vector<int>> dp(n, vector<int>(w+1, -1));
  return MMZ(n-1, w, profit, weight, dp);
}



int unboundedKnapsackBU(int n, int w, vector<int> &profit, vector<int> &weight) {
  vector<vector<int>> dp(n, vector<int>(w+1, 0));

  // base case:
  for (int cap=0; cap<=w; cap++) {
    dp[0][cap]= profit[0]*(cap/weight[0]);
  }

  for (int idx=1; idx<n; idx++) {
    for (int cap=0; cap<=w; cap++) {
      int pick=INT_MIN;
      if (cap-weight[idx]>=0)
    pick=profit[idx]+dp[idx][cap-weight[idx]];
  int skip=0+dp[idx-1][cap];
  dp[idx][cap]=max(pick, skip);
    }
  }
  return dp[n-1][w];
}



int unboundedKnapsackOPT(int n, int w, vector<int> &profit, vector<int> &weight) {
  vector<int> row(w+1, 0);

  // base case:
  for (int cap=0; cap<=w; cap++) {
    row[cap]= profit[0]*(cap/weight[0]);
  }

  for (int idx=1; idx<n; idx++) {
    for (int cap=0; cap<=w; cap++) {
      int pick=INT_MIN;
      if (cap-weight[idx]>=0)
        pick=profit[idx]+row[cap-weight[idx]];
      int skip=0+row[cap];
      row[cap]=max(pick, skip);
    }
  }
  return row[w];
}



#include "test/dp023.h"
int main() {
  run_tests("BF", unboundedKnapsackBF);
  run_tests("MMZ", unboundedKnapsackMMZ);
  run_tests("BU", unboundedKnapsackBU);
  run_tests("OPT", unboundedKnapsackOPT);

  print_report();
  return 0;
}