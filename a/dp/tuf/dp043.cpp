
int lengthOfLISBF_DP3(vector<int>& nums);

// binary search
int lengthOfLISBF_DP4(vector<int>& nums);



#include "test/dp041.h"
int main() {
  run_tests("DP3", lengthOfLISBF_DP3);
  run_tests("DP4", lengthOfLISBF_DP4);

  print_report();
  return 0;
}