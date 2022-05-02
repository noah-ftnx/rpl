#ifndef INC_070__CPP_A_DP_TUF_TEST_DP002_H_
#define INC_070__CPP_A_DP_TUF_TEST_DP002_H_

#include <iostream>
#include <iomanip>
using namespace std;

int prototype(long long nStairs);
using fptr = decltype(prototype);

bool _wrong;
void test(fptr function, int input, int correct) {
  auto result = function(input);
  bool wrong = result !=correct;
  _wrong|=wrong;
  cout << setw(10) << input << ": MSG: "  << result <<
      (wrong? " (WRONG)":"") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, 3, 3);
  test(function, 4, 5);
  test(function, 5, 8);
  test(function, 6, 13);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}


#endif  // INC_070__CPP_A_DP_TUF_TEST_DP002_H_