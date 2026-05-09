
// IMPLEMENT: minimumElementsBF
int minimumElementsBF(vector<int> &num, int x);

// IMPLEMENT: minimumElementsMMZ
int minimumElementsMMZ(vector<int> &num, int x);

// IMPLEMENT: minimumElementsBU
int minimumElementsBU(vector<int> &num, int x);

// IMPLEMENT: minimumElementsOPT
int minimumElementsOPT(vector<int> &num, int x);



#include "test/dp020.h"
int main() {
  run_tests("BF", minimumElementsBF);
  // run_tests("MMZ", minimumElementsMMZ);
  // run_tests("BU", minimumElementsBU);
  // run_tests("OPT", minimumElementsOPT);

  print_report();
  return 0;
}