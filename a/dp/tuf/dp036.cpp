
long getMaximumProfitBF(vector<int> &prices);

long getMaximumProfitMMZ(vector<int> &prices);

long getMaximumProfitBU(vector<int> &prices);

long getMaximumProfitOPT(vector<int> &prices);



#include "test/dp036.h"
int main() {
  run_tests("BF", getMaximumProfitBF);
  // run_tests("MMZ", getMaximumProfitMMZ);
  // run_tests("BU", getMaximumProfitBU);
  // run_tests("OPT", getMaximumProfitOPT);

  print_report();
  return 0;
}