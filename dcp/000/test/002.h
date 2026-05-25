#ifndef RPL_DCP_TEST_002_H_
#define RPL_DCP_TEST_002_H_

#include <vector>
#include "../../../.inc/check.h"

vector<int> sol1(vector<int>& vec);
vector<int> sol2(vector<int>& vec);

void check(string msg, vector<int> input, vector<int> correct) {
  vector<int> v1 = input;
  vector<int> v2 = input;
  check_result("div " + msg, sol1(v1), correct);
  check_result("no-div " + msg, sol2(v2), correct);
}

void run_tests() {
  check("v1", {1, 2, 3, 4, 5}, {120, 60, 40, 30, 24});
  check("v2", {3, 2, 1}, {2, 3, 6});
  check("v3", {10, 3, 5, 6, 2}, {180, 600, 360, 300, 900});
  check("v4", {4, 5}, {5, 4});
  check("v5", {7}, {7});
  check("v6", {}, {});
  check("v7", {1, 0, 3}, {0, 3, 0});
  check("v8", {0, 0, 3}, {0, 0, 0});
  check("v9", {-1, 2, -3}, {-6, 3, -2});
}

#endif  // RPL_DCP_TEST_002_H_