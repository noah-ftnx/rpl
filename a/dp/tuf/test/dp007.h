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

int prototype(vector<vector<int>> &points);
using fptr = decltype(prototype);

void check(fptr function, string msg, vector<vector<int>> in2, int correct) {
  int result = function(in2);

  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << msg << " |  Result: " << setw(5) << result << (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << endl;
  check(function, "1", {{1,2,5}, {3 ,1 ,1} ,{3,3,3} },11);
  check(function, "2", {{10,2,5}, {3 ,1 ,1} ,{3,3,3} },14);
  check(function, "3", {{10,2,5} }, 10);
  cout << endl;
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_DP006_H_