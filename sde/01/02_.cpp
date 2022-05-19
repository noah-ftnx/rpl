#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
  if (numRows<=0) return {};
  vector<vector<int>> res;

  for (int row=1; row<=numRows; row++) {
    vector<int> cur_row(row);
    int prev=0;

    for (int j=0; j<row; j++) {  // fill row
      if (j==0 || j==row-1) { // first or last elent
        // this covers first 2 rows (no OOB)
        cur_row[j]=1;
      } else { // take sum
        cur_row[j]=res.back()[prev] + res.back()[prev+1];
        prev++;
      }
    }
    res.push_back(cur_row);
  }
  return res;
}



#include "test/02.h"
int main() {

  run_tests("triangle", generate);

  print_report();
  return 0;
}
