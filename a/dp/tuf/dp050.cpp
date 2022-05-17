
int costBF(int n, int c, vector<int> &cuts);

int costMMZ(int n, int c, vector<int> &cuts);

int costBU(int n, int c, vector<int> &cuts);



#include "test/dp050.h"
int main() {
  run_tests("DP", costBF);
  // run_tests("MMZ", costMMZ);
  // run_tests("BU", costBU);
  // run_tests("OPT", costOPT);

  print_report();
  return 0;
}