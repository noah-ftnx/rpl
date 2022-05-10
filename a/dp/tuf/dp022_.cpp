#include <vector>
using namespace std;

int BF(int idx, int k, int *arr) {
  // base case
  if (idx==0) { // considered all the numbers
    // {1}, 7
    // can the first num solve it?
    // we can use 7 1s, (still one solution. solving cnt)
    return (k%arr[0]==0); // solves or not
  }

  int skip=BF(idx-1, k, arr);
  int pick=0;
  if (k-arr[idx]>=0) pick=BF(idx, k-arr[idx], arr); // allow to re-pick

  return skip+pick;
}

long countWaysToMakeChangeBF(int *denominations, int n, int value) {
  if (denominations==nullptr || n<=0 || value<0) return 0;
  return BF(n-1, value, denominations);
}



int MMZ(int idx, int k, int *arr, vector<vector<int>> &dp) {
  // base case
  if (idx==0) { // considered all the numbers
    // {1}, 7
    // can the first num solve it?
    // we can use 7 1s, (still one solution. solving cnt)
    return (k%arr[0]==0); // solves or not
  } else if (dp[idx][k]!=-1) return dp[idx][k];

  int skip=MMZ(idx-1, k, arr, dp);
  int pick=0;
  if (k-arr[idx]>=0) pick=MMZ(idx, k-arr[idx], arr, dp); // allow to re-pick

  return dp[idx][k]=skip+pick;
}

long countWaysToMakeChangeMMZ(int *denominations, int n, int value) {
  if (denominations==nullptr || n<=0 || value<0) return 0;
  vector<vector<int>> dp (n, vector<int>(value+1, -1));
  return MMZ(n-1, value, denominations, dp);
}



long countWaysToMakeChangeBU(int *denominations, int n, int value) {
  if (denominations==nullptr || n<=0 || value<0) return 0;
  vector<vector<long>> dp (n, vector<long>(value+1, 0));

  int *arr=denominations;
  // base case
  for (int k=0; k<=value; k++) {
    dp[0][k]=(k%arr[0]==0);
  }

  for (int idx=1; idx<n; idx++) {
    for (int k=0; k<=value; k++) {
      int skip=dp[idx-1][k];
      int pick=0;
      if (k-arr[idx]>=0) pick=dp[idx][k-arr[idx]]; // allow re-picking

      dp[idx][k]=skip+pick;
    }
  }
  return dp[n-1][value];
}




long countWaysToMakeChangeOPT(int *denominations, int n, int value) {
  if (denominations==nullptr || n<=0 || value<0) return 0;
  vector<long> prev, cur(value+1, 0);

  int *arr=denominations;
  // base case
  for (int k=0; k<=value; k++) {
    cur[k]=(k%arr[0]==0);
  }

  for (int idx=1; idx<n; idx++) {
    prev=cur;
    for (int k=0; k<=value; k++) {
      int skip=prev[k];
      int pick=0;
      if (k-arr[idx]>=0) pick=cur[k-arr[idx]]; // allow re-picking

      cur[k]=skip+pick;
    }
  }
  return cur[value];
}





#include "test/dp022.h"
int main() {
  run_tests("BF", countWaysToMakeChangeBF);
  run_tests("MMZ", countWaysToMakeChangeMMZ);
  run_tests("BU", countWaysToMakeChangeBU);
  run_tests("OPT", countWaysToMakeChangeOPT);

  print_report();
  return 0;
}