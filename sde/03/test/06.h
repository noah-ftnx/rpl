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
  test(fun, {1,3,2,3,1}, 2);
  test(fun, {2,4,3,5,1}, 3);
  test(fun, {}, 0);
  cout << endl;
}

#endif  // _H_
