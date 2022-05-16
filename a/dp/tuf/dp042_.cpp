#include <string>
#include <vector>
using namespace std;

void print_arrays(int, vector<int>&, vector<int> &, vector<int>&);

string BF(int idx, int last_idx, vector<int>& nums) {
    const int N = (int) nums.size();
    if (idx==0) return "";

    string res=BF(idx-1, last_idx, nums); // SKIPPED
    bool can_pick = (last_idx==N+1) || nums[idx-1]<nums[last_idx-1];
    if (can_pick) {
        string pick=BF(idx-1, idx, nums) + " " + to_string(nums[idx-1]);
        if (pick.size() > res.size()) res=pick;
    }
    return res;
}

string printLISBF(vector<int>& nums) {
    const int N = (int) nums.size();
    return BF(N, N+1, nums);
}



string printLISDP(vector<int>& nums) {
  if (nums.empty()) return "";
  const int N = (int) nums.size();
  vector<int> dp(N, 1); // min: just a num itself
  vector<int> par(N, -1); // everyone is a parent of itself

  int lastPar=0, mx=1;
  for (int i=0; i<N; i++) {
    // look at previous nums and find bigger subsequences for dp[i]
    for (int prev=0; prev<i; prev++) {
      // increasing
      if (nums[i] > nums[prev] // increasing
          && 1+dp[prev] > dp[i]) { // + bigger subsequence
        dp[i]=1+dp[prev];
        par[i]=prev;
      }
    }

    if (dp[i]>mx) { // new max (biggest subsequence)
      mx=dp[i];
      lastPar=i;
    }
  }

  // build result
  string res;
  while(lastPar!=-1) {
    res = to_string(nums[lastPar]) + " " + res;
    lastPar=par[lastPar];
  }
  return res;
}




#include "test/dp042.h"
int main() {
    run_tests("BF", printLISBF);
    run_tests("DP", printLISDP);

    print_report();
    return 0;
}