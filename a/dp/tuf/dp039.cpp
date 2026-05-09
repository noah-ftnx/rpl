
// IMPLEMENT: stockProfitBF
int stockProfitBF(vector<int> &prices);

// IMPLEMENT: stockProfitMMZ
int stockProfitMMZ(vector<int> &prices);

// IMPLEMENT: stockProfitBU
int stockProfitBU(vector<int> &prices);

// IMPLEMENT: stockProfitOPT
int stockProfitOPT(vector<int> &prices);



#include "test/dp039.h"
int main() {
  run_tests("BF", stockProfitBF);
  // run_tests("MMZ", stockProfitMMZ);
  // run_tests("BU", stockProfitBU);
  // run_tests("OPT", stockProfitOPT);

  print_report();
  return 0;
}