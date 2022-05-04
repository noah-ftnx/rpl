#include <vector>
using namespace std;

int mod = (int) (1e9+7);

bool isBlocked(const vector<vector<int>> &mat, int i, int j) {
  return mat[i][j]==-1;
}

int BF(int i, int j, const vector<vector<int>> &mat) {
  // base cases:
  if (i<0 || j<0) return 0; // out of bounds
  else if (isBlocked(mat, i, j)) return 0; // not a wall
  else if (i==0 && j==0) return 1; // solution

  int top=BF(i-1,j,mat);
  int left=BF(i,j-1,mat);
  return top+left;
}

int mazeObstaclesBF(int n, int m, vector<vector<int>> &mat) {
  if (n<=0 || m<=0) return 0;
  else if (isBlocked(mat,0,0) || isBlocked(mat, n-1, m-1)) return 0;
  return BF(n-1, m-1, mat) %mod;
}



int MMZ(int i, int j, const vector<vector<int>> &mat,
        vector<vector<int>> &mmz) {
  // base cases:
  if (i<0 || j<0) return 0; // out of bounds
  else if (isBlocked(mat, i, j)) return 0; // not a wall
  else if (i==0 && j==0) return 1; // solution
  else if (mmz[i][j]!=-1) return mmz[i][j];
  int top=MMZ(i-1, j, mat, mmz);
  int left=MMZ(i, j-1, mat, mmz);
  return mmz[i][j]=top+left;
}

int mazeObstaclesMMZ(int n, int m, vector<vector<int>> &mat) {
  if (n<=0 || m<=0) return 0;
  else if (isBlocked(mat,0,0) || isBlocked(mat, n-1, m-1)) return 0;
  vector<vector<int>> mmz(n, vector<int>(m, -1));
  return MMZ(n-1, m-1, mat, mmz) %mod;
}



int mazeObstaclesBU(int n, int m, vector<vector<int>> &mat) {
  if (n<=0 || m<=0) return 0;
  else if (isBlocked(mat,0,0) || isBlocked(mat, n-1, m-1)) return 0;

  vector<vector<int>> tab(n, vector<int>(m, 0));

  auto isValid = [&] (int i, int j) -> bool {
    return i>=0 && j>=0 && !isBlocked(mat, i, j);
  };


  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (i==0 && j==0) { tab[0][0]=1; continue; }

      int  top=!isValid(i-1, j)? 0:tab[i-1][j];
      int left=!isValid(i, j-1)? 0:tab[i][j-1];
      tab[i][j]=top+left;
    }
  }
  return tab[n-1][m-1]%mod;
}



int mazeObstaclesOPT(int n, int m, vector<vector<int>> &mat) {
  if (n<=0 || m<=0) return 0;
  else if (isBlocked(mat,0,0) || isBlocked(mat, n-1, m-1)) return 0;

  vector<int> cur(m, 0);
  vector<int> prev(m, 0);

  auto isValid = [&] (int i, int j) -> bool {
    return i>=0 && j>=0 && !isBlocked(mat, i, j);
  };

  for (int i=0; i<n; i++) {
    swap(cur, prev);
    for (int j=0; j<m; j++) {
      if (i==0 && j==0) {cur[0]=1; continue; }

      int  top=!isValid(i-1, j)? 0:prev[j];
      int left=!isValid(i, j-1)? 0:cur[j-1];
      cur[j]=top+left;
    }
  }
  return cur[m-1]%mod;
}



#include "test/009.h"
int main() {
  run_tests("BF", mazeObstaclesBF);
  run_tests("MMZ", mazeObstaclesMMZ);
  run_tests("BU", mazeObstaclesBU);
  run_tests("OPT", mazeObstaclesOPT);

  print_errors();
  return 0;
}