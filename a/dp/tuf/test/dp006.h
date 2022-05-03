#ifndef INC_070__CPP_A_DP_TUF_TEST_DP006_H_
#define INC_070__CPP_A_DP_TUF_TEST_DP006_H_

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

void check(fptr function, vector<int> in, int correct) {
  int result = function(in);

  bool wrong = result !=correct;
  _wrong|=wrong;
  string s1;
  for (int i: in) s1+= to_string(i) + " ";
  cout << setw(20) << s1 << " |  Result: " << setw(5) << result << (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << endl;
  check(function, {}, 0);
  check(function, {100, 110, 50, 2, 40, 6}, 190);
  check(function, {500, 1,  2, 1, 1001}, 1003);
  check(function, {2 ,3, 2}, 3);
  check(function, {1,2,3,1}, 4);
  check(function, {1,5}, 5);
  check(function, {5, 1}, 5);
  check(function, {10}, 10);
  cout << endl;
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_DP006_H_