
int maximalAreaOfSubMatrixOfAll1BF(vector<vector<int>> &mat, int n, int m);

int maximalAreaOfSubMatrixOfAll1MMZ(vector<vector<int>> &mat, int n, int m);

int maximalAreaOfSubMatrixOfAll1BU(vector<vector<int>> &mat, int n, int m);

int maximalAreaOfSubMatrixOfAll1OPT(vector<vector<int>> &mat, int n, int m);



#include "test/dp055.h"
int main() {
  run_tests("BF", maximalAreaOfSubMatrixOfAll1BF);
  // run_tests("MMZ", maximalAreaOfSubMatrixOfAll1MMZ);
  // run_tests("BU", maximalAreaOfSubMatrixOfAll1BU);
  // run_tests("OPT", maximalAreaOfSubMatrixOfAll1OPT);

  print_report();
  return 0;
}