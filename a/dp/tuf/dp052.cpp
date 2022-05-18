
int evaluateExpBF(string &exp);

int evaluateExpMMZ(string &exp);

int evaluateExpBU(string &exp);

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