
int maximumProfitBF(vector<int> &prices, int k);

int maximumProfitMMZ(vector<int> &prices, int k);

int maximumProfitBU(vector<int> &prices, int k);

int maximumProfitOPT(vector<int> &prices, int k)



#include "test/dp038.h"
int main() {
  run_tests("BF", maximumProfitBF);
  // run_tests("MMZ", maximumProfitMMZ);
  // run_tests("BU", maximumProfitBU);
  // run_tests("OPT", maximumProfitOPT);

  print_report();
  return 0;
}