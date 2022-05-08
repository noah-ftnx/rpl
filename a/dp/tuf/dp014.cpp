
bool subsetSumToKBF(int n, int k, vector<int> &arr);

bool subsetSumToKMMZ(int n, int k, vector<int> &arr);

bool subsetSumToKBU(int n, int k, vector<int> &arr);

bool subsetSumToKOPT(int n, int k, vector<int> &arr);



#include "test/dp014.h"
int main() {
  run_tests("BF", subsetSumToKBF);
  run_tests("MMZ", subsetSumToKMMZ);
  run_tests("BU", subsetSumToKBU);
  run_tests("OPT", subsetSumToKOPT);

  print_report();
  return 0;
}