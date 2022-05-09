
int minSubsetSumDifferenceBF(vector<int>& arr, int n);

int minSubsetSumDifferenceMMZ(vector<int>& arr, int n);

int minSubsetSumDifferenceBU(vector<int>& arr, int n);

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