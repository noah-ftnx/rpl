#ifndef RPL_LTCD_TEST_704_H_
#define RPL_LTCD_TEST_704_H_

#include ".inc/check.h"

void run_test(vector<int> nums, int target, int correct) {
  Solution s;
  check_result("target " + to_string(target), s.search(nums, target), correct);
}

void run_tests() {
  run_test({-1, 0, 3, 5, 9, 12}, 9, 4);
  run_test({-1, 0, 3, 5, 9, 12}, 2, -1);
  run_test({-10, -4, 0, 7, 11}, -10, 0);
  run_test({-10, -4, 0, 7, 11}, 11, 4);
  run_test({-10, -4, 0, 7, 11}, 6, -1);
  run_test({5}, 5, 0);
  run_test({5}, -5, -1);
  run_test({1, 3}, 1, 0);
  run_test({1, 3}, 3, 1);
  run_test({1, 3}, 2, -1);
}

#endif  // RPL_LTCD_TEST_704_H_
