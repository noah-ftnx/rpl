#include <vector>
using namespace std;

// IMPLEMENT: generate triangle
vector<vector<int>> generate(int numRows);

#include "test/118.h"
int main() {
  run_tests("triangle", generate);
  print_report();
  return 0;
}
