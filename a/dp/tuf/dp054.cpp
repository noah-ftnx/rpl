
// IMPLEMENT: maxSumAfterPartitioningBF
int maxSumAfterPartitioningBF(vector<int> &num, int x);

// IMPLEMENT: maxSumAfterPartitioningMMZ
int maxSumAfterPartitioningMMZ(vector<int> &num, int x);

// IMPLEMENT: maxSumAfterPartitioningBU
int maxSumAfterPartitioningBU(vector<int> &num, int x);

// IMPLEMENT: maxSumAfterPartitioningOPT
int maxSumAfterPartitioningOPT(vector<int> &num, int x);



#include "test/dp054.h"
int main() {
  run_tests("BF", maxSumAfterPartitioningBF);
  // run_tests("MMZ", maxSumAfterPartitioningMMZ);
  // run_tests("BU", maxSumAfterPartitioningBU);
  // run_tests("OPT", maxSumAfterPartitioningOPT);

  print_report();
  return 0;
}