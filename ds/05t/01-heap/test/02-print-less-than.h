#ifndef RPL_DS_05T_01_HEAP_TEST_02_PRINT_LESS_THAN_H_
#define RPL_DS_05T_01_HEAP_TEST_02_PRINT_LESS_THAN_H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/to_string.h"
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

void check(string name, vector<int> heap, int val, vector<int> correct) {
  auto result = nodes_less_than(heap, val);
  sort(result.begin(), result.end());
  sort(correct.begin(), correct.end());

  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(18) << name;
  cout << "val=" << setw(4) << val;
  cout << setw(44) << to_string(heap, 1);
  cout << " -> " << to_string(result, 1);
  if (wrong) cout << " (WRONG. Expected: " << to_string(correct, 1) << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, 10, {});
  check("one below", {3}, 10, {3});
  check("one equal", {3}, 3, {});
  check("mixed", {2, 6, 3, 8, 9, 4, 15, 10, 25, 40, 24}, 10, {2, 3, 4, 6, 8, 9});
  check("prune root", {12, 15, 20, 18, 30}, 10, {});
  check("prune subtree", {2, 6, 3, 8, 20, 4, 15, 10, 25}, 10, {2, 3, 4, 6, 8});
  check("all below", {1, 2, 3, 4, 5}, 10, {1, 2, 3, 4, 5});
  cout << endl;
}

#endif  // RPL_DS_05T_01_HEAP_TEST_02_PRINT_LESS_THAN_H_
