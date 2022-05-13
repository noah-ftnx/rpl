
bool wildcardMatchingBF(string pattern, string text);

bool wildcardMatchingMMZ(string pattern, string text);

bool wildcardMatchingBU(string pattern, string text);

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