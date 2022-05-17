#include <vector>
using namespace std;

int BF(int i, int j, vector<int> &arr) {
  // a single vector: no operations
  if (i==j) return 0;

  // try different split points:
  // A(BCD)
  // (AB)(CD)
  // (ABC)D
  int mn=INT_MAX;
  for (int p=i; p<j; p++) {
    int ops = (arr[i-1] * arr[p] * arr[j])
              // left partition
              + BF(i, p, arr)
              // right partition
              + BF(p+1, j, arr);
    mn=min(mn, ops);
  }
  return mn;
}

int matrixMultiplicationBF(vector<int> &arr, int N) {
  if (N<=1) return -1;
  return BF(1, N-1, arr);
}



int MMZ(int i, int j, vector<int> &arr, vector<vector<int>> dp) {
  // a single vector: no operations
  if (i==j) return 0;

  if (dp[i][j]!=-1) return dp[i][j];

  // try different split points:
  // A(BCD)
  // (AB)(CD)
  // (ABC)D
  int mn=INT_MAX;
  for (int p=i; p<j; p++) {
    int ops = (arr[i-1] * arr[p] * arr[j])
              // left partition
              + MMZ(i, p, arr, dp)
              // right partition
              + MMZ(p+1, j, arr, dp);
    mn=min(mn, ops);
  }
  return dp[i][j]=mn;
}

int matrixMultiplicationMMZ(vector<int> &arr, int N) {
  if (N<=1) return -1;
  vector<vector<int>> dp(N, vector<int>(N, -1));
  return MMZ(1, N-1, arr, dp);
}



int matrixMultiplicationBU(vector<int> &arr, int N) {
  if (N<=1) return -1;
  vector<vector<int>> dp(N, vector<int>(N, 0));

  // base case: a single vector: no operations
  // dp[x][x]==0: diagonal

  for (int i=N-1; i>=1; i--) {
    // starting from i+1: instead of 1:
    // 1. no need to check for: i==j
    // 2. the inner loop would have never entered anyway (if started from 1)
    for (int j=i+1; j<N; j++) {

      int mn=INT_MAX;
      for (int p=i; p<j; p++) {
        int ops = (arr[i-1] * arr[p] * arr[j])
                  // left partition
                  + dp[i][p]
                  // right partition
                  + dp[p+1][j];
        mn=min(mn, ops);
      }
      dp[i][j]=mn;

    }
  }
  return dp[1][N-1];
}



#include "test/dp048.h"
int main() {
  run_tests("DP", matrixMultiplicationBF);
  run_tests("MMZ", matrixMultiplicationMMZ);
  run_tests("BU", matrixMultiplicationBU);
  run_tests("OPT", matrixMultiplicationOPT);

  print_report();
  return 0;
}