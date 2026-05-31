#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int r = 0; r < numRows; r++) {
      vector<int> row(r + 1, 1);
      for (int c = 1; c < r; c++) {
        row[c] = res[r - 1][c - 1] + res[r - 1][c];
      }
      res.push_back(row);
    }
    return res;
  }
};

#include "test/118.h"
int main() {
  run_tests("triangle", generate);
  print_report();
  return 0;
}
