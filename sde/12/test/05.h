#ifndef RPL_SDE_12_TEST_05_H_
#define RPL_SDE_12_TEST_05_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

void check(string name, vector<vector<int>> input, vector<int> correct) {
  auto got = mergeKSortedArrays(input, input.size());
  bool wrong = got != correct;
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
}

void run_tests() {
  check("classic", {{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6});
  check("with_empty", {{}, {1}, {}}, {1});
  check("all_empty", {{}}, {});
  cout << endl;
}

#endif  // RPL_SDE_12_TEST_05_H_
