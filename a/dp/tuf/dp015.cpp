
bool canPartitionBF(vector<int> &arr, int n);

bool canPartitionMMZ(vector<int> &arr, int n);

bool canPartitionBU(vector<int> &arr, int n);

bool canPartitionOPT(vector<int> &arr, int n);



#include "test/dp015.h"
int main() {
  run_tests("BF", canPartitionBF);
  run_tests("MMZ", canPartitionMMZ);
  run_tests("BU", canPartitionBU);
  run_tests("OPT", canPartitionOPT);

  print_report();
  return 0;
}