
// IMPLEMENT: shortestSupersequenceBF
string shortestSupersequenceBF(string a, string b);

// IMPLEMENT: shortestSupersequenceMMZ
string shortestSupersequenceMMZ(string a, string b);

// IMPLEMENT: shortestSupersequenceBU
string shortestSupersequenceBU(string a, string b);

// IMPLEMENT: shortestSupersequenceOPT
string shortestSupersequenceOPT(string a, string b);

#include "test/dp031.h"
int main() {
  run_tests("BF", shortestSupersequenceBF);
  // run_tests("MMZ", shortestSupersequenceMMZ);
  // run_tests("BU", shortestSupersequenceBU);
  // run_tests("OPT", shortestSupersequenceOPT);

  print_report();
  return 0;
}