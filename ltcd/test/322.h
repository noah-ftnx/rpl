#ifndef RPL_LTCD_TEST_322_H_
#define RPL_LTCD_TEST_322_H_

#include ".inc/check.h"

void run_test(vector<int> coins, int amount, int correct) {
  Solution s;
  check_result("BF", s.coinChange(coins, amount), correct);
  check_result("MMZ", coinChangeMMZ(coins, amount), correct);
  check_result("BU", coinChangeBU(coins, amount), correct);
  check_result("OPT", coinChangeOPT(coins, amount), correct);
}

void run_tests() {
  run_test({1, 2, 5}, 11, 3);
  run_test({2}, 3, -1);
  run_test({1}, 0, 0);
}

#endif  // RPL_LTCD_TEST_322_H_
