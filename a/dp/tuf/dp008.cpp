
int uniquePathsBF(int m, int n);

int uniquePathsMMZ(int m, int n);

int uniquePathsBU(int m, int n);

int uniquePathsOPT(int m, int n);



#include "test/dp008.h"
int main() {
  run_tests("BF", uniquePathsBF);
  // run_tests("MMZ", uniquePathsMMZ);
  // run_tests("BU", uniquePathsBU);
  // run_tests("OPT", uniquePathsOPT);

  print_report();
  return 0;
}