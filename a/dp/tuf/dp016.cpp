
// IMPLEMENT: minSubsetSumDifferenceBF
int minSubsetSumDifferenceBF(vector<int>& arr, int n);

// IMPLEMENT: minSubsetSumDifferenceMMZ
int minSubsetSumDifferenceMMZ(vector<int>& arr, int n);

// IMPLEMENT: minSubsetSumDifferenceBU
int minSubsetSumDifferenceBU(vector<int>& arr, int n);

// IMPLEMENT: minSubsetSumDifferenceOPT
int minSubsetSumDifferenceOPT(vector<int>& arr, int n);


#include "test/dp016.h"
int main() {
  run_tests("BF", minSubsetSumDifferenceBF);
  // run_tests("MMZ", minSubsetSumDifferenceMMZ);
  // run_tests("BU", minSubsetSumDifferenceBU);
  // run_tests("OPT", minSubsetSumDifferenceOPT);

  print_report();
  return 0;
}