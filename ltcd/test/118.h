#ifndef _H_
#define _H_

#include "../../../.inc/base.h"

vector<vector<int>> prototype(int numRows);
using fptr = decltype(prototype);

void test(fptr function, int n, vector<vector<int>> correct) {
  auto res = function(n);
  bool wrong = correct != res;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ") << "Input: " << n << endl;
  if (wrong) {
    cout << "Expected:\n";
    for (auto row : correct) {
      for (auto v : row) cout << v << ' ';
      cout << endl;
    }
    cout << "Got:\n";
  }
  for (auto row : res) {
    for (auto v : row) cout << v << ' ';
    cout << endl;
  }
  cout << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]: all results.\n";
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, -1, {});
  test(function, 0, {});
  test(function, 1, {{1}});
  test(function, 2, {{1}, {1, 1}});
  test(function, 3, {{1}, {1, 1}, {1, 2, 1}});
  test(function, 5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}});
  cout << endl;
}

#endif  // _H_
