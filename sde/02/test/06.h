#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/vec.h"

long long prototype(vector<int> arr, int n);
using fptr = decltype(prototype);

void test(fptr function, vector<int> v1, int correct) {
  auto res = function(v1, v1.size());
  cout << setw(20) << to_string(v1) << " ";

  bool wrong = res!=correct;
  _wrong|=wrong;

  cout << ":\t " << setw(3) << res << (wrong? " (WRONG)": " correct") << endl;
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {2, 4, 1, 3, 5}, 3);
  test(function, {5, 4, 3, 2, 1}, 10);
  test(function, {3, 2, 1}, 3);
  test(function, {1, 2, 3 ,4 ,5}, 0);
  test(function, {5, 3, 2, 4, 1, 6}, 8);

  cout << endl;
}

#endif  // _H_
