
int getMaxPathSumBF(vector<vector<int>> &matrix);

int getMaxPathSumMMZ(vector<vector<int>> &matrix);

int getMaxPathSumBU(vector<vector<int>> &matrix);

int getMaxPathSumOPT(vector<vector<int>> &matrix);



#include "test/dp012.h"
int main() {
  run_tests("BF", getMaxPathSumBF);
  run_tests("MMZ", getMaxPathSumMMZ);
  run_tests("BU", getMaxPathSumBU);
  run_tests("OPT", getMaxPathSumOPT);

  print_errors();
  return 0;
}