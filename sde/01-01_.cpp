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
  auto cpy=matrix;
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

  // whether 1st row, col have zeros
  bool col0=false, row0=false;

  // mark 1st row/col, and set flags row0, col0
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (matrix[i][j]==0) {
        matrix[0][j]=0; // mark row
        matrix[i][0]=0; // mark col

        if (i==0) row0=true; // zero on 1st row
        if (j==0) col0=true; // zero on 1st col
      }
    }
  }

  // update zeros in rest of array (in reverse)
  // start from the end, not to propagate wrong zeros:
  // we do all cols except the 0th. then the 0th if col0.
  // then we move to the above row
  for (int i=n-1; i>=0; i--) {
    for (int j=m-1; j>=0; j--) {
      if ((i==0 && row0) ||  // first row and has to be zeroed
          (j==0 && col0) || // first col and has to be zeroed
          // other rows and are marked
          matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
    }
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
