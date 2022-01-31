#ifndef RPL_DCP_TEST_044_H_
#define RPL_DCP_TEST_044_H_

#include <iostream>
#include <iomanip>

void test(vector<int> input, int correct) {
  int result = count_inversions(input);

  for (auto i: input) cout << i << " ";

  cout << " inversions: " << result
       << (result!=correct? " (WRONG)": "") << endl;
}

void run_tests() {
  test({2, 4, 1, 3, 5}, 3);
  test({5, 4, 3, 2, 1}, 10);
  test({3, 2, 1}, 3);
  test({1, 2, 3 ,4 ,5}, 0);
}

#endif  // RPL_DCP_TEST_044_H_
