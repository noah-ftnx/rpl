
// IMPLEMENT: evaluateExpBF
int evaluateExpBF(string &exp);

// IMPLEMENT: evaluateExpMMZ
int evaluateExpMMZ(string &exp);

// IMPLEMENT: evaluateExpBU
int evaluateExpBU(string &exp);

// IMPLEMENT: evaluateExpOPT
int evaluateExpOPT(string &exp);



#include "test/dp052.h"
int main() {
  run_tests("BF", evaluateExpBF);
  // run_tests("MMZ", evaluateExpMMZ);
  // run_tests("BU", evaluateExpBU);
  // run_tests("OPT", evaluateExpOPT);

  print_report();
  return 0;
}