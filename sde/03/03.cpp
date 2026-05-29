#include <vector>
using namespace std;

// IMPLEMENT: majorityElement
int majorityElement(vector<int>& nums);

#include "test/03.h"
int main() {
  run_tests(majorityElement, "majorityElement");
  print_report();
  return 0;
}
