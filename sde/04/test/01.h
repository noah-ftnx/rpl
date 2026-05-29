#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"

vector<int> prototype(vector<int>& nums, int target);
using fptr = decltype(prototype);

void test(fptr fun, vector<int> input, int target, vector<int> correct) {
  auto res=fun(input, target);
  bool wrong=res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(20) << to_string(input, 2);
  cout << " t=" << setw(3) << target;
  cout << " -> " << setw(12) << to_string(res, 2);
  if (wrong) cout << " (WRONG. Expected: " << to_string(correct, 2) << ")";
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg << ":\n";
  test(fun, {2,7,11,15}, 9, {0,1});
  test(fun, {3,2,4}, 6, {1,2});
  test(fun, {3,3}, 6, {0,1});
  cout << endl;
}

#endif  // _H_
