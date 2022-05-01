
int solve_mazeBF(vector<vector<int>> maze);

int solve_mazeMMZ(vector<vector<int>> maze);

int solve_mazeBU(vector<vector<int>> maze);

int solve_mazeOPT(vector<vector<int>> maze);

int solve_mazeIN_PLACE(vector<vector<int>> maze);



#include "test/rtmz-cnt.h"
int main() {
  run_tests("BF", solve_mazeBF);
  // run_tests("MMZ", solve_mazeMMZ);
  // run_tests("BU", solve_mazeBU);
  // run_tests("OPT", solve_mazeOPT);
  // run_tests("IN PLACE", solve_mazeIN_PLACE);

  print_errors();
  return 0;
}