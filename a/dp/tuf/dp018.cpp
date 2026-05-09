
// IMPLEMENT: countPartitionsBF
int countPartitionsBF(int n, int d, vector<int> &arr);

// IMPLEMENT: countPartitionsMMZ
int countPartitionsMMZ(int n, int d, vector<int> &arr);

// IMPLEMENT: countPartitionsBU
int countPartitionsBU(int n, int d, vector<int> &arr);

// IMPLEMENT: countPartitionsOPT
int countPartitionsOPT(int n, int d, vector<int> &arr);



#include "test/dp018.h"
int main() {
  run_tests("BF", countPartitionsBF);
  run_tests("MMZ", countPartitionsMMZ);
  run_tests("BU", countPartitionsBU);
  run_tests("OPT", countPartitionsOPT);

  print_report();
  return 0;
}