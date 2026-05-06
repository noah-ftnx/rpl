#ifndef RPL_DS_05T_01_HEAP_TEST_03_CHECK_ARRAY_IS_HEAP_H_
#define RPL_DS_05T_01_HEAP_TEST_03_CHECK_ARRAY_IS_HEAP_H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/to_string.h"
#include <iomanip>
#include <vector>
using namespace std;

void check(string name, vector<int> input, bool correct) {
  bool result = is_min_heap(input);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(22) << name;
  cout << setw(42) << to_string(input, 1);
  cout << boolalpha << result;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, true);
  check("one node", {10}, true);
  check("valid small", {2, 6, 3, 8, 9, 4, 15}, true);
  check("valid duplicates", {2, 2, 3, 8, 9, 4}, true);
  check("bad left child", {2, 1, 3}, false);
  check("bad right child", {2, 6, 1}, false);
  check("bad deeper", {2, 6, 3, 8, 1, 4}, false);
  check("maxheap not minheap", {9, 8, 7, 6, 5}, false);
  cout << endl;
}

#endif  // RPL_DS_05T_01_HEAP_TEST_03_CHECK_ARRAY_IS_HEAP_H_
