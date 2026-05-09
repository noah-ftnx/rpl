
// IMPLEMENT: ninjaTrainingBF
int ninjaTrainingBF(vector<vector<int>> &points);

// IMPLEMENT: ninjaTrainingMMZ
int ninjaTrainingMMZ(vector<vector<int>> &points);

// IMPLEMENT: ninjaTrainingBU
int ninjaTrainingBU(vector<vector<int>> &points);

// IMPLEMENT: ninjaTrainingOPT
int ninjaTrainingOPT(vector<vector<int>> &points);



#include "test/dp007.h"
int main() {
  run_tests("BF", ninjaTrainingBF);
  // run_tests("TD", ninjaTrainingMMZ);
  // run_tests("BU", ninjaTrainingBU);
  // run_tests("OPT", ninjaTrainingOPT);

  print_errors();
  return 0;
}