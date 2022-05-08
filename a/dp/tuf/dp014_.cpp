#include <vector>
using namespace std;

bool BF(int idx, int k, vector<int> &arr) {
  // base cases:
  if (k==0) return true; // solved
  else if (idx==0) return arr[0]==k; // last element

  bool pick = (k-arr[idx]>=0) && BF(idx-1, k-arr[idx], arr);
  bool notPick = BF(idx-1, k, arr);

  return pick || notPick;
}

bool subsetSumToKBF(int n, int k, vector<int> &arr) {
  // edge cases:
  if (k<0 || arr.empty()) return false;

  return BF(n-1, k, arr);
}



bool MMZ(int idx, int k, vector<int> &arr, vector<vector<int8_t>> &dp) {
  // base cases:
  if (k==0) return true; // solved
  else if (idx==0) return arr[0]==k; // last element
  else if (dp[idx][k]!=-1) return dp[idx][k];

  bool pick = (k-arr[idx]>=0) && MMZ(idx-1, k-arr[idx], arr, dp);
  bool notPick = MMZ(idx-1, k, arr, dp);

  return dp[idx][k]=(pick || notPick);
}

bool subsetSumToKMMZ(int n, int k, vector<int> &arr) {
  // edge cases:
  if (k<0 || arr.empty()) return false;

  vector<vector<int8_t>> dp(n, vector<int8_t>(k+1, -1));
  return MMZ(n-1, k, arr, dp);
}



bool subsetSumToKBU(int n, int target, vector<int> &arr) {
  // edge cases:
  if (target<0 || arr.empty()) return false;

  vector<vector<bool>> dp(n, vector<bool>(target+1, false));

  // base cases:
  for (int i=0; i<n; i++) dp[i][0]=true; // solved

  // for (int k=0; k<=target; k++) dp[0][k]= ((arr[0])==k);
  // simplified. last element matches
  if (arr[0] <=target)  dp[0][arr[0]]=true;
  // for above:
  // index is 0, but target can be anything.
  // But when it is true though? Only when arr[0]==k. Just in this case.

  for (int idx=1; idx<n; idx++) {
    for (int k=1; k<=target; k++) {
      bool pick = (k-arr[idx]>=0) && dp[idx-1][k-arr[idx]];
      bool notPick = dp[idx-1][k];
      dp[idx][k]=(pick || notPick);
    }
  }

  return dp[n-1][target];
}



bool subsetSumToKOPT(int n, int target, vector<int> &arr) {
  // edge cases:
  if (target<0 || arr.empty()) return false;

  vector<bool> prev(target+1, false);
  vector<bool> cur(target+1, false);

  // base cases:
  // for (int k=0; k<=target; k++) cur[k]= ((arr[0])==k);
  cur[arr[0]]=true; // simplified. last element matches
  cur[0]=true;
  // we never modify 0 idx in loop. we do this once over here:
  prev[0]=true;

  for (int idx=1; idx<n; idx++) {
    prev=cur;
    // we are overriding each [idx][k], so no need to worry about
    // previous values
    for (int k=1; k<=target; k++) {
      bool pick = (k-arr[idx]>=0) && prev[k-arr[idx]];
      bool notPick = prev[k];
      cur[k]=(pick || notPick);
    }
  }

  return cur[target];
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