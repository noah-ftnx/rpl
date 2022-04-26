#ifndef INC_070__CPP_DCP_051_TEST_074_H_
#define INC_070__CPP_DCP_051_TEST_074_H_

#include <iostream>
#include <iomanip>
using namespace std;
bool _wrong=false;

void test(int N, int X, int correct) {
  int result = solve(N, X);
  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << "N:" << left << setw(3) << N << " X:" << setw(3) << X
       << " Result: " <<  setw(3) << result
       << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {
  test(0, 0, 0);
  test(1, 1, 1);

  test(3, 1, 1);
  test(3, 6, 2);
  test(3, 9, 1);
  test(3, 10, 0);

  test(6, 12, 4);
  test(6, 1, 1);
  test(6, 6, 4);
  test(6, 36, 1);
  test(6, 30, 2);
  test(6, 20, 2);
  test(6, 16, 1);
}

#endif  // INC_070__CPP_DCP_051_TEST_074_H_
