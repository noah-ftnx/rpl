
int lcstrBF(string s, string t);

int lcstrMMZ(string s, string t);

int lcstrBU(string s, string t);

int lcstrOPT(string s, string t);



#include "test/dp027.h"
int main() {
  run_tests("BF", lcstrBF);
  run_tests("MMZ", lcstrMMZ);
  run_tests("BU", lcstrBU);
  run_tests("OPT", lcstrOPT);

  print_report();
  return 0;
}