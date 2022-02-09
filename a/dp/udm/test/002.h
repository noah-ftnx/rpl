#ifndef RPL_A_DP_TEST_002_H_
#define RPL_A_DP_TEST_002_H_

#include <string>
#include <iostream>

int prototype(const vector<int>& v);
using fptr = decltype(prototype);

void check(fptr function, string msg, vector<int> input, int correct) {
  int res = function(input);
  cout << msg << ": " << res << (res!=correct? " (WRONG)": "") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << endl;
  check(function, "0", {}, 0);
  check(function, "1", {100, 110, 50, 2, 40, 6}, 190);
  check(function, "2", {500, 1,  2, 1, 1001}, 1503);
  cout << endl;
}

#endif  // RPL_A_DP_TEST_002_H_
