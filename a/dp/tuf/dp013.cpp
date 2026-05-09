
// IMPLEMENT: maximumChocolatesBF
int maximumChocolatesBF(int r, int c, vector<vector<int>> &grid);

// IMPLEMENT: maximumChocolatesMMZ
int maximumChocolatesMMZ(int r, int c, vector<vector<int>> &grid);

// IMPLEMENT: maximumChocolatesBU
int maximumChocolatesBU(int r, int c, vector<vector<int>> &grid);

// IMPLEMENT: maximumChocolatesOPT
int maximumChocolatesOPT(int r, int c, vector<vector<int>> &grid);



#include "test/dp013.h"
int main() {
  run_tests("BF", maximumChocolatesBF);
  run_tests("MMZ", maximumChocolatesMMZ);
  run_tests("BU", maximumChocolatesBU);
  run_tests("OPT", maximumChocolatesOPT);

  print_errors();
  return 0;
}