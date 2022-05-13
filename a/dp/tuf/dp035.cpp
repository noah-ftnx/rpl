
int maximumProfitBF(vector<int> &prices);

int maximumProfitMMZ(vector<int> &prices);

int maximumProfitBU(vector<int> &prices);

int maximumProfitOPT(vector<int> &prices);



#include "test/dp035.h"
int main() {
  run_tests("BF", maximumProfitBF);
  // run_tests("MMZ", maximumProfitMMZ);
  // run_tests("BU", maximumProfitBU);
  // run_tests("OPT", maximumProfitOPT);

  print_report();
  return 0;
}