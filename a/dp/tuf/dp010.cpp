
int minSumPathBF(vector<vector<int>> &grid);

int minSumPathMMZ(vector<vector<int>> &grid);

int minSumPathBU(vector<vector<int>> &grid);

int minSumPathOPT(vector<vector<int>> &grid);



#include "test/dp010.h"
int main() {
  run_tests("BF", minSumPathBF);
  // run_tests("MMZ", minSumPathMMZ);
  // run_tests("BU", minSumPathBU);
  // run_tests("OPT", minSumPathOPT);

  print_errors();
  return 0;
}