
int minInsertionBF(string &s);

int minInsertionMMZ(string &s);

int minInsertionBU(string &s);

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