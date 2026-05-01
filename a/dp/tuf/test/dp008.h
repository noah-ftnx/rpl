#ifndef INC_070__CPP_A_DP_TUF_TEST_008_H_
#define INC_070__CPP_A_DP_TUF_TEST_008_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

int prototype(int N, int M);
using fptr = decltype(prototype);

void test(fptr function, int n, int m, int correct) {
  int result = function(n, m);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << n << "x" << m << ": " << flush;

  cout << setw(3)  << result  << endl;
}

void print_report() {
  cout << endl << (_wrong ? "[FAIL] " : "[PASS] ") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test(function, 0, 0, 0);
  test(function, 0, 1, 0);
  test(function, 1, 0, 0);
  test(function, 1, 1, 1);
  test(function, 5, 1, 1);
  test(function, 2, 2, 2);
  test(function, 3, 2, 3);
  test(function, 3, 3, 6);
  test(function, 4, 4, 20);
  test(function, 5, 5, 70);
  cout << endl;
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_008_H_
