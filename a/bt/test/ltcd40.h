#ifndef RPL_A_BT_TEST_LTCD40_H_
#define RPL_A_BT_TEST_LTCD40_H_

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

  test({10,1,2,7,6,1,5}, 8, {
      {1,1,6},
      {1,2,5},
      {1,7},
      {2,6}
  });

  test({2,5,2,1,2}, 5, {
    {1,2,2},
    {5}
  });

  test({}, 0, {{}});

  test({2,3,1,6,7}, 7, {{1,6}, {7}});
  test({2,3,5}, 8, {{3,5}});
  test({1}, 2, {});

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  } else {
    cout << "\nCorrect: ALL results.\n";
  }
}

#endif  // RPL_A_BT_TEST_LTCD40_H_
