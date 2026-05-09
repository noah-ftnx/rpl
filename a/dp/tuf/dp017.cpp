
// IMPLEMENT: findWaysBF
int findWaysBF(vector<int> &num, int tar);

// IMPLEMENT: findWaysMMZ
int findWaysMMZ(vector<int> &num, int tar);

// IMPLEMENT: findWaysBU
int findWaysBU(vector<int> &num, int tar);

// IMPLEMENT: findWaysOPT
int findWaysOPT(vector<int> &num, int tar);



#include "test/dp017.h"
int main() {
  run_tests("BF", findWaysBF);
  // run_tests("MMZ", findWaysMMZ);
  // run_tests("BU", findWaysBU);
  // run_tests("OPT", findWaysOPT);

  print_report();
  return 0;
}