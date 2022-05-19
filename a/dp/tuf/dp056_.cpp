#include <vector>
using namespace std;

int countSquaresBU(int n, int m, vector<vector<int>> &arr) {
  vector<vector<int>> dp (n, vector<int>(m, 0));
  int sum {};

  // init first column
  for (int i=0; i<n; i++) {
    dp[i][0]=arr[i][0];
    if (dp[i][0]) sum++;
  }

  // init first row
  // TRICKY: [0][0] already covered
  for (int j=1; j<m; j++) {
    dp[0][j]=arr[0][j];
    if (dp[0][j]) sum++;
  }

  for (int i=1; i<n; i++) {
    for (int j=1; j<m; j++) {
      // form rectangles:
      if (arr[i][j]) {  // only if not zero
        // top, left, diagonalTL
        int mn = min(dp[i-1][j],
                     min(dp[i][j-1], dp[i-1][j-1]));
        dp[i][j]=mn+1;
        sum+=dp[i][j];
      }
    }
  }
  return sum;
}



#include "test/dp056.h"
int main() {
  // run_tests("BF", countSquaresBF);
  // run_tests("MMZ", countSquaresMMZ);
  run_tests("BU", countSquaresBU);
  // run_tests("OPT", countSquaresBU);

  print_report();
  return 0;
}