#ifndef RPL_LTCD_TEST_560_H_
#define RPL_LTCD_TEST_560_H_

#include ".inc/check.h"

void run_test(vector<int> nums, int k, int correct) {
  Solution s;
  check_result("k " + to_string(k), s.subarraySum(nums, k), correct);
}

void run_tests() {
  run_test({1, 1, 1}, 2, 2);
  run_test({1, 2, 3}, 3, 2);
  run_test({1, -1, 0}, 0, 3);
  run_test({0, 0, 0}, 0, 6);
  run_test({3, 4, 7, 2, -3, 1, 4, 2}, 7, 4);
  run_test({-1, -1, 1}, 0, 1);
  run_test({5}, 5, 1);
  run_test({5}, 3, 0);
  run_test({1, 2, 1, 2, 1}, 3, 4);
  run_test({2, -2, 2, -2}, 0, 4);
  run_test({1, 1, 1, 1}, 2, 3);
  run_test({}, 0, 0);
}

#endif  // RPL_LTCD_TEST_560_H_
