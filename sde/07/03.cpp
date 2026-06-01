#include <vector>
using namespace std;

// IMPLEMENT: threeSum
vector<vector<int>> threeSum(vector<int>& nums);

#include "test/03.h"
int main() {
  run_tests(threeSum, "threeSum");
  print_report();
  return 0;
}
