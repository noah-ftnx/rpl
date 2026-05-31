#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"

int prototype(vector<int>& nums);
using fptr = decltype(prototype);

void test(fptr function, vector<int> v1, int correct) {
  auto res = function(v1);
  bool wrong = res!=correct;
  _wrong|=wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(20) << to_string(v1) << " ";

  cout << ":\t "  << setw(3) << res  << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {}, -1);
  test(function, {1,2}, -1);
  test(function, {1,2,3,4,5}, -1);
  test(function, {1,3,4,2,3}, 3);
  test(function, {1,2,4,2,3}, 2);
  test(function, {1,3,4,2,2}, 2);
  test(function, {1,2,3,4,5,6,7,7}, 7);
  test(function, {2,3,4,5,6,7,8,9,1,9}, 9);

  cout << endl;
}

#endif  // _H_
