#ifndef _H_
#define _H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/to_string.h"


void prototype(vector<int> &vec);
using fptr = decltype(prototype);

void test(fptr fun, const vector<int> input, vector<int> correct) {
  cout << setw(30) << to_string(input, 2);

 auto vec = input;  // copy
 fun(vec);

  cout << "  ->  ";
  cout << setw(30) << to_string(vec, 3);

  bool wrong = vec != correct;
  _wrong|=wrong;

  cout  <<  (wrong? " (WRONG)": " correct") << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg  << ":\n";
  test(fun, {25, 3, 10, 15, 2, 40}, {2, 3, 10, 15, 25, 40});

  test(fun, {3}, {3});
  test(fun, {3, 10}, {3, 10});
  test(fun, {10, 3}, {3, 10});

  cout << endl;
}

#endif  // _H_
