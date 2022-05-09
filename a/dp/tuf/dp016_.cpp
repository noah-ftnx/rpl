#include <vector>
#include <climits>
using namespace std;

int NaiveBF(int idx, int a, int b, vector<int>& arr) {
  if (idx<0) { // divided all numbers in subsets
    return abs(a-b);
  }

  int pickedByA=NaiveBF(idx-1, a+arr[idx], b, arr);
  int pickedByB=NaiveBF(idx-1, a, b+arr[idx], arr);

  return min(pickedByA, pickedByB);
}


int minSubsetSumDifferenceNaiveBF(vector<int>& arr, int n) {
  return NaiveBF(n-1, 0, 0, arr);
}



int specialSumUpToKBU(vector<int>& arr, int n, int target) {
  vector<vector<bool>> dp (n, vector<bool>(target+1, false));

  for (int i=0; i<n; i++) dp[i][0]=true; // solved
  if (arr[0]<=target) dp[0][arr[0]]=true; // last element

  for (int idx=1; idx<n; idx++) {
    for (int k=1; k<=target; k++) {
      bool pick=k-arr[idx]>=0 && dp[idx-1][k-arr[idx]];
      bool skip=dp[idx-1][k];
      dp[idx][k]=(pick || skip);
    }
  }

  // k: 0..TS, incl
  int mn=INT_MAX;
  for (int k=0; k<=target/2; k++) {
    if (dp[n-1][k]) {
      int sumA = target-k;
      int sumB =k;
      mn=min(mn, abs(sumA-sumB));
    }
  }
  return mn;
}

int minSubsetSumDifferenceBU(vector<int>& arr, int n) {
  int TS {};
  for (int i=0; i<n; i++) TS+=arr[i];
  return specialSumUpToKBU(arr, n, TS);
}



int specialSumUpToKOPT(vector<int>& arr, int n, int target) {
  vector<bool> prev(target+1, false);
  vector<bool> cur(target+1, false);

  if (arr[0] <= target) cur[arr[0]]=true; // last element
  prev[0]=cur[0]=true;

  for (int idx=1; idx<n; idx++) {
    prev=cur;
    for (int k=1; k<=target; k++) {
      bool pick=k-arr[idx]>=0 && prev[k-arr[idx]];
      bool skip=prev[k];
      cur[k]=(pick || skip);
    }
  }

  // k: 0..TS, incl
  int mn=INT_MAX;
  for (int k=0; k<=target/2; k++) {
    if (cur[k]) {
      int sumA = target-k;
      int sumB =k;
      mn=min(mn, abs(sumA-sumB));
    }
  }
  return mn;
}

int minSubsetSumDifferenceOPT(vector<int>& arr, int n) {
  int TS {};
  for (int i=0; i<n; i++) TS+=arr[i];
  return specialSumUpToKOPT(arr, n, TS);
}



#include "test/dp016.h"
int main() {
  run_tests("NaiveBF", minSubsetSumDifferenceNaiveBF);
  run_tests("BU", minSubsetSumDifferenceBU);
  run_tests("OPT", minSubsetSumDifferenceOPT);

  print_report();
  return 0;
}