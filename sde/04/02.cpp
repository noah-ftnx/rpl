#include <vector>
using namespace std;

// IMPLEMENT: fourSum
vector<vector<int>> fourSum(vector<int>& nums, int target);

#include "test/02.h"
int main() {
  run_tests("fourSum", fourSum);
  print_report();
  return 0;
}
