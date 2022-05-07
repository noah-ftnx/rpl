#include <vector>
using namespace std;

int BF(int i, int j1, int j2,
       int r, int c, vector<vector<int>> &grid) {

  // base case:
  if (j1<0 || j1>=c || j2<0 || j2>=c) { // either OOB
    return INT_MIN;
  } else if (i==r-1) { // reached destination
    int s = grid[i][j1];
    if (j2!=j1) s+=grid[i][j2]; // not in common spot
    return s;
  }

  // explore all paths: 9
  // row is always +1
  // col is: -1, 0, +1, for both...
  vector<int> colDirs {-1, 0, +1};
  int mx=-1;
  for (int j1Ofst: colDirs) {
    for (int j2Ofst: colDirs) {
      int t=BF(i+1, j1+j1Ofst, j2+j2Ofst, r, c, grid);

      if (t==INT_MIN) continue;
      t+=grid[i][j1];
      if (j2!=j1) t+=grid[i][j2]; // not in common spot
      mx=max(mx, t);
    }
  }
  return mx;
}

int maximumChocolatesBF(int r, int c, vector<vector<int>> &grid) {
  return BF(0, 0, c-1, r, c, grid);
}



int MMZ(int i, int j1, int j2,
        int r, int c, vector<vector<int>> &grid,
        vector<vector<vector<int>>> &dp) {

  // base case:
  if (j1<0 || j1>=c || j2<0 || j2>=c) { // either OOB
    return INT_MIN; // TODO overflow?
  } else if (i==r-1) { // reached destination
    int s = grid[i][j1];
    if (j2!=j1) s+=grid[i][j2]; // not in common spot
    return s;
  } else if (dp[i][j1][j2]!=-1) return dp[i][j1][j2];

  // explore all paths: 9
  // row is always +1
  // col is: -1, 0, +1, for both...
  vector<int> colDirs {-1, 0, +1};
  int mx=-1;
  for (int j1Ofst: colDirs) {
    for (int j2Ofst: colDirs) {
      int t=MMZ(i+1, j1+j1Ofst, j2+j2Ofst, r, c, grid, dp);

      if (t==INT_MIN) continue;
      t+=grid[i][j1];
      if (j2!=j1) t+=grid[i][j2]; // not in common spot
      mx=max(mx, t);
    }
  }
  return dp[i][j1][j2]=mx;
}

int maximumChocolatesMMZ(int r, int c, vector<vector<int>> &grid) {
  vector<vector<vector<int>>> dp (r,
                                  vector<vector<int>> (c, vector<int> (c, -1)));
  return MMZ(0, 0, c-1, r, c, grid, dp);
}



int maximumChocolatesBU(int r, int c, vector<vector<int>> &grid) {
  vector<vector<vector<int>>> dp (r,
                                 vector<vector<int>> (c, vector<int> (c, -1)));

  // base case: last row
  for (int j1=0; j1<c; j1++) {
    for (int j2=0; j2<c; j2++) {
      int s = grid[r-1][j1];
      if (j2!=j1) s+=grid[r-1][j2]; // not in common spot
      dp[r-1][j1][j2]=s;
    }
  }

  // express every state
  for (int i=r-2; i>=0; i--) {
    for (int j1=c-1; j1>=0; j1--) {
      for (int j2=c-1; j2>=0; j2--) {

        vector<int> colDirs {-1, 0, +1};
        int mx=-1;
        for (int j1Ofst: colDirs) {
          for (int j2Ofst: colDirs) {
            // OOB for either j1, or j2: ignore them
            if (j1+j1Ofst <0 || j1+j1Ofst >=c
                || j2+j2Ofst <0 || j2+j2Ofst >=c) continue;

            int t=dp[i+1][j1+j1Ofst][j2+j2Ofst];
            t+=grid[i][j1];
            if (j2!=j1) t+=grid[i][j2]; // not in common spot
            mx=max(mx, t);
          }
        }
        dp[i][j1][j2]=mx;
      }
    }
  }
  return dp[0][0][c-1];
}



int maximumChocolatesOPT(int r, int c, vector<vector<int>> &grid) {
  vector<vector<int>> prev(c, vector<int> (c, -1));
  vector<vector<int>> cur(c, vector<int> (c, -1));

  // base case: last row
  for (int j1=0; j1<c; j1++) {
    for (int j2=0; j2<c; j2++) {
      int s = grid[r-1][j1];
      if (j2!=j1) s+=grid[r-1][j2]; // not in common spot
      cur[j1][j2]=s;
    }
  }

  // express every state
  for (int i=r-2; i>=0; i--) {
    prev=cur;
    for (int j1=c-1; j1>=0; j1--) {
      for (int j2=c-1; j2>=0; j2--) {

        vector<int> colDirs {-1, 0, +1};
        int mx=-1;
        for (int j1Ofst: colDirs) {
          for (int j2Ofst: colDirs) {
            // OOB for either j1, or j2: ignore them
            if (j1+j1Ofst <0 || j1+j1Ofst >=c
                || j2+j2Ofst <0 || j2+j2Ofst >=c) continue;

            int t=prev[j1+j1Ofst][j2+j2Ofst];
            t+=grid[i][j1];
            if (j2!=j1) t+=grid[i][j2]; // not in common spot
            mx=max(mx, t);
          }
        }
        cur[j1][j2]=mx;
      }
    }
  }

  return cur[0][c-1];
}



#include "test/dp013.h"
int main() {
  run_tests("BF", maximumChocolatesBF);
  run_tests("MMZ", maximumChocolatesMMZ);
  run_tests("BU", maximumChocolatesBU);
  run_tests("OPT", maximumChocolatesOPT);

  print_errors();
  return 0;
}