
int palindromePartitioningBF(string str);

int palindromePartitioningMMZ(string str);

int palindromePartitioningBU(string str);



#include "test/dp053.h"
int main() {
  run_tests("BF", palindromePartitioningBF);
  run_tests("MMZ", palindromePartitioningMMZ);
  run_tests("BU", palindromePartitioningBU);
  // run_tests("OPT", palindromePartitioningBU);

  print_report();
  return 0;
}