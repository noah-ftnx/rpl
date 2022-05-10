#include <vector>
#include <climits>
using namespace std;

int BF(int idx, int k, const vector<int> &num) {
  if (idx==0) {  // last element
    // must be used 1+ times, and perfectly match k
    // pick the last one to match k
    if (k % num[0] != 0) return INT_MAX; // cannot use it
    else return k / num[0];
  } else if (k==0) return 0; // no need for extra picks

  int pick=INT_MAX;
  if (k-num[idx]>=0) {
    pick=BF(idx, k-num[idx], num);
    if (pick!=INT_MAX) pick++; // count the coin (w/o overflowing)
  }
  int skip=0+BF(idx-1, k, num);

  return min(pick, skip);
}

int minimumElementsBF(vector<int> &num, int x) {
  if (x<0 || num.empty()) return -1; // edge cases

  int res=BF((int)num.size()-1, x, num);
  return res==INT_MAX? -1: res;
}



int MMZ(int idx, int k, const vector<int> &num, vector<vector<int>> &dp) {
  if (idx==0) {  // last element
                   // must be used 1+ times, and perfectly match k
    // pick the last one to match k
    if (k % num[0] != 0) return INT_MAX; // cannot use it
    else return k / num[0];
  } else if (k==0) return 0; // no need for extra picks
  else if (dp[idx][k]!=-1) return dp[idx][k];

  int pick=INT_MAX;
  if (k-num[idx]>=0) {
    pick=MMZ(idx, k-num[idx], num, dp);
    if (pick!=INT_MAX) pick++; // count the coin (w/o overflowing)
  }
  int skip=0+MMZ(idx-1, k, num, dp);

  return dp[idx][k]=min(pick, skip);
}

int minimumElementsMMZ(vector<int> &num, int x) {
  if (x<0 || num.empty()) return -1; // edge cases
  vector<vector<int>> dp((int)num.size(), vector<int>(x+1, -1));
  int res=MMZ((int)num.size()-1, x, num, dp);
  return res==INT_MAX? -1: res;
}



int minimumElementsBU(vector<int> &num, int x) {
  if (x<0 || num.empty()) return -1; // edge cases

  const int N = (int) num.size();
  vector<vector<int>> dp(N, vector<int>(x+1, 0));

  // base cases
  for (int k=0; k<=x; k++) {
    if (k % num[0] != 0) dp[0][k]=INT_MAX; // cannot use it
    else dp[0][k]= k/num[0];
  }


  for (int idx=1; idx<N; idx++) {
    for (int k=0; k<=x; k++) {
      int pick=INT_MAX;
      if (k-num[idx]>=0) {
        pick=dp[idx][k-num[idx]];
        if (pick!=INT_MAX) pick++; // count the coin (w/o overflowing)
      }
      int skip=0+dp[idx-1][k];
      dp[idx][k]=min(pick, skip);
    }
  }
  int res=dp[N-1][x];
  return res==INT_MAX? -1: res;
}



int minimumElementsOPT(vector<int> &num, int x) {
  if (x<0 || num.empty()) return -1; // edge cases

  const int N = (int) num.size();
  vector<int> prev;
  vector<int> cur(x+1, 0);

  // base cases
  for (int k=0; k<=x; k++) {
    if (k % num[0] != 0) cur[k]=INT_MAX; // cannot use it
    else cur[k]= k/num[0];
  }

  for (int idx=1; idx<N; idx++) {
    prev=cur;
    for (int k=0; k<=x; k++) {
      int pick=INT_MAX;
      if (k-num[idx]>=0) {
        pick=cur[k-num[idx]];
        if (pick!=INT_MAX) pick++; // count the coin (w/o overflowing)
      }
      int skip=0+prev[k];
      cur[k]=min(pick, skip);
    }
  }
  int res = cur[x];
  return res==INT_MAX? -1: res;
}



#include "test/dp020.h"
int main() {
  run_tests("BF", minimumElementsBF);
  run_tests("MMZ", minimumElementsMMZ);
  run_tests("BU", minimumElementsBU);
  run_tests("OPT", minimumElementsOPT);

  print_report();
  return 0;
}