
int min_additionsBF(string word);

int min_additionsMMZ(string word);

int min_additionsBU(string word);

int min_additionsOPT(string word);



#include "test/028.h"
int main() {
  run_tests("BF", min_additionsBF);
  run_tests("MMZ", min_additionsMMZ);
  run_tests("BU", min_additionsBU);
  run_tests("OPT", min_additionsOPT);

  print_errors();
  return 0;
}