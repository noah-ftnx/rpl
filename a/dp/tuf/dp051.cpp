
// IMPLEMENT: maxCoinsBF
int maxCoinsBF(vector<int>& nums);

// IMPLEMENT: maxCoinsMMZ
int maxCoinsMMZ(vector<int>& nums);

// IMPLEMENT: maxCoinsBU
int maxCoinsBU(vector<int>& nums);

// IMPLEMENT: maxCoinsOPT
int maxCoinsOPT(vector<int>& nums);



#include "test/dp051.h"
int main() {
  run_tests("BF", maxCoinsBF);
  // run_tests("MMZ", maxCoinsMMZ);
  // run_tests("BU", maxCoinsBU);
  // run_tests("OPT", maxCoinsBU);

  print_report();
  return 0;
}