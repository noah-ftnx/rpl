#ifndef INC_070__CPP_A_BT_TEST_REC_L18_H_
#define INC_070__CPP_A_BT_TEST_REC_L18_H_

#include <iostream>
#include <iomanip>

bool _wrong = false;

void test(int N, int K, string correct) {

  cout << "N: " << setw(3) << N << " K: " << setw(3) << K;
  auto result = kth_permutation(N, K);
  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << ": " << setw(10) << result << " ";
  cout << (wrong? "WRONG!" : "Correct.") << endl;
}

void run_tests() {

  test(4, 25, "<NAN>");
  test(4, 0, "<NAN>");
  test(4, -1, "<NAN>");
  test(0, 3, "<NAN>");

  test(4, 9, "2314");
  test(4, 10, "2341");
  test(4, 24, "4321");

  test(3, 1, "123");
  test(3, 6, "321");
  test(3, 3, "213");

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  } else {
    cout << "\nCorrect: ALL results.\n";
  }
}

#endif  // INC_070__CPP_A_BT_TEST_REC_L18_H_
