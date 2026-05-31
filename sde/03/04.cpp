#include <vector>
using namespace std;

// IMPLEMENT: majority element > n/3
vector<int> majorityElement(vector<int>& nums);

#include "test/04.h"
int main() {
  run_tests("majorityElement", majorityElement);
  print_report();
  return 0;
}
