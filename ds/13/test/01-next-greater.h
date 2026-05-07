#ifndef RPL_DS_13_TEST_01_NEXT_GREATER_H_
#define RPL_DS_13_TEST_01_NEXT_GREATER_H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"
#include <iomanip>
#include <vector>
using namespace std;

void check(string name, vector<int> input, vector<int> correct) {
  auto result = input;
  find_next_greater_element(result);

  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(22) << name;
  cout << setw(38) << to_string(input, 1);
  cout << " -> ";
  cout << to_string(result, 1);
  if (wrong) cout << " (WRONG. Expected: " << to_string(correct, 1) << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, {});
  check("one item", {7}, {-1});
  check("increasing", {1, 2, 3, 4}, {2, 3, 4, -1});
  check("decreasing", {4, 3, 2, 1}, {-1, -1, -1, -1});
  check("mixed", {50, 20, 10, 80, 70, 100}, {80, 80, 80, 100, 100, -1});
  check("duplicates", {2, 2, 3, 1, 3}, {3, 3, -1, 3, -1});
  check("local greater", {4, 5, 2, 25}, {5, 25, 25, -1});
  cout << endl;
}

#endif  // RPL_DS_13_TEST_01_NEXT_GREATER_H_
