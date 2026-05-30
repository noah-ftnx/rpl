#ifndef RPL_SDE_11_TEST_02_H_
#define RPL_SDE_11_TEST_02_H_

#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

void check(string name, int (*function)(vector<vector<int>>&), vector<vector<int>> matrix, int correct) {
  int got = function(matrix);
  bool wrong = got != correct;
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name;
  if (wrong) cout << " (expected " << correct << ", got " << got << ")";
  cout << endl;
}

void run_tests(string msg, int (*function)(vector<vector<int>>&)) {
  cout << msg << ":\n";
  check("single_row", function, {{1, 3, 5}}, 3);
  check("sorted_3x3", function, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 5);
  check("dupes", function, {{1, 1, 2}, {2, 3, 3}, {3, 4, 5}}, 3);
  cout << endl;
}

#endif  // RPL_SDE_11_TEST_02_H_
