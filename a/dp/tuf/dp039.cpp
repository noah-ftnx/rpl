
int stockProfitBF(vector<int> &prices);

int stockProfitMMZ(vector<int> &prices);

int stockProfitBU(vector<int> &prices);

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