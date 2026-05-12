#ifndef RPL_SDE_08_TEST_06_H_
#define RPL_SDE_08_TEST_06_H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"
#include <iomanip>
#include <vector>
using namespace std;

void check(string name, vector<int> start, vector<int> finish, int correct) {
  int result = maximumActivities(start, finish);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(20) << name;
  cout << "start=" << setw(22) << to_string(start, 1);
  cout << "finish=" << setw(22) << to_string(finish, 1);
  cout << " -> " << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void run_tests() {
  check("empty", {}, {}, 0);
  check("one activity", {7}, {10}, 1);
  check("sorted sample", {1, 3, 0, 5, 8, 5}, {2, 4, 6, 7, 9, 9}, 4);
  check("unsorted sample", {5, 1, 3, 0, 8, 5}, {7, 2, 4, 6, 9, 9}, 4);
  check("touching", {1, 10, 20}, {10, 20, 30}, 3);
  check("overlapping", {1, 2, 3}, {10, 9, 8}, 1);
  check("same interval", {1, 1, 1}, {2, 2, 2}, 1);
  check("all chain", {0, 1, 2, 3}, {1, 2, 3, 4}, 4);
  cout << endl;
  print_report();
}

#endif  // RPL_SDE_08_TEST_06_H_
