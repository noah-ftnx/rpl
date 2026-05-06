#ifndef _H_
#define _H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/to_string.h"


void prototype(vector<int> &vec);
using fptr = decltype(prototype);

void test(fptr fun, const vector<int> input, vector<int> correct) {
  auto vec = input;  // copy
  fun(vec);
  bool wrong = vec != correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(30) << to_string(input, 2);
  cout << "  ->  ";
  cout << setw(30) << to_string(vec, 3);

  if (wrong) cout << " (WRONG. Expected: " << to_string(correct, 3) << ")";
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg  << ":\n";
  test(fun, {}, {});
  test(fun, {3}, {3});
  test(fun, {3, 10}, {3, 10});
  test(fun, {10, 3}, {3, 10});
  test(fun, {25, 3, 10, 15, 2, 40}, {2, 3, 10, 15, 25, 40});
  test(fun, {9, 8, 7, 6, 5, 4, 3}, {3, 4, 5, 6, 7, 8, 9});
  test(fun, {5, 1, 5, 1, 3}, {1, 1, 3, 5, 5});

  cout << endl;
}

#endif  // _H_
