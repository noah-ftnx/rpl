#include <vector>
using namespace std;

int BF(int idx, int k, vector<int>& arr) { // sum up to k
  if (idx==0) {
    // allowing zeros?
    if (arr[0]==0 && k==0) return 2; // last zero: 2 options: pick/skip
    return k==0 || arr[0]==k;
  }

  int pick= k-arr[idx]<0? 0 : BF(idx-1, k-arr[idx], arr);
  int skip=BF(idx-1, k, arr);

  return pick+skip;
}

int targetSumBF(int n, int target, vector<int>& arr) {
  int TS {};
  for (int a: arr) TS+=a;

  if (TS-target<0) return 0;
  else if ((TS-target)%2==1) return 0;

  // count how many subsets sum up to this:
  int k=(TS-target)/2;

  return BF(n-1, k, arr);
}



int MMZ(int idx, int k, vector<int>& arr, vector<vector<int>> &dp) {
  if (idx==0) {
    // allowing zeros?
    if (arr[0]==0 && k==0) return 2; // last zero: 2 options: pick/skip
    return k==0 || arr[0]==k;
  } else if (dp[idx][k]!=-1) return dp[idx][k];

  int pick= k-arr[idx]<0? 0 : MMZ(idx-1, k-arr[idx], arr, dp);
  int skip=MMZ(idx-1, k, arr, dp);

  return dp[idx][k]=pick+skip;
}

int targetSumMMZ(int n, int target, vector<int>& arr) {
  int TS {};
  for (int a: arr) TS+=a;

  if (TS-target<0) return 0;
  else if ((TS-target)%2==1) return 0;

  // count how many subsets sum up to this:
  int k=(TS-target)/2;

  vector<vector<int>> dp (n, vector<int>(k+1, -1));
  return MMZ(n-1, k, arr, dp);
}



int targetSumBU(int n, int target, vector<int>& arr) {
  int TS {};
  for (int a: arr) TS+=a;

  if (TS-target<0) return 0;
  else if ((TS-target)%2==1) return 0;

  // count how many subsets sum up to this:
  int SUM2=(TS-target)/2; // the negative subset sum

  vector<vector<int>> dp (n, vector<int>(SUM2+1, 0));

  // base cases
  for (int idx=0; idx<n; idx++) dp[idx][0]=1;
  if (arr[0] <=SUM2) dp[0][arr[0]]=1;
  if (arr[0]==0) dp[0][0]=2; // 1st num is 9: can pick/skip

  for (int idx=1; idx<n; idx++) {
    for (int k=0; k<=SUM2; k++) {
      int pick= k-arr[idx]<0? 0 : dp[idx-1][k-arr[idx]];
      int skip=dp[idx-1][k];
      dp[idx][k]=pick+skip;
    }
  }
  return dp[n-1][SUM2];
}



int targetSumOPT(int n, int target, vector<int>& arr) {
  int TS {};
  for (int a: arr) TS+=a;

  if (TS-target<0) return 0;
  else if ((TS-target)%2==1) return 0;

  // count how many subsets sum up to this:
  int SUM2=(TS-target)/2; // the negative subset sum

  vector<int> prev(SUM2+1, 0);
  vector<int> cur(SUM2+1, 0);

  // base cases
  prev[0]=cur[0]=1;
  if (arr[0] <=SUM2) cur[arr[0]]=1;

  if (arr[0]==0) cur[0]=2; // 1st num is 9: can pick/skip

  for (int idx=1; idx<n; idx++) {
    prev=cur;
    for (int k=0; k<=SUM2; k++) {
      int pick= k-arr[idx]<0? 0 : prev[k-arr[idx]];
      int skip=prev[k];
      cur[k]=pick+skip;
    }
  }
  return cur[SUM2];
}



#include "test/dp021.h"
int main() {
  run_tests("BF", targetSumBF);
  run_tests("MMZ", targetSumMMZ);
  run_tests("BU", targetSumBU);
  run_tests("OPT", targetSumOPT);

  print_report();
  return 0;
}