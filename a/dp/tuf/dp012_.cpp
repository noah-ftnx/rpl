#include <vector>
using namespace std;

int BF(int i, int j, const vector<vector<int>> &matrix) {
  const int M = (int) matrix[0].size();

  // base cases
  if (j<0 || j>M-1) { // OOB
    return INT_MIN;
  } else if (i==0) { // reached 1st row
    return matrix[0][j];
  }

  const int cost = matrix[i][j];
  int up=BF(i-1, j, matrix);
  if (up!=INT_MIN) up+=cost;

  int upLeft=BF(i-1, j-1, matrix);
  if (upLeft!=INT_MIN) upLeft+=cost;

  int upRight=BF(i-1, j+1, matrix);
  if (upRight!=INT_MIN) upRight+=cost;

  return max(up, max(upLeft, upRight));
}

int getMaxPathSumBF(vector<vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty()) return -1;

  int mx=-1;
  const int N = (int) matrix.size();
  const int M = (int) matrix[0].size();

  for (int j=0; j<M; j++) {
    mx=max(mx, BF(N-1, j, matrix));
  }

  return mx;
}



int MMZ(int i, int j, const vector<vector<int>> &matrix,
        vector<vector<int>> dp) {
  const int N = (int) matrix.size();
  const int M = (int) matrix[0].size();

  // base cases
  if (j<0 || j>M-1) { // OOB
    return INT_MIN; // OVERFLOW?!
  } else if (i==0) { // reached 1st row
    return matrix[0][j];
  } else if (dp[i][j]!=-1) return dp[i][j];

  const int cost = matrix[i][j];
  int up=MMZ(i-1, j, matrix, dp);
  if (up!=INT_MIN) up+=cost;

  int upLeft=MMZ(i-1, j-1, matrix, dp);
  if (upLeft!=INT_MIN) upLeft+=cost;

  int upRight=MMZ(i-1, j+1, matrix, dp);
  if (upRight!=INT_MIN) upRight+=cost;

  return dp[i][j]=max(up, max(upLeft, upRight));
}

int getMaxPathSumMMZ(vector<vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty()) return -1;

  int mx=-1;
  const int N = (int) matrix.size();
  const int M = (int) matrix[0].size();

  vector<vector<int>> dp(N, vector<int>(M, -1));
  for (int j=0; j<M; j++) {
    mx=max(mx, MMZ(N-1, j, matrix, dp));
  }

  return mx;
}



int getMaxPathSumBU(vector<vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty()) return -1;

  const int N = (int) matrix.size();
  const int M = (int) matrix[0].size();
  vector<vector<int>> dp(N, vector<int>(M, -1));

  // base cases:
  for (int j=0; j<M; j++) dp[0][j]=matrix[0][j];

  for (int i=1; i<N; i++) {
    for (int j=0; j<M; j++) {
      const int cost = matrix[i][j];
      int up=cost+dp[i-1][j];
      int upLeft=j-1>=0 ? cost+dp[i-1][j-1] : INT_MIN;
      int upRight=j+1<M ? cost+dp[i-1][j+1] : INT_MIN;

      dp[i][j]=max(up, max(upLeft, upRight));
    }
  }

  int mx=-1;
  for (int j=0; j<M; j++) {
    mx=max(mx, dp[N-1][j]);
  }

  return mx;
}



int getMaxPathSumOPT(vector<vector<int>> &matrix) {
  if (matrix.empty() || matrix[0].empty()) return -1;

  const int N = (int) matrix.size();
  const int M = (int) matrix[0].size();
  vector<int> prev(M, -1);
  vector<int> cur(M, -1);

  // base cases:
  for (int j=0; j<M; j++) cur[j]=matrix[0][j];

  for (int i=1; i<N; i++) {
    swap(cur, prev);
    for (int j=0; j<M; j++) {
      const int cost = matrix[i][j];
      int up=cost+prev[j];
      int upLeft=j-1>=0 ? cost+prev[j-1] : INT_MIN;
      int upRight=j+1<M ? cost+prev[j+1] : INT_MIN;

      cur[j]=max(up, max(upLeft, upRight));
    }
  }

  int mx=-1;
  for (int j=0; j<M; j++) {
    mx=max(mx, cur[j]);
  }
  return mx;
}



#include "test/dp012.h"
int main() {
  run_tests("BF", getMaxPathSumBF);
  run_tests("MMZ", getMaxPathSumMMZ);
  run_tests("BU", getMaxPathSumBU);
  run_tests("OPT", getMaxPathSumOPT);

  print_errors();
  return 0;
}