#ifndef RPL_A_RECV_TEST_01_PARAM_SUM_H_
#define RPL_A_RECV_TEST_01_PARAM_SUM_H_

#include <iostream>
using namespace std;

bool _wrong = false;

void test(int N, int expected) {
  int result = parameterized_sum(N);
  bool wrong = result != expected;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << "Result: " << result << " Expected: " << expected;
  cout << " (N=" << N << ")" << endl;
}

void run_tests() {
  test(0, 0);
  test(1, 1);
  test(3, 6);
  test(4, 10);
  test(10, 55);

  if (_wrong) {
    cout << "[FAIL]\n";
  } else {
    cout << "[PASS]: ALL results.\n";
  }
}

#endif  // RPL_A_RECV_TEST_01_PARAM_SUM_H_
