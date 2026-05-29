#ifndef _H_
#define _H_

#include "../../../.inc/base.h"

int prototype(vector<int>& nums);
using fptr = decltype(prototype);

void test(fptr fun, vector<int> input, int correct) {
  int res=fun(input);
  bool wrong=res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  for (auto v: input) cout << v << ' ';
  cout << "-> " << res;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg << ":\n";
  test(fun, {3,2,3}, 3);
  test(fun, {2,2,1,1,1,2,2}, 2);
  test(fun, {1}, 1);
  cout << endl;
}

#endif  // _H_
