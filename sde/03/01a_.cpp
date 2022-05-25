#include <vector>
#include <utility>
using namespace std;


/*
0  1  2  3
4  5  6  7
8  9 10 11

0: 0 1 2 3
1: 0 1 2 3
2: 0 1 2 3

mx = m*n;

for i: 0 to mx:

   7
   row
   7/n= 7/4 = 1 col 1

   7%n=7%4=3 col (correct)
*/



bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (matrix.empty() || matrix[0].empty()) return false;

  int m = (int) matrix.size();
  int n = (int) matrix[0].size();

  int sz1d=m*n;

  auto get = [&](int i) -> int {
    int row = i/n; int col = i%n;
    return matrix[row][col];
  };

  // binary search:
  int l=0, r=sz1d-1;
  while (l<=r) {
    int mid = (l+r)/2;
    int midVal = get(mid);
    if (midVal == target) return true;
    else if (target > midVal) {  // go to right
      l=mid+1;
    } else { // go to left
      r=mid-1;
    }
  }
  return false;
}


#include "test/01a.h"
int main() {
  run_tests("Sol", searchMatrix);

  print_report();
  return 0;
}