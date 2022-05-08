#include <vector>
using namespace std;

bool NaiveBF(int idx, int a, int b, vector<int> &arr) {
  // base cases:
  if (idx<0) return a==b; // consumed input: sums matching

  // explore
  bool pickForA = NaiveBF(idx-1, a+arr[idx], b, arr);
  bool pickForB = NaiveBF(idx-1, a, b+arr[idx], arr);

  return pickForA | pickForB;
}

bool canPartitionNaiveBF(vector<int> &arr, int n)
{
  return NaiveBF(n-1, 0, 0, arr);
}



bool BF(int idx, int k, vector<int> &arr) {
  // base cases:
  if (k==0) return true; // solved
  else if (idx==0) return arr[0]==k; // last element

  // explore
  bool pick= k-arr[idx] >=0 && BF(idx-1, k-arr[idx], arr);
  bool skip=BF(idx-1, k, arr);

  return pick | skip;
}

bool canPartitionBF(vector<int> &arr, int n)
{

  if (arr.empty()) return true;

  int S {};
  for (int i=0; i<n; i++) S+=arr[i];

  // with odd sum, we cannot split
  if (S%2!=0) return false;

  // there's a solution when: we find a subset that sums S/2,
  // as the remaining elements add up to the other half
  return BF(n-1, S/2, arr);
}



bool MMZ(int idx, int k, vector<int> &arr, vector<vector<int8_t>> &dp) {
  // base cases:
  if (k==0) return true; // solved
  else if (idx==0) return arr[0]==k; // last element
  else if (dp[idx][k]!=-1) return dp[idx][k];

  // explore
  bool pick= k-arr[idx] >=0 && MMZ(idx-1, k-arr[idx], arr, dp);
  bool skip=MMZ(idx-1, k, arr, dp);

  return dp[idx][k]=(pick | skip);
}

bool canPartitionMMZ(vector<int> &arr, int n)
{

  if (arr.empty()) return true;

  int S {};
  for (int i=0; i<n; i++) S+=arr[i];

  // with odd sum, we cannot split
  if (S%2!=0) return false;


  vector<vector<int8_t>> dp(n, vector<int8_t>((S/2)+1, -1));

  // there's a solution when: we find a subset that sums S/2,
  // as the remaining elements add up to the other half
  return MMZ(n-1, S/2, arr, dp);
}



bool canPartitionBU(vector<int> &arr, int n)
{

  if (arr.empty()) return true;

  int S {};
  for (int i=0; i<n; i++) S+=arr[i];

  // with odd sum, we cannot split
  if (S%2!=0) return false;


  const int K = S/2;
  vector<vector<bool>> dp(n, vector<bool>(K+1, false));


  // base cases:
  for (int i=0; i<n; i++) dp[i][0]=true; // solved
  if (arr[0] <=K) dp[0][arr[0]]=true;   // last element

  // explore
  for (int idx=1; idx<n; idx++) {
    for (int k=1; k<=K; k++) {

      bool pick= k-arr[idx] >=0 && dp[idx-1][k-arr[idx]];
      bool skip=dp[idx-1][k];
      dp[idx][k]=(pick | skip);
    }
  }

  // there's a solution when: we find a subset that sums S/2,
  // as the remaining elements add up to the other half
  return dp[n-1][K];
}



bool canPartitionOPT(vector<int> &arr, int n)
{

  if (arr.empty()) return true;

  int S {};
  for (int i=0; i<n; i++) S+=arr[i];

  // with odd sum, we cannot split
  if (S%2!=0) return false;


  const int K = S/2;
  vector<bool> prev(K+1, false);
  vector<bool> cur(K+1, false);

  // base cases:
  cur[0]=prev[0]=true; // solved: (k is zero!)
  if (arr[0] <=K) cur[arr[0]]=true;   // last element

  // explore
  for (int idx=1; idx<n; idx++) {
    prev=cur;
    // cur[0]= true.. base case.. set above..
    for (int k=1; k<=K; k++) {

      bool pick= k-arr[idx] >=0 && prev[k-arr[idx]];
      bool skip=prev[k];
      cur[k]=(pick | skip);
    }
  }

  // there's a solution when: we find a subset that sums S/2,
  // as the remaining elements add up to the other half
  return cur[K];
}


#include "test/dp015.h"
int main() {
  run_tests("NaiveBF", canPartitionNaiveBF);
  run_tests("BF", canPartitionBF);
  run_tests("MMZ", canPartitionMMZ);
  run_tests("BU", canPartitionBU);
  run_tests("OPT", canPartitionOPT);

  print_report();
  return 0;
}