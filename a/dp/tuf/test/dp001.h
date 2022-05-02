#ifndef INC_070__CPP_A_DP_TUF_TEST_DP001_H_
#define INC_070__CPP_A_DP_TUF_TEST_DP001_H_

#include <iostream>
#include <iomanip>
using namespace std;

int prototype(int N);
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
  test(function, -5, -1);
  test(function, 0, 0);
  test(function, 1, 1);
  test(function, 2, 1);
  test(function, 4, 3);
  test(function, 4, 3);
  test(function, 6, 8);
  test(function, 8, 21);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}


#endif  // INC_070__CPP_A_DP_TUF_TEST_DP001_H_
