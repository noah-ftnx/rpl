#include <vector>
using namespace std;

// IMPLEMENT: twoSum
vector<int> twoSum(vector<int>& nums, int target);

#include "test/01.h"
int main() {
  run_tests(twoSum, "twoSum");
  print_report();
  return 0;
}
