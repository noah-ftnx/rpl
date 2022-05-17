
int maxCoinsBF(vector<int>& nums);

int maxCoinsMMZ(vector<int>& nums);

int maxCoinsBU(vector<int>& nums);



#include "test/dp051.h"
int main() {
  run_tests("BF", maxCoinsBF);
  // run_tests("MMZ", maxCoinsMMZ);
  // run_tests("BU", maxCoinsBU);
  // run_tests("OPT", maxCoinsBU);

  print_report();
  return 0;
}