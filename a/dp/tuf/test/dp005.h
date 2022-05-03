#ifndef INC_070__CPP_A_DP_TUF_TEST_DP005_H_
#define INC_070__CPP_A_DP_TUF_TEST_DP005_H_

#include <string>
#include <iostream>

bool _wrong;
void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

int prototype(vector<int> &nums);
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

#endif  // INC_070__CPP_A_DP_TUF_TEST_DP005_H_