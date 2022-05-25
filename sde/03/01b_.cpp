#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (matrix.empty() || matrix[0].empty()) return false;

  int m = (int) matrix.size();
  int n = (int) matrix[0].size();

  int i=0, j=n-1;

  while (i<m && j>=0) {
    if (matrix[i][j]==target) return true; // found
    else if (target < matrix[i][j]) { // smaller than cur
      // rows sorted asc:
      // rows below have even greater nums
      j--; // go left
    } else { // bigger than cur
      // go down: to find a bigger num
      i++;
    }
  }
  return false;
}



#include "test/01b.h"
int main() {
  run_tests("Sol", searchMatrix);

  print_report();
  return 0;
}