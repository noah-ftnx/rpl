#include <vector>
using namespace std;

int BF(const vector<vector<int>> &triangle, int n, int i, int j) {
  if (i==n-1) { // base case: reached last row
    return triangle[i][j];
  }

  int down= triangle[i][j]+BF(triangle, n, i+1, j);
  int downRight=triangle[i][j]+BF(triangle, n, i+1, j+1);

  return min(down, downRight);
}

int minimumPathSumBF(vector<vector<int>>& triangle, int n){
  return BF(triangle, n, 0, 0);
}

int MMZ(const vector<vector<int>> &triangle, int n, int i, int j,
        vector<vector<int>> &dp) {
  if (i==n-1) { // base case: reached last row
    return triangle[i][j];
  } else if (dp[i][j]!=-1) return dp[i][j];

  int down= triangle[i][j]+MMZ(triangle, n, i+1, j, dp);
  int downRight=triangle[i][j]+MMZ(triangle, n, i+1, j+1, dp);

  return dp[i][j]=min(down, downRight);
}

int minimumPathSumMMZ(vector<vector<int>>& triangle, int n){
  vector<vector<int>> dp (n, vector<int>(n, -1));
  return MMZ(triangle, n, 0, 0, dp);
}

int minimumPathSumBU(vector<vector<int>>& triangle, int n){
  vector<vector<int>> dp (n, vector<int>(n, -1));

  // base case: last row
  dp[n-1]=triangle[n-1];

  for (int i=n-2; i>=0; i--) {
    for (int j=i; j>=0; j--) {
      int down= triangle[i][j]+dp[i+1][j];
      int downRight=triangle[i][j]+dp[i+1][j+1];
      dp[i][j]=min(down, downRight);
    }
  }
  return dp[0][0];
}




#include "test/dp011.h"
int main() {
  run_tests("BF", minimumPathSumBF);
  run_tests("MMZ", minimumPathSumMMZ);
  run_tests("BU", minimumPathSumBU);
  // run_tests("OPT", minSumPathOPT);

  print_errors();
  return 0;
}