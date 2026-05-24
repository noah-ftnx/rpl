#ifndef RPL_A_BT_TEST_LTCD78_BASE_H_
#define RPL_A_BT_TEST_LTCD78_BASE_H_

#include <algorithm>
#include <iostream>

void normalize(vector<vector<int>> &powerset) {
  for (auto &subset: powerset) {
    sort(subset.begin(), subset.end());
  }
  sort(powerset.begin(), powerset.end());
}

void run_tests() {
  vector<int> nums {1, 2, 3};
  vector<vector<int>> correct {
      { },
      { 1 },
      { 1, 2 },
      { 1, 2, 3 },
      { 1, 3 },
      { 2 },
      { 2, 3 },
      { 3 }
  };

  auto powerset = subsets(nums);
  normalize(powerset);
  normalize(correct);

  cout << "Powerset:\n";
  for (auto subset: powerset) {
    cout << "{ ";
    for (auto num: subset)
      cout << num << ", ";
    cout << "},\n";
  }

  cout << endl << (powerset != correct ? "[FAIL] " : "[PASS] ") << " result\n";
}

#endif  // RPL_A_BT_TEST_LTCD78_BASE_H_
