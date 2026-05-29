#ifndef RPL_LTCD_TEST_2332_H_
#define RPL_LTCD_TEST_2332_H_

#include ".inc/check.h"

void run_test(vector<int> buses, vector<int> passengers, int capacity, int correct) {
  Solution s;
  check_result("latest time", s.latestTimeCatchTheBus(buses, passengers, capacity), correct);
}

void run_tests() {
  run_test({10, 20}, {2, 17, 18, 19}, 2, 16);
  run_test({20, 30, 10}, {19, 13, 26, 4, 25, 11, 21}, 2, 20);
  run_test({10}, {2, 3, 4}, 2, 1);
  run_test({10}, {2, 3, 4}, 4, 10);
  run_test({3}, {2, 3}, 2, 1);
  run_test({5, 10}, {4, 5, 9, 10}, 2, 8);
  run_test({5, 10}, {5, 6, 7, 8}, 2, 4);
}

#endif  // RPL_LTCD_TEST_2332_H_
