#ifndef RPL_A_SRT_TEST_MSORT2_H_
#define RPL_A_SRT_TEST_MSORT2_H_

#include <vector>
#include <iostream>
#include <iomanip>

void test(vector<int> input, vector<int> correct) {
  merge_sort(input);
  bool wrong = correct != input;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  for (auto v: input) cout << setw(3) << v << " ";
  cout << endl; for (auto v: correct) cout << setw(3) << v << " ";
  cout << endl;
}

void run_tests() {
  vector<int> input0 {};
  vector<int> sorted0 {};
  vector<int> input1 {7};
  vector<int> sorted1 {7};
  vector<int> input2 {34, -6, 45, 30, 677, 4, 0, -16};
  vector<int> sorted2 {-16, -6, 0, 4, 30, 34, 45, 677};
  vector<int> input3 {3, -5, 1, 7, 0};
  vector<int> sorted3 {-5, 0, 1, 3, 7};

  test(input0, sorted0);
  test(input1, sorted1);
  test(input2, sorted2);
  test(input3, sorted3);
}

#endif  // RPL_A_SRT_TEST_MSORT2_H_
