#ifndef RPL_A_DP_TEST_001_H_
#define RPL_A_DP_TEST_001_H_

#include <iostream>


uint64_t prototype(int);
using fptr = decltype(prototype);

void check(string msg, fptr function, int n, int correct) {
  int res = function(n);
  cout << n << ": " <<  res << (res!=correct?" (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << endl;
  check(msg, function, 0, 0);
  // check(msg, function,1, 0);
  check(msg, function,3, 2);
  // check(msg, function,4, 9);
  // check(msg, function,8, 14833);
  check(msg, function,10, 1334961);
  cout << endl;
}

#endif  // RPL_A_DP_TEST_001_H_
