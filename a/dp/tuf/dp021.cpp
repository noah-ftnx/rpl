
int targetSumBF(int n, int target, vector<int>& arr);

int targetSumMMZ(int n, int target, vector<int>& arr);

int targetSumBU(int n, int target, vector<int>& arr);

int targetSumOPT(int n, int target, vector<int>& arr);



#include "test/dp021.h"
int main() {
  run_tests("BF", targetSumBF);
  // run_tests("MMZ", targetSumMMZ);
  // run_tests("BU", targetSumBU);
  // run_tests("OPT", targetSumOPT);

  print_report();
  return 0;
}