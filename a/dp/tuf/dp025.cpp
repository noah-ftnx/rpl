
int lcsBF(string s, string t);

int lcsMMZ(string s, string t);

int lcsBU(string s, string t);

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