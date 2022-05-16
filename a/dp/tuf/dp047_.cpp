#include <vector>
using namespace std;

void print_verification(vector<int> &arr, vector<int> &dp, vector<int> &ways);

int findNumberOfLIS(vector<int> &arr) {
  const int N = (int) arr.size();
  vector<int> dp(N, 1);
  vector<int> ways(N, 1);
  int mx=1;
  for (int i=0; i<N; i++) {
    for (int prev=0; prev<i; prev++) {

      if (arr[i] > arr[prev]) { // increasing subsequence
        if (dp[prev]+1 > dp[i]) { // new max lis
          dp[i]=dp[prev]+1;
          mx=max(mx, dp[i]);
          ways[i]=ways[prev];

        } else if (dp[prev]+1==dp[i]) { // another ways to reach max lis
          ways[i]+=ways[prev];
        }
      }
    }
  }

  print_verification(arr, dp, ways);

  // sum all the ways to generate a mx len subsequence
  int cnt=0;
  for (int i=0; i<N; i++) {
    if (dp[i]==mx) cnt+=ways[i];
  }
  return cnt;
}




#include "test/dp047.h"
int main() {
  run_tests("DP", findNumberOfLIS);

  print_report();
  return 0;
}