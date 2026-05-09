
// IMPLEMENT: minimumPathSumBF
int minimumPathSumBF(vector<vector<int>>& triangle, int n);

// IMPLEMENT: minimumPathSumMMZ
int minimumPathSumMMZ(vector<vector<int>>& triangle, int n);

// IMPLEMENT: minimumPathSumBU
int minimumPathSumBU(vector<vector<int>>& triangle, int n);

// IMPLEMENT: minimumPathSumOPT
int minimumPathSumOPT(vector<vector<int>>& triangle, int n);



#include "test/dp011.h"
int main() {
  run_tests("BF", minimumPathSumBF);
  run_tests("MMZ", minimumPathSumMMZ);
  run_tests("BU", minimumPathSumBU);
  run_tests("OPT", minimumPathSumOPT);

  print_errors();
  return 0;
}