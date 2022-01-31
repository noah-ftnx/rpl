#ifndef RPL_A_SRT_TEST_MSORT_H_
#define RPL_A_SRT_TEST_MSORT_H_

#include <iostream>

void test(vector<int> input, vector<int> correct) {
  merge_sort(input); // inplace sorting
  bool wrong = correct != input;

  for (auto v: input) cout << v << " ";
  cout << endl; for (auto v: correct) cout << v << " ";
  cout << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {
  vector<int> input1 {34, -6, 45, 30, 677, 4, 0, -16};
  vector<int> sorted1 {-16, -6, 0, 4, 30, 34, 45, 677};
  vector<int> input2 {3, -5, 1, 7, 0};
  vector<int> sorted2 {-5, 0, 1, 3, 7};

  test(input1, sorted1);
  test(input2, sorted2);
}

#endif  // RPL_A_SRT_TEST_MSORT_H_
