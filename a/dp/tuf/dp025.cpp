
// IMPLEMENT: lcsBF
int lcsBF(string s, string t);

// IMPLEMENT: lcsMMZ
int lcsMMZ(string s, string t);

// IMPLEMENT: lcsBU
int lcsBU(string s, string t);

// IMPLEMENT: lcsOPT
int lcsOPT(string s, string t);



#include "test/dp025.h"
int main() {
  run_tests("BF", lcsBF);
  // run_tests("MMZ", lcsMMZ);
  // run_tests("BU", lcsBU);
  // run_tests("OPT", lcsOPT);

  print_report();
  return 0;
}