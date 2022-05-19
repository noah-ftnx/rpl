#include <vector>
using namespace std;

void setZeroesBF(vector<vector<int>>& matrix) {
  auto cpy=matrix;
  const int n = matrix.size();
  const int m = matrix[0].size();
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (cpy[i][j]==0) {
        // zero column
        for (int x=0; x<n; x++) matrix[x][j]=0;
        // zero row
        for (int y=0; y<m; y++) matrix[i][y]=0;
      }
    }
  }
}



void setZeroesV2(vector<vector<int>>& matrix) {
  const int n = matrix.size();
  const int m = matrix[0].size();
  // mark the rows and columns that have 0
  vector<int> row(n, -1);
  vector<int> col(m, -1);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (matrix[i][j]==0) {
        row[i]=0;
        col[j]=0;
      }
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (row[i]==0 || col[j]==0) matrix[i][j]=0;
    }
  }
}



void setZeroesV3(vector<vector<int>>& matrix) {
  const int n = matrix.size();
  const int m = matrix[0].size();

  bool zeroCol0=false;

  // mark headers
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (matrix[i][j]==0) {
        // must zero the 1st col only when a 0 is found on it
        // (as there might be just zeros on 1st row)
        if (j==0) zeroCol0=true;

        // mark j and i headers
        matrix[i][0]=0; // mark column header
        matrix[0][j]=0; // mark row header
      }
    }
  }

  for (int i=n-1; i>=0; i--) {
    for (int j=m-1; j>=1; j--) {
      // either header is zero
      if (matrix[0][j]==0||matrix[i][0]==0)
        matrix[i][j]=0;
    }
    // there was a zero in the 1st row:
    // only then zero it out
    if (zeroCol0) matrix[i][0]=0;
  }
}




#include "test/01-01.h"
int main() {

  run_tests("BF", setZeroesBF);
  run_tests("V2", setZeroesV2);
  run_tests("V3", setZeroesV3);

  print_report();
  return 0;
}
