#ifndef RPL_DCP_TEST_037_H_
#define RPL_DCP_TEST_037_H_

#include <iostream>
#include <iomanip>

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

  auto result = powerset(nums);
  cout << "Powerset:\n";
  for (auto subset: result) {
    cout << "{ ";
    for (auto num: subset)
      cout << num << ", ";
    cout << "},\n";
  }

  cout << endl << (result != correct? "Wrong":"Correct") << " result\n";
}

#endif  // RPL_DCP_TEST_037_H_
