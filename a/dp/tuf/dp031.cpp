
string shortestSupersequenceBF(string a, string b);

string shortestSupersequenceMMZ(string a, string b);

string shortestSupersequenceBU(string a, string b);

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