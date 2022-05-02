
int frogJump2BF(int n, int k, vector<int> &heights);

int frogJump2MMZ(int n, int k, vector<int> &heights);

int frogJump2BU(int n, int k, vector<int> &heights);

int frogJump2OPT(int n, int k, vector<int> &heights);



#include "test/dp004.h"
int main() {
  run_tests("BF", frogJump2BF);
  // run_tests("TD", frogJump2MMZ);
  // run_tests("BU", frogJump2BU);
  // run_tests("OPT", frogJump2OPT);

  print_errors();
  return 0;
}