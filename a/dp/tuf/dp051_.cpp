#include<vector>
using namespace std;

int BF(int i, int j, vector<int>& nums) {
  // there is a subproblem even if i==j (a single burst)
  // base case: only when i crosses j
  if (i>j) return 0;

  // pick bursting (in reverse)
  int mx=-1;
  for (int burst=i; burst<=j; burst++) {
    int cost = nums[i-1]*nums[burst]*nums[j+1] +
               BF(i, burst-1, nums) + BF(burst+1, j, nums);
    mx=max(mx, cost);
  }
  return mx;
}

int maxCoinsBF(vector<int>& nums) {
  const int B = (int) nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);

  return BF(1, B, nums);
}



int MMZ(int i, int j, vector<int>& nums, vector<vector<int>> &dp) {
 // there is a subproblem even if i==j (a single burst)
 // base case: only when i crosses j
 if (i>j) return 0;

 if (dp[i][j]!=-1) return dp[i][j];

 // pick bursting (in reverse)
 int mx=-1;
 for (int burst=i; burst<=j; burst++) {
   int cost = nums[i-1]*nums[burst]*nums[j+1] +
              MMZ(i, burst-1, nums, dp) + MMZ(burst+1, j, nums, dp);
   mx=max(mx, cost);
 }
 return dp[i][j]=mx;
}

int maxCoinsMMZ(vector<int>& nums) {
 const int B = (int) nums.size();
 nums.insert(nums.begin(), 1);
 nums.push_back(1);

 vector<vector<int>> dp(B+1, vector<int>(B+1, -1));
 return MMZ(1, B, nums, dp);
}



int maxCoinsBU(vector<int>& nums) {
  const int B = (int) nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);

  // we added 2 elements
  // in MMZ is ok, but here not
  vector<vector<int>> dp(B+2, vector<int>(B+2, 0));

  for (int i=B; i>=1; i--) {
    for (int j=1; j<=B; j++) {
      if (i>j) continue; // base case: only when i crosses j

      // pick bursting (in reverse)
      int mx=-1;
      for (int burst=i; burst<=j; burst++) {
        int cost = nums[i-1]*nums[burst]*nums[j+1] +
                   dp[i][burst-1] + dp[burst+1][j];
        mx=max(mx, cost);
      }
      dp[i][j]=mx;
    }
  }
  return dp[1][B];
}



#include "test/dp051.h"
int main() {
  run_tests("BF", maxCoinsBF);
  run_tests("MMZ", maxCoinsMMZ);
  run_tests("BU", maxCoinsBU);
  // run_tests("OPT", maxCoinsBU);

  print_report();
  return 0;
}