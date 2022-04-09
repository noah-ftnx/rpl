#ifndef RPL_DCP_TEST_004_H_
#define RPL_DCP_TEST_004_H_

#include <iostream>
#include "../../../.check/check.h"

int find_first_missing(vector<int>& vec);

void run_tests() {
  vector<int> v0 {};
  vector<int> v1 {0};
  vector<int> v2 {1};
  vector<int> v3 {5};
  vector<int> v4 {1, 2, 3};
  vector<int> v5 {3, 2, 1};
  vector<int> v6 {3, -1, 1};
  vector<int> v7 {-1, -1, 1};
  vector<int> v8 {-1, -1, -1};
  vector<int> v9 {3, -1, 1, 2};
  vector<int> v10 {3, 1, -1, 4};
  vector<int> v11 {3, 2, -1, 4};
  vector<int> v12 {3, -1, 1, -1, 1, 4, 3};
  check_result(" v0", find_first_missing(v0), -1);
  check_result(" v1", find_first_missing(v1), 1);
  check_result(" v2", find_first_missing(v2), 2);
  check_result(" v3", find_first_missing(v3), 1);
  check_result(" v4", find_first_missing(v4), 4);
  check_result(" v5", find_first_missing(v5), 4);

  check_result(" v6", find_first_missing(v6), 2);
  check_result(" v7", find_first_missing(v7), 2);
  check_result(" v8", find_first_missing(v8), 1);
  check_result(" v9", find_first_missing(v9), 4);

  check_result("v10", find_first_missing(v10), 2);
  check_result("v11", find_first_missing(v11), 1);
  check_result("v11", find_first_missing(v12), 2);
}

void run_tests(vector<vector<int>> tc) {
  run_tests();
  cout << endl;
  if (tc.empty()) { cout << "extra test-cases empty.\n"; return; }
  for (auto test: tc) {
    for (auto v: test) cout << v << " ";
    cout << ": missing: " << find_first_missing(test) << endl;
  }
}

#endif  // RPL_DCP_TEST_004_H_
