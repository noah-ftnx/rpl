
int robBF(vector<int>& nums);

int robMMZ(vector<int>& nums);

int robBU(vector<int>& nums);

int robOPT(vector<int>& nums);



#include "test/dp006.h"
int main() {
  run_tests("BF", robBF);
  run_tests("TD", robMMZ);
  run_tests("BU", robBU);
  run_tests("OPT", robOPT);

  print_errors();
  return 0;
}