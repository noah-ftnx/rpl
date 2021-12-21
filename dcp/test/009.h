#ifndef RPL_DCP_TEST_009_H_
#define RPL_DCP_TEST_009_H_

#include <iostream>
#include <string>

int prototype(const vector<int>& v);
using fptr = decltype(prototype);

void check(string msg, fptr function, vector<int> v, int correct) {
  int r = function(v);
  cout << msg << ": " << r << (r!=correct? " (WRONG)": "")  << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  check("0", function, {}, 0);
  check("1", function, {5}, 5);
  check("2", function, {101, 50}, 101);
  check("3", function, {2, 4, 6, 2, 5}, 13);
  check("4", function, {5, 1, 1, 5}, 10);
  check("5", function, {5, 11, 1, 1, 1, 1, 300, 3}, 312);
  cout << endl;
}

#endif  // RPL_DCP_TEST_009_H_
