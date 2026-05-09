
// IMPLEMENT: fiboBF
int fiboBF(int N);

// IMPLEMENT: fiboMMZ
int fiboMMZ(int N);

// IMPLEMENT: fiboBU
int fiboBU(int N);

// IMPLEMENT: fiboOPT
int fiboOPT(int N);



#include "test/dp001.h"
int main() {
  run_tests("BF", fiboBF);
  run_tests("TD", fiboMMZ);
  run_tests("BU", fiboBU);
  run_tests("OPT", fiboOPT);

  print_errors();
  return 0;
}