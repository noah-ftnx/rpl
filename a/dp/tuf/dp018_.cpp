#include <vector>
using namespace std;

int BF(int idx, int k, vector<int> &arr) {
  // base case
  if (idx==0) {  // whole input considered
    if (k==0 && arr[0]==0) return 2; // 2 solutions: take/skip arr[0]
    return k==0 || arr[0]==k; // return 1. solved
  }

  int take=k-arr[idx]<0 ? 0 : BF(idx-1, k-arr[idx], arr);
  int skip=BF(idx-1, k, arr);

  return take+skip;
}

int countPartitionsBF(int n, int d, vector<int> &arr) {
  int TS {};
  for (auto a: arr) TS+=a;

  if ((TS-d)%2 !=0) return 0;
  else if (TS-d <0) return 0;

  int target=(TS-d)/2;
  return BF(n-1, target, arr);
}



int MMZ(int idx, int k, vector<int> &arr, vector<vector<int>> &dp) {
  // base case
  if (idx==0) {  // whole input considered
    // 0, 10 : k==0
    if (k==0 && arr[0]==0) return 2; // 2 solutions: take/skip arr[0]
    return k==0 || arr[0]==k; // return 1. solved
  } else if (dp[idx][k]!=-1) return dp[idx][k];

  int take=k-arr[idx]<0 ? 0 : MMZ(idx-1, k-arr[idx], arr, dp);
  int skip=MMZ(idx-1, k, arr, dp);

  return dp[idx][k]=take+skip;
}

int countPartitionsMMZ(int n, int d, vector<int> &arr) {
  int TS {};
  for (auto a: arr) TS+=a;

  if ((TS-d)%2 !=0) return 0;
  else if (TS-d <0) return 0;

  int target=(TS-d)/2;
  vector<vector<int>> dp (n, vector<int>(target+1, -1));
  return MMZ(n-1, target, arr, dp);
}



int countPartitionsBU(int n, int d, vector<int> &arr) {
  int TS {};
  for (auto a: arr) TS+=a;

  if ((TS-d)%2 !=0) return 0;
  else if (TS-d <0) return 0;

  int target=(TS-d)/2;
  vector<vector<int>> dp (n, vector<int>(target+1, 0));

  // base case
  for (int i=0; i<n; i++) dp[i][0]=1;
  if (arr[0]==0) dp[0][0]=2;
  else if (arr[0] <=target) dp[0][arr[0]]=1;

  for (int idx=1; idx<n; idx++) {
    for (int k=1; k<=target; k++) {
      int take=k-arr[idx]<0 ? 0 : dp[idx-1][k-arr[idx]];
      int skip=dp[idx-1][k];
      dp[idx][k]=take+skip;
    }
  }
  return dp[n-1][target];
}



int countPartitionsOPT(int n, int d, vector<int> &arr) {
  int TS {};
  for (auto a: arr) TS+=a;

  if ((TS-d)%2 !=0) return 0;
  else if (TS-d <0) return 0;

  int target=(TS-d)/2;
  vector<int> prev(target+1, 0);
  vector<int> cur(target+1, 0);

  // base case
  prev[0]=cur[0]=1;
  if (arr[0]==0) cur[0]=2;
  else if (arr[0] <=target) cur[arr[0]]=1;

  for (int idx=1; idx<n; idx++) {
    prev=cur;
    for (int k=1; k<=target; k++) {
      int take=k-arr[idx]<0 ? 0 : prev[k-arr[idx]];
      int skip=prev[k];
      cur[k]=take+skip;
    }
  }
  return cur[target];
}




#include "test/dp018.h"
int main() {
  run_tests("BF", countPartitionsBF);
  run_tests("MMZ", countPartitionsMMZ);
  run_tests("BU", countPartitionsBU);
  run_tests("BU", countPartitionsOPT);

  print_report();
  return 0;
}