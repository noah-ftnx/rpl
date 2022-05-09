#include <vector>
#include <cmath>
using namespace std;

int BF(int idx, int k, vector<int> &num) {
  if (idx==0) {
    if (k==0 && num[0]==0) return 2; // TRICKY case:  can pick or skip '0' on idx 0
    // all other cases
    return (int) (k==0 || k==num[0]);
  }

  int take=(k-num[idx]>=0)? BF(idx-1, k-num[idx], num) : 0;
  int notTake=BF(idx-1, k, num);

  return take + notTake;
}

int findWaysBF(vector<int> &num, int tar) {
  if (num.empty()) return tar==0;
  return BF(num.size()-1, tar, num);
}



int MMZ(int idx, int k, vector<int> &num, vector<vector<int>> &dp) {
  if (idx==0) {
   // 0, 0, 10
   if (k==0 && num[0]==0) return 2; // TRICKY: can pick or skip

   return k==0 || k==num[0];
  } else if (dp[idx][k]!=-1) return dp[idx][k];

  int take= k-num[idx]>=0? MMZ(idx-1, k-num[idx], num, dp) : 0;
  int notTake=MMZ(idx-1, k, num, dp);

  return dp[idx][k]=take + notTake;
}

int findWaysMMZ(vector<int> &num, int tar) {
  if (num.empty()) return tar==0;

  vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
  return MMZ(num.size()-1, tar, num, dp);
}



int findWaysBU(vector<int> &num, int tar) {
  if (num.empty()) return tar==0;
  vector<vector<int>> dp(num.size(), vector<int>(tar+1, 0));
  const int N = (int) num.size();

  // base cases
  // order matters here (this is added before the other case
  if (num[0]<=tar) dp[0][num[0]]=1; // last element matches

  // the other case is NOT a loop now (and we start inner loop from 0)
  for (int i=0; i<N; i++) dp[i][0]=1; // case 1: reached target
  // case 2:
  if (num[0]==0) dp[0][0]=2;
  else if (num[0] <= tar) dp[0][num[0]]=1;

  for (int idx=1; idx<N; idx++) {
    for (int k=0; k<=tar; k++) {
      int take= k-num[idx]>=0? dp[idx-1][k-num[idx]]:0;
      int notTake=dp[idx-1][k];
      dp[idx][k]=take + notTake;
    }
  }

  return dp[N-1][tar];
}



int findWaysOPT(vector<int> &num, int tar) {
  if (num.empty()) return tar==0;

  vector<int> prev(tar+1, 0);
  vector<int> cur(tar+1, 0);
  const int N = (int) num.size();

  // base cases:
  // order matters (this one above)
  if (num[0]<=tar) cur[num[0]]= 1; // last element matches

  cur[0]=prev[0]= num[0]==0? 2:1; // processing index 0
  // plus we start the inner loop from 0

  for (int idx=1; idx<N; idx++) {
    prev=cur;
    for (int k=0; k<=tar; k++) {
      int take=k-num[idx]>=0? prev[k-num[idx]]:0;
      int notTake=prev[k];
      cur[k]=take + notTake;
    }
  }

  return cur[tar];
}



#include "test/dp017.h"
int main() {
  run_tests("BF", findWaysBF);
  run_tests("MMZ", findWaysMMZ);
  run_tests("BU", findWaysBU);
  run_tests("OPT", findWaysOPT);

  print_report();
  return 0;
}