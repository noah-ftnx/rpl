
long countWaysToMakeChangeBF(int *denominations, int n, int value);

long countWaysToMakeChangeMMZ(int *denominations, int n, int value);

long countWaysToMakeChangeBU(int *denominations, int n, int value);

long countWaysToMakeChangeOPT(int *denominations, int n, int value);



#include "test/dp022.h"
int main() {
  run_tests("BF", countWaysToMakeChangeBF);
  // run_tests("MMZ", countWaysToMakeChangeMMZ);
  // run_tests("BU", countWaysToMakeChangeBU);
  // run_tests("OPT", countWaysToMakeChangeOPT);

  print_report();
  return 0;
}