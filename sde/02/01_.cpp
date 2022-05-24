#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  auto cpy=matrix;
  const int N = matrix.size();

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int col=N-1-i;
      // j: col for cpy, and row for matrix
      matrix[j][col]=cpy[i][j];
    }
  }
}



void rotate2(vector<vector<int>>& matrix) {
  auto cpy=matrix;
  const int N = matrix.size();

  // generate the transpose
  for (int i=0; i<N; i++) {
    for (int j=0; j<i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // reverse each row
  for (int i=0; i<N; i++) {
    int l=0, r=N-1;
    while (l<r) {
      swap(matrix[i][l++], matrix[i][r--]);
    }
  }
}



#include "test/01.h"
int main() {
  run_tests("Sol", rotate);
  run_tests("Sol2", rotate2);

  print_report();
  return 0;
}

