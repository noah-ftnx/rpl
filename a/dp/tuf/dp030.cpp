
// IMPLEMENT: canYouMakeBF
int canYouMakeBF(string &s, string &t);

// IMPLEMENT: canYouMakeMMZ
int canYouMakeMMZ(string &s, string &t);

// IMPLEMENT: canYouMakeBU
int canYouMakeBU(string &s, string &t);

// IMPLEMENT: canYouMakeOPT
int canYouMakeOPT(string &s, string &t);



#include "test/dp030.h"
int main() {
  run_tests("BF", canYouMakeBF);
  // run_tests("MMZ", canYouMakeMMZ);
  // run_tests("BU", canYouMakeBU);
  // run_tests("OPT", canYouMakeOPT);

  print_report();
  return 0;
}