#ifndef RPL_A_BT_TEST_LTCD39_H_
#define RPL_A_BT_TEST_LTCD39_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> candidates, int target, vector<vector<int>> correct) {

  cout << "Candidates: ";
  for (auto i: candidates) cout << i << " ";
  cout << " Target: " << target << ":\n";

  auto result = combinationSum(candidates, target);

  for (auto combination: result) {
    for (int i: combination) cout << i << " ";
    cout << endl;
  }

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << (wrong? "WRONG!" : "Correct.") << endl << endl;
}

void run_tests() {
  test({2,3,6,7}, 7, {{2,2,3}, {7}});
  test({2,3,5}, 8, {{2,2,2,2}, {2,3,3}, {3,5}});
  test({2}, 1, {});
  test({}, 0, {{}});

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  }
}

#endif  // RPL_A_BT_TEST_LTCD39_H_
