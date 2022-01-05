#ifndef RPL_DCP_TEST_018_H_
#define RPL_DCP_TEST_018_H_

#include <iostream>
void test(vector<int> input, int k, vector<int> correct) {
  auto result = largest_subarray(input, k);

  cout << "input: ";
  for (auto i: input) cout << i << " ";
  cout << "\nresult: ";
  for (auto i: result) cout << i << " ";
  cout << (result!=correct? ": (WRONG)":"") << endl << endl;
}

void run_tests() {
  test({10, 5, 2, 7, 8, 7}, 3, {10, 7, 8, 8});
  test({3,4,5,10,3,5,2,6,7,10}, 4, {10, 10, 10, 10, 6, 7, 10});
}

#endif  // RPL_DCP_TEST_018_H_