
int minDistanceBF(string s, string t);

int minDistanceMMZ(string s, string t);

int minDistanceBU(string s, string t);

int minDistanceOPT(string s, string t);



#include "test/dp033.h"
int main() {
  run_tests("BF", minDistanceBF);
  // run_tests("MMZ", minDistanceMMZ);
  // run_tests("BU", minDistanceBU);
  // run_tests("OPT", minDistanceOPT);

  print_report();
  return 0;
}