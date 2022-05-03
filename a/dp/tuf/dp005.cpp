
int maximumNonAdjacentSumBF(vector<int> &nums);

int maximumNonAdjacentSumMMZ(vector<int> &nums);

int maximumNonAdjacentSumBU(vector<int> &nums);

int maximumNonAdjacentSumOPT(vector<int> &nums);



#include "test/dp005.h"
int main() {
  run_tests("BF", maximumNonAdjacentSumBF);
  // run_tests("TD", maximumNonAdjacentSumMMZ);
  // run_tests("BU", maximumNonAdjacentSumBU);
  // run_tests("OPT", maximumNonAdjacentSumOPT);

  print_errors();
  return 0;
}