
// IMPLEMENT: string_distanceBF
int string_distanceBF(string a, string b);

// IMPLEMENT: string_distanceMMZ
int string_distanceMMZ(string a, string b);

// IMPLEMENT: string_distanceBU
int string_distanceBU(string a, string b);

// IMPLEMENT: string_distanceOPT
int string_distanceOPT(string a, string b);



#include "test/031.h"
int main() {
  run_tests("BF", string_distanceBF);
  // run_tests("MMZ", string_distanceMMZ);
  // run_tests("BU", string_distanceBU);
  // run_tests("OPT", string_distanceOPT);
  return 0;
}