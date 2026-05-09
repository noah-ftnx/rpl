
// IMPLEMENT: frogJumpBF
int frogJumpBF(int n, vector<int> &heights);

// IMPLEMENT: frogJumpMMZ
int frogJumpMMZ(int n, vector<int> &heights);

// IMPLEMENT: frogJumpBU
int frogJumpBU(int n, vector<int> &heights);

// IMPLEMENT: frogJumpOPT
int frogJumpOPT(int n, vector<int> &heights);



#include "test/dp003.h"
int main() {
  run_tests("BF", frogJumpBF);
  // run_tests("TD", frogJumpMMZ);
  // run_tests("BU", frogJumpBU);
  // run_tests("OPT", frogJumpOPT);

  print_errors();
  return 0;
}