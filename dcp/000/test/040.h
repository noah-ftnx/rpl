#ifndef RPL_DCP_TEST_040_H_
#define RPL_DCP_TEST_040_H_

#include <iostream>
#include <iomanip>

void test(vector<int> input, int correct) {
  int result = find_num(input);
  cout << "unique num: " << result <<
      (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test({6, 1, 3, 3, 3, 6, 6}, 1);
  test({13, 19, 13, 13}, 19);
}


#endif  // RPL_DCP_TEST_040_H_
