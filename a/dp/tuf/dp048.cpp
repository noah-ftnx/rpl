
int matrixMultiplicationBF(vector<int> &arr, int N);

int matrixMultiplicationMMZ(vector<int> &arr, int N);

int matrixMultiplicationBU(vector<int> &arr, int N);



#include "test/dp048.h"
int main() {
  run_tests("DP", matrixMultiplicationBF);
  // run_tests("MMZ", matrixMultiplicationMMZ);
  // run_tests("BU", matrixMultiplicationBU);
  // run_tests("OPT", matrixMultiplicationOPT);

  print_report();
  return 0;
}