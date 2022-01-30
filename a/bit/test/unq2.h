#ifndef RPL_A_BIT_TEST_UNQ2_H_
#define RPL_A_BIT_TEST_UNQ2_H_

#include <iostream>
#include <iomanip>

void test(vector<int> input, int correct) {
  int result = find_num(input);
  cout << "unique num: " << result <<
       (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test({2, 2, 3, 4, 3, 5, 7, 7, 5}, 4);
  test({2, 3, 3, 5, 7, 7, 5}, 2);
}


#endif  // RPL_A_BIT_TEST_UNQ2_H_
