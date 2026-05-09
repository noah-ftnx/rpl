
// IMPLEMENT: minInsertionBF
int minInsertionBF(string &s);

// IMPLEMENT: minInsertionMMZ
int minInsertionMMZ(string &s);

// IMPLEMENT: minInsertionBU
int minInsertionBU(string &s);

// IMPLEMENT: minInsertionOPT
int minInsertionOPT(string &s);



#include "test/dp029.h"
int main() {
  run_tests("BF", minInsertionBF);
  // run_tests("MMZ", minInsertionMMZ);
  // run_tests("BU", minInsertionBU);
  // run_tests("OPT", minInsertionOPT);

  print_report();
  return 0;
}