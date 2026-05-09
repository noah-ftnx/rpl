
// IMPLEMENT: lcsBF
string lcsBF(string s, string t);

// IMPLEMENT: lcsMMZ
string lcsMMZ(string s, string t);

// IMPLEMENT: lcsBU
string lcsBU(string s, string t);

// IMPLEMENT: lcsOPT
string lcsOPT(string s, string t);

#include "test/dp026.h"
int main() {
  run_tests("BF", lcsBF);
  // run_tests("MMZ", lcsMMZ);
  // run_tests("BU", lcsBU);
  // run_tests("OPT", lcsOPT);

  print_report();
  return 0;
}