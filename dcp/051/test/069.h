#ifndef RPL_DCP_051_TEST_069_H_
#define RPL_DCP_051_TEST_069_H_

#include "base.h"

void test(vector<int> input, int correct) {
  // int result = largest_product3(input);
  int result = largest_product3_slower(input);
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "Largest product: " << result
       << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {
  test({-10, -10, 5, 2}, 500);
  test({-10, -10, 5, 11}, 1100);
  test({-10, 5, 11}, -550);
  test({-10, 5, 0}, 0);
  test({-10, 5, 10, 0}, 0);
  test({-10, 5, 10, 0, 4}, 200);
  test({-5 -10, 5, 10, 0, 4}, 200);
  test({-5 -10, 6, 10, 0, 4}, 240);
  test({-10, -10, 2, 3, 10}, 1000);
  test({-10, -3, 2, 4, 10}, 300);
  test({-10, -3, 2, 2, 10}, 300);
}



#endif  // RPL_DCP_051_TEST_069_H_
