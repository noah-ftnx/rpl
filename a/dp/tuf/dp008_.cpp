#include <vector>
using namespace std;

int BF(int i, int j) {
  // base cases:
  if (i==0 && j==0) return 1; // reached destination
  else if (i<0 || j<0) return 0; // out of bounds

  int top=BF(i-1, j);
  int left=BF(i, j-1);

  return top+left;
}

int uniquePathsBF(int m, int n) {
  return BF(m-1, n-1);
}



int MMZ(int i, int j, vector<vector<int>> &mmz) {
  // base cases:
  if (i==0 && j==0) return 1; // reached destination
  else if (i<0 || j<0) return 0; // out of bounds
  else if (mmz[i][j]!=-1) return mmz[i][j];

  int top=MMZ(i-1, j, mmz);
  int left=MMZ(i, j-1, mmz);

  return mmz[i][j]=top+left;
}

int uniquePathsMMZ(int m, int n) {
  vector<vector<int>> mmz(m, vector<int>(n,-1));
  return MMZ(m-1, n-1, mmz);
}



int uniquePathsBU(int m, int n) {
  if (m<=0 || n<=0) return 0;
  vector<vector<int>> tab(m, vector<int>(n, 0));
  tab[0][0]=1; // base case

  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      if (i==0 && j==0) continue;
      int top= i==0? 0:tab[i-1][j];
      int left= j==0? 0:tab[i][j-1];
      tab[i][j]=top+left;
    }
  }

  return tab[m-1][n-1];
}



int uniquePathsOPT(int m, int n) {
  if (m<=0 || n<=0) return 0;
  vector<int> prev(n, 0), cur(n, 0);

  for (int i=0; i<m; i++) {
    swap(cur, prev);
    for (int j=0; j<n; j++) {
      if (i==0 && j==0) { cur[0]=1; continue; } // base case

      int top= i==0? 0:prev[j];
      int left= j==0? 0:cur[j-1];
      cur[j]=top+left;
    }
  }

  return cur[n-1];
}



#include "test/dp008.h"
int main() {
  run_tests("BF", uniquePathsBF);
  run_tests("MMZ", uniquePathsMMZ);
  run_tests("BU", uniquePathsBU);
  run_tests("OPT", uniquePathsOPT);

  print_report();
  return 0;
}