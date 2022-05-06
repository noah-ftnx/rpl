#include <vector>
using namespace std;

int BF(vector<vector<int>>& triangle, const int N, int i, int j) {
  // base cases:
  if (i==N-1) return triangle[i][j]; // reached last row
  // cannot go out of bounds:
  // j axis: it is always valid
  // i axis: we finish on last valid row

  int cost = triangle[i][j];

  int down = cost + BF(triangle, N, i+1, j);
  int downRight = cost + BF(triangle, N, i+1, j+1);

  return min(down, downRight);
}

int minimumPathSumBF(vector<vector<int>>& triangle, int n){
  if (triangle.empty()) return 0;
  return BF(triangle, n, 0, 0);
}


int MMZ(vector<vector<int>>& triangle, const int N, int i, int j,
        vector<vector<int>> &dp) {
  // base cases:
  if (i==N-1) return triangle[i][j]; // reached last row
    // cannot go out of bounds:
    // j axis: it is always valid
    // i axis: we finish on last valid row
  else if (dp[i][j]!=-1) return dp[i][j];

  int cost = triangle[i][j];

  int down = cost + MMZ(triangle, N, i+1, j, dp);
  int downRight = cost + MMZ(triangle, N, i+1, j+1, dp);

  return dp[i][j]=min(down, downRight);
}

int minimumPathSumMMZ(vector<vector<int>>& triangle, int n){
  if (triangle.empty()) return 0;
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return MMZ(triangle, n, 0, 0, dp);
}



int minimumPathSumBU(vector<vector<int>>& triangle, int n){
  if (triangle.empty()) return 0;
  vector<vector<int>> dp(n, vector<int>(n, -1));

  // cannot go out of bounds:
  // j axis: it is always valid
  // i axis: we finish on last valid row

  // base case: last row
  dp[n-1]=triangle[n-1];

  for (int i=n-2; i>=0; i--){
    for (int j=0; j<i+1; j++) {
      int cost = triangle[i][j];
      int down = cost + dp[i+1][j];
      int downRight = cost + dp[i+1][j+1];
      dp[i][j]=min(down, downRight);
    }
  }
  return dp[0][0];
}



int minimumPathSumOPT(vector<vector<int>>& triangle, int n){
  if (triangle.empty()) return 0;
  vector<int> prev(n, -1);
  vector<int> cur(n, -1);

  // cannot go out of bounds:
  // j axis: it is always valid
  // i axis: we finish on last valid row

  // base case: last row
  cur=triangle[n-1];

  for (int i=n-2; i>=0; i--){
    swap(cur, prev);
    for (int j=0; j<i+1; j++) {
      int cost = triangle[i][j];
      int down = cost + prev[j];
      int downRight = cost + prev[j+1];
      cur[j]=min(down, downRight);
    }
  }
  return cur[0];
}






#include "test/dp011.h"
int main() {
  run_tests("BF", minimumPathSumBF);
  run_tests("MMZ", minimumPathSumMMZ);
  run_tests("BU", minimumPathSumBU);
  run_tests("OPT", minimumPathSumOPT);

  print_errors();
  return 0;
}