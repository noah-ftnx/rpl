
bool matchBF(string input, string pattern);

bool matchMMZ(string input, string pattern);

bool matchTD(string input, string pattern);



#include "test/025.h"
int main() {
  run_tests("BF", matchBF);
  run_tests("MMZ", matchMMZ);
  run_tests("TD", matchTD);
  print_errors();
  return 0;
}