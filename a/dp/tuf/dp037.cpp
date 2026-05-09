
// IMPLEMENT: getMaximumProfitBF
long getMaximumProfitBF(vector<int>& prices);

// IMPLEMENT: getMaximumProfitMMZ
long getMaximumProfitMMZ(vector<int>& prices);

// IMPLEMENT: getMaximumProfitBU
long getMaximumProfitBU(vector<int>& prices);

// IMPLEMENT: getMaximumProfitOPT
long getMaximumProfitOPT(vector<int>& prices);



#include "test/dp037.h"
int main() {
  run_tests("BF", getMaximumProfitBF);
  // run_tests("MMZ", getMaximumProfitMMZ);
  // run_tests("BU", getMaximumProfitBU);
  // run_tests("OPT", getMaximumProfitOPT);

  print_report();
  return 0;
}