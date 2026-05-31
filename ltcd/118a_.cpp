#include <vector>
using namespace std;

class Solution {
public:
  vector<int> lastRow(int numRows) {
    vector<int> row;
    for (int r = 0; r < numRows; r++) {
      vector<int> next(r + 1, 1);
      for (int c = 1; c < r; c++) {
        next[c] = row[c - 1] + row[c];
      }
      row = next;
    }
    return row;
  }
};

#include "test/118a.h"
int main() {
  run_tests("triangle", lastRow);
  print_report();
  return 0;
}
