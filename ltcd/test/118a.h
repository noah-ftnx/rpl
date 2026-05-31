#ifndef _H_
#define _H_

#include "../../../.inc/base.h"

vector<int> prototype(int numRows);
using fptr = decltype(prototype);

void test(fptr function, int n, vector<int> correct) {
  auto res = function(n);
  bool wrong = correct != res;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ") << "Input: " << n << endl;
  if (wrong) {
    cout << "Expected: ";
    for (auto v : correct) cout << v << ' ';
    cout << endl << "Got: ";
  }
  for (auto v : res) cout << v << ' ';
  cout << endl << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]: all results.\n";
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, 1, {1});
  test(function, 2, {1, 1});
  test(function, 3, {1, 2, 1});
  test(function, 5, {1, 4, 6, 4, 1});
  cout << endl;
}

#endif  // _H_
