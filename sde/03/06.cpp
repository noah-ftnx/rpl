#include <vector>
using namespace std;

// IMPLEMENT: reversePairs
int reversePairs(vector<int>& nums);

#include "test/06.h"
int main() {
  run_tests(reversePairs, "reversePairs");
  print_report();
  return 0;
}
