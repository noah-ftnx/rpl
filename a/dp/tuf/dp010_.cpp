#include <vector>
using namespace std;


int BF(const vector<vector<int>> &grid, int i, int j) {
  if (i==0 && j==0) return grid[0][0];
    // OOB: make sure not considered
  else if (i<0 || j<0) return INT_MAX; // OVERFLOW?!

  int cost=grid[i][j];

  int up=BF(grid, i-1, j);
  if (up!=INT_MAX) up+=cost;

  int left=BF(grid, i, j-1);
  if (left!=INT_MAX) left+=cost;

  return min(up, left);
}

int minSumPathBF(vector<vector<int>> &grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  const int N = (int) grid.size();
  const int M  = (int) grid[0].size();

  return BF(grid, N-1, M-1);
}



int MMZ(const vector<vector<int>> &grid, int i, int j,
        vector<vector<int>> &dp) {
  if (i==0 && j==0) return grid[0][0];
    // OOB: make sure not considered
  else if (i<0 || j<0) return INT_MAX; // OVERFLOW?!
  else if(dp[i][j]!=-1) return dp[i][j];

  int cost=grid[i][j];

  int up=MMZ(grid, i-1, j, dp);
  if (up!=INT_MAX) up+=cost;

  int left=MMZ(grid, i, j-1, dp);
  if (left!=INT_MAX) left+=cost;

  return dp[i][j]=min(up, left);
}

int minSumPathMMZ(vector<vector<int>> &grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  const int N = (int) grid.size();
  const int M  = (int) grid[0].size();

  vector<vector<int>> dp(N, vector<int>(M, -1));
  return MMZ(grid, N-1, M-1, dp);
}



int minSumPathBU(vector<vector<int>> &grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  const int N = (int) grid.size();
  const int M  = (int) grid[0].size();

  vector<vector<int>> dp(N, vector<int>(M, -1));
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (i==0 && j==0) { dp[0][0]=grid[0][0]; continue; }
      int cost=grid[i][j];
      int   up=i-1<0? INT_MAX : cost+dp[i-1][j];
      int left=j-1<0? INT_MAX : cost+dp[i][j-1];
      dp[i][j]=min(up, left);
    }
  }
  return dp[N-1][M-1];
}



int minSumPathOPT(vector<vector<int>> &grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  const int N = (int) grid.size();
  const int M  = (int) grid[0].size();

  vector<int> cur(M, -1);
  vector<int> prev(M, -1);

  for (int i=0; i<N; i++) {
    swap(cur, prev);
    for (int j=0; j<M; j++) {
      if (i==0 && j==0) { cur[0]=grid[0][0]; continue; }
      int cost=grid[i][j];
      int   up=i-1<0? INT_MAX : cost+prev[j];
      int left=j-1<0? INT_MAX : cost+cur[j-1];
      cur[j]=min(up, left);
    }
  }
  return cur[M-1];
}



#include "test/dp010.h"
int main() {
  run_tests("BF", minSumPathBF);
  run_tests("MMZ", minSumPathMMZ);
  run_tests("BU", minSumPathBU);
  run_tests("OPT", minSumPathOPT);

  print_errors();
  return 0;
}