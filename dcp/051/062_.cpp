#include <vector>
using namespace std;

int paths_numBF(int N, int M) {
  if (N==0 || M==0) return 0; // invalid array
  if (N==1 || M==1) return 1; // 1D arrays have only 1 solution

  return paths_numBF(N-1, M) + paths_numBF(N, M-1);
}


int BF(int i, int j) {
  // base case:
  if (i==0 && j==0) return 1; // valid way
  else if (i<0 || j<0) return 0;  // out of bounds

  // we are from bottom-right, so we move opposite
  int top = BF(i-1, j);
  int left = BF(i, j-1);

  return top+left;
}


int uniquePaths(int m, int n) {
  return BF(m-1, n-1);
}


int paths_numBU(int N, int M) {
  if (N ==0 || M==0) return 0;

  vector<vector<int>> grid (N, vector<int>(M, 0));

  // only 1 way to reach an 1D array
  for (int i=0; i<N; i++) grid[i][0]=1;
  for (int j=0; j<M; j++) grid[0][j]=1;

  for (int i=1; i<N; i++) {
    for (int j=1; j<M; j++) {
      grid[i][j]=grid[i-1][j]+grid[i][j-1];
    }
  }
  return grid[N-1][M-1];
}

int paths_numOPT(int N, int M) {
  if (N ==0 || M==0) return 0;

  vector<int> prev(M, 0);

  vector<int> cur(M, 1); // 1 col: 1 way to solve

  for (int i=1; i<N; i++) {
    swap(cur, prev);
    cur[0]=1; // 1 row: 1 way to solve

    for (int j=1; j<M; j++) {
      cur[j]=prev[j]+cur[j-1];
    }
  }
  return cur.back();
}




#include "test/062.h"
int main() {
  run_tests("BF", paths_numBF);
  run_tests("BU", paths_numBU);
  run_tests("OPT", paths_numOPT);
  return 0;
}