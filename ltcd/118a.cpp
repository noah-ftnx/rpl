#include <vector>
using namespace std;

// IMPLEMENT: last row of Pascal's triangle
vector<int> lastRow(int numRows);

#include "test/118a.h"
int main() {
  run_tests("triangle", lastRow);
  print_report();
  return 0;
}
