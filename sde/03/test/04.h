#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include <algorithm>

vector<int> prototype(vector<int>& nums);
using fptr = decltype(prototype);

void test(fptr fun, vector<int> input, vector<int> correct) {
  vector<int> res = fun(input);
  sort(res.begin(), res.end());
  sort(correct.begin(), correct.end());
  bool wrong = res != correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  for (auto v: input) cout << v << ' ';
  cout << "-> ";
  for (auto v: res) cout << v << ' ';
  if (wrong) {
    cout << "(WRONG. Expected: ";
    for (auto v: correct) cout << v << ' ';
    cout << ")";
  }
  cout << endl;
}

void run_tests(string msg, fptr fun) {
  cout << msg << ":\n";
  test(fun, {3,2,3}, {3});
  test(fun, {1}, {1});
  test(fun, {1,2}, {1,2});
  test(fun, {1,1,1,3,3,2,2,2}, {1,2});
  test(fun, {2,2}, {2});
  test(fun, {0,0,0}, {0});
  test(fun, {-1,-1,-1,0,1,2}, {-1});
  test(fun, {1,2,3,1,2,1,1}, {1});
  cout << endl;
}

#endif  // _H_
