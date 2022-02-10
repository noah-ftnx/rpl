#ifndef RPL_DCP_051_TEST_062_H_
#define RPL_DCP_051_TEST_062_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

int prototype(int N, int M);
using fptr = decltype(prototype);

void test(fptr function, int n, int m, int correct) {
  int result = function(n, m);
  cout << n << "x" << m << ": " << flush;

  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << result<< (wrong? " (WRONG)": "") << endl;

}

void print_report() {
  cout << endl <<  (_wrong? "WRONG RESULTS." : "Correct (all tests)") << endl;
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

  print_report();
}


#endif  // RPL_DCP_051_TEST_062_H_