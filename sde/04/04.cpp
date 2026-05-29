#include <vector>
using namespace std;

// IMPLEMENT: largest zero-sum subarray length
int maxLen(vector<int> &A);

#include "test/04.h"
int main() {
  run_tests(maxLen, "maxLen");
  print_report();
  return 0;
}
