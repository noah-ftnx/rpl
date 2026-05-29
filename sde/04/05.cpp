#include <vector>
using namespace std;

// IMPLEMENT: count subarrays with xor K
int subarraysXor(vector<int> &arr, int k);

#include "test/05.h"
int main() {
  run_tests(subarraysXor, "subarraysXor");
  print_report();
  return 0;
}
