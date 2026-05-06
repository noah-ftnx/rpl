#ifndef RPL_DS_05T_TEST_19_DEGENERATE_BST_PREORDER_H_
#define RPL_DS_05T_TEST_19_DEGENERATE_BST_PREORDER_H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"
#include <iomanip>
#include <vector>
using namespace std;

void check(string name, vector<int> preorder, bool correct) {
  bool result = is_degenerate(preorder);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(24) << name;
  cout << setw(36) << to_string(preorder, 1);
  cout << boolalpha << result;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, true);
  check("one node", {10}, true);
  check("right chain", {3, 5, 10}, true);
  check("left chain", {10, 5, 3}, true);
  check("left then right", {10, 5, 7}, true);
  check("right then left", {10, 15, 12}, true);
  check("root gets 2 children", {10, 5, 15}, false);
  check("ancestor bound", {10, 5, 1, 7}, false);
  check("complex false", {8, 3, 1, 6, 4, 7, 10}, false);
  check("duplicate", {10, 5, 5}, false);
  cout << endl;
}

#endif  // RPL_DS_05T_TEST_19_DEGENERATE_BST_PREORDER_H_
