
// IMPLEMENT: countSquaresBF
int countSquaresBF(int n, int m, vector<vector<int>> &arr);

// IMPLEMENT: countSquaresMMZ
int countSquaresMMZ(int n, int m, vector<vector<int>> &arr);

// IMPLEMENT: countSquaresBU
int countSquaresBU(int n, int m, vector<vector<int>> &arr);

// IMPLEMENT: countSquaresOPT
int countSquaresOPT(int n, int m, vector<vector<int>> &arr);



#include "test/dp056.h"
int main() {
  run_tests("BF", countSquaresBF);
  // run_tests("MMZ", countSquaresMMZ);
  // run_tests("BU", countSquaresBU);
  // run_tests("OPT", countSquaresOPT);

  print_report();
  return 0;
}