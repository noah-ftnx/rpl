#include <vector>
using namespace std;

bool BF(int idx, int k, vector<int> &arr) {
  // base cases:
  if (k==0) return true; // solved
  else if (idx==0) return arr[0]==k; // last element: solves or not

  // case 1: pick
  bool pick=(k>=arr[idx]) && BF(idx-1, k-arr[idx], arr);

  // case 2: not pick
  bool notPick = BF(idx-1, k, arr);

  return pick | notPick; // bitwise or: also works!
}

bool subsetSumToKBF(int n, int k, vector<int> &arr) {
  if (n==0 || k<0) return false;
  return BF(n-1, k, arr);
}



bool MMZ(int idx, int k, vector<int> &arr, vector<vector<int8_t>> &dp) {
  // base cases:
  if (k==0) return true; // solved
  else if (idx==0) return arr[0]==k; // last element: solves or not
  else if (dp[idx][k]!=-1) return dp[idx][k];

  // case 1: pick
  bool pick=(k>=arr[idx]) && MMZ(idx-1, k-arr[idx], arr, dp);

  // case 2: not pick
  bool notPick = MMZ(idx-1, k, arr, dp);

  return dp[idx][k]=(pick || notPick);
}

bool subsetSumToKMMZ(int n, int k, vector<int> &arr) {
  if (n==0 || k<0) return false;
  vector<vector<int8_t>> dp(n, vector<int8_t>(k+1, -1));
  return MMZ(n-1, k, arr, dp);
}



bool subsetSumToKBU(int n, int k, vector<int> &arr) {
  if (n==0 || k<0) return false;
  vector<vector<bool>> dp(n, vector<bool>(k+1, false));

  // base cases
  // can happen at any idx so we do a loop:
  for (int i=0; i<n; i++) dp[i][0]=true; // solved
  // We could do this: (simpler..)
  // for (int j=0; j<=k; j++) dp[0][j]=(arr[0]==j); // last element
  // or simplify just to this:
  dp[0][arr[0]]=true; // only the matching value can be true
  // example: it's when we have JUST ONE element, then that element must match:
  // arr: {3}, then dp will have:
  // - indices:    0,     1,     2,    3
  // - values: false, false, false, true

  // explore states:
  for (int idx=1; idx<n; idx++) {
    for (int j=1; j<=k; j++) {
      // case 1: pick
      bool pick=(j>=arr[idx]) && dp[idx-1][j-arr[idx]];

      // case 2: not pick
      bool notPick = dp[idx-1][j];

      dp[idx][j]=(pick || notPick);
    }
  }
  return dp[n-1][k];
}



bool subsetSumToKOPT(int n, int k, vector<int> &arr) {
  if (n==0 || k<0) return false;

  vector<bool> prev;
  vector<bool> cur(k+1, false);

  cur[arr[0]]=true; // base case: last element

  // explore states:
  for (int idx=1; idx<n; idx++) {
    prev=cur;
    cur[0]=true;  // base case: solved (k became zero)
    for (int j=1; j<=k; j++) {
      // case 1: pick
      bool pick=(j>=arr[idx]) && prev[j-arr[idx]];

      // case 2: not pick
      bool notPick = prev[j];

      cur[j]=(pick || notPick);
    }
  }

  return cur[k];
}



#include "test/dp014.h"
int main() {
  run_tests("BF", subsetSumToKBF);
  run_tests("MMZ", subsetSumToKMMZ);
  run_tests("BU", subsetSumToKBU);
  run_tests("OPT", subsetSumToKOPT);

  print_report();
  return 0;
}