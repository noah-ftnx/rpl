#ifndef RPL_A_BIT_TEST_LTCD78_BASE_H_
#define RPL_A_BIT_TEST_LTCD78_BASE_H_

#include <iostream>

void run_tests() {
  vector<int> nums {1, 2, 3};
  vector<vector<int>> correct {
      { },
      { 1 },
      { 2 },
      { 1, 2 },
      { 3 },
      { 1, 3 },
      { 2, 3 },
      { 1, 2, 3 },
  };

  auto powerset = subsetsBIT(nums);
  cout << "Powerset:\n";
  for (auto subset: powerset) {
    cout << "{ ";
    for (auto num: subset)
      cout << num << ", ";
    cout << "},\n";
  }

  cout << endl << (powerset != correct? "Wrong":"Correct") << " result\n";
}

#endif  // RPL_A_BIT_TEST_LTCD78_BASE_H_
