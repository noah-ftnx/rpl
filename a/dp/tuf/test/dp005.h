#ifndef INC_070__CPP_A_DP_TUF_TEST_DP005_H_
#define INC_070__CPP_A_DP_TUF_TEST_DP005_H_

#include <string>
#include <iostream>
#include <iomanip>

bool _wrong;
void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

int prototype(vector<int> &nums);
using fptr = decltype(prototype);

void check(fptr function, string msg, vector<int> in, int correct) {
  int result = function(in);

  bool wrong = result !=correct;
  _wrong|=wrong;
  string s1;
  for (int i: in) s1+= to_string(i) + " ";
  cout << setw(20) << s1 << " Result: " << setw(4) << result << (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << endl;
  check(function, "0", {}, 0);
  check(function, "1", {100, 110, 50, 2, 40, 6}, 190);
  check(function, "2", {500, 1,  2, 1, 1001}, 1503);
  cout << endl;
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_DP005_H_