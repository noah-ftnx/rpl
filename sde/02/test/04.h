#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/vec.h"

int prototype(vector<int>& nums);
using fptr = decltype(prototype);

void test(fptr function, vector<int> v1, int correct) {
  auto res = function(v1);
  cout << setw(20) << to_string(v1) << " ";

  bool wrong = res!=correct;
  _wrong|=wrong;

  cout << ":\t " << setw(3) << res << (wrong? " (WRONG)": " correct") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {}, -1);
  test(function, {1,2}, -1);
  test(function, {1,3,4,2,3}, 3);
  test(function, {1,2,4,2,3}, 2);
  test(function, {1,3,4,2,2}, 2);

  cout << endl;
}

#endif  // _H_
