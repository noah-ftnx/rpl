
// IMPLEMENT: wildcardMatchingBF
bool wildcardMatchingBF(string pattern, string text);

// IMPLEMENT: wildcardMatchingMMZ
bool wildcardMatchingMMZ(string pattern, string text);

// IMPLEMENT: wildcardMatchingBU
bool wildcardMatchingBU(string pattern, string text);

// IMPLEMENT: wildcardMatchingOPT
bool wildcardMatchingOPT(string pattern, string text);



#include "test/dp034.h"
int main() {
  run_tests("BF", wildcardMatchingBF);
  // run_tests("MMZ", wildcardMatchingMMZ);
  // run_tests("BU", wildcardMatchingBU);
  // run_tests("OPT", wildcardMatchingOPT);

  print_report();
  return 0;
}