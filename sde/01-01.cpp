
void setZeroesBF(vector<vector<int>>& matrix);

void setZeroesV2(vector<vector<int>>& matrix);

void setZeroesV3(vector<vector<int>>& matrix);



#include "test/01-01.h"
int main() {
  run_tests("BF", setZeroesBF);
  // run_tests("V2", setZeroesV2);
  // run_tests("V3", setZeroesV3);

  print_report();
  return 0;
}
