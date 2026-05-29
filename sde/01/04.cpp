#include <climits>
#include <vector>
using namespace std;

// IMPLEMENT: maxSubArray
int maxSubArray(vector<int>& nums);

#include "test/04.h"
int main() {
  run_tests("Sol", maxSubArray);

  print_report();
  return 0;
}
