
int minimumElementsBF(vector<int> &num, int x);

int minimumElementsMMZ(vector<int> &num, int x);

int minimumElementsBU(vector<int> &num, int x);



#include "test/dp054.h"
int main() {
  run_tests("BF", minimumElementsBF);
  // run_tests("MMZ", minimumElementsMMZ);
  // run_tests("BU", minimumElementsBU);
  // run_tests("OPT", minimumElementsOPT);

  print_report();
  return 0;
}