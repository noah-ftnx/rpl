
// IMPLEMENT: cutRodBF
int cutRodBF(vector<int> &price, int n);

// IMPLEMENT: cutRodMMZ
int cutRodMMZ(vector<int> &price, int n);

// IMPLEMENT: cutRodBU
int cutRodBU(vector<int> &price, int n);

// IMPLEMENT: cutRodOPT
int cutRodOPT(vector<int> &price, int n);



#include "test/dp024.h"
int main() {
  run_tests("BF", cutRodBF);
  // run_tests("MMZ", cutRodMMZ);
  // run_tests("BU", cutRodBU);
  // run_tests("OPT", cutRodOPT);

  // print_report();
  return 0;
}