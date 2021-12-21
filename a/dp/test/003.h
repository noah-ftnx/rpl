#ifndef RPL_A_DP_TEST_003_H_
#define RPL_A_DP_TEST_003_H_

#include <iostream>
using namespace std;

int prototype(const vector<int>& vec);
using fptr = decltype(prototype);

void check(string msg, fptr function, const vector<int>& input, int correct) {
  int res = function(input);
  cout << res << (res!=correct? " (WRONG)": "") << endl;
}

void run_tests(string method, fptr function) {
  cout << method  << ":" << endl;
  check("0", function, {0}, 0);
  check("1", function, {2}, 2);
  check("2", function, {2, 3, -5}, 5);
  check("3", function, {3, 5, -4}, 8);
  check("4", function, {5, -4, 8, -10, -2, 4, -3, 2, 7, -8, 3, -5, 3 }, 10);
  // vector<int> vbig (10000, 1);
  // check(msg, function, vbig);
  cout << endl;
}

#endif  // RPL_A_DP_TEST_003_H_
