#ifndef RPL_DCP_051_TEST_070_H_
#define RPL_DCP_051_TEST_070_H_

#include "base.h"

void test(int N, int correct) {
  // int result = perfect_nth(N);
  int result = perfect_nth_fast(N);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "Num: " << setw(3) << N << ": " << setw(3) << result
       << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {
  test(1, 19);
  test(2, 28);
  test(3, 37);
  test(4, 46);
  test(5, 55);
  test(6, 64);
  test(7, 73);
  test(8, 82);
  test(9, 91);
  test(10, 109); // +9+9
  test(11, 118);
  test(12, 127);
  test(13, 136);
  test(14, 145);
  test(15, 154);
  test(16, 163);
  test(17, 172);
  test(18, 181);
  test(19, 190); // +9+9
  test(20, 208);
}

#endif  // RPL_DCP_051_TEST_070_H_
