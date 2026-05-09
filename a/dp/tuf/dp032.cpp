
// IMPLEMENT: numDistinctBF
int numDistinctBF(string s, string t) ;

// IMPLEMENT: numDistinctMMZ
int numDistinctMMZ(string s, string t);

// IMPLEMENT: numDistinctBU
int numDistinctBU(string s, string t) ;

// IMPLEMENT: numDistinctOPT
int numDistinctOPT(string s, string t) ;



#include "test/dp032.h"
int main() {
  run_tests("BF", numDistinctBF);
  // run_tests("MMZ", numDistinctMMZ);
  // run_tests("BU", numDistinctBU);
  // run_tests("OPT", numDistinctOPT);

  print_report();
  return 0;
}