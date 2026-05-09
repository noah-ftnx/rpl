
// IMPLEMENT: maximumProfitBF
int maximumProfitBF(int fee, vector<int> &prices);

// IMPLEMENT: maximumProfitMMZ
int maximumProfitMMZ(int fee, vector<int> &prices);

// IMPLEMENT: maximumProfitBU
int maximumProfitBU(int fee, vector<int> &prices);

// IMPLEMENT: maximumProfitOPT
int maximumProfitOPT(int fee, vector<int> &prices);



#include "test/dp040.h"
int main() {
  run_tests("BF", maximumProfitBF);
  // run_tests("MMZ", maximumProfitMMZ);
  // run_tests("BU", maximumProfitBU);
  // run_tests("OPT", maximumProfitOPT);

  print_report();
  return 0;
}