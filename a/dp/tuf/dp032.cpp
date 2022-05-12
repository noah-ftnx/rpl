
int numDistinctBF(string s, string t) ;

int numDistinctMMZ(string s, string t);

int numDistinctBU(string s, string t) ;

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