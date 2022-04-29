#ifndef INC_070__CPP_A_BT_TEST_REC_L11_H_
#define INC_070__CPP_A_BT_TEST_REC_L11_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> candidates, vector<vector<int>> correct) {
  cout << "Candidates: ";
  for (auto i : candidates) cout << i << " ";
  cout << endl;

  auto result = subsetsWithDup(candidates);
  cout << "Result:\n";
  for (auto vec : result) {
    for (int i : vec) cout << i << " ";
    cout << endl;
  }

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << (wrong? "WRONG!" : "Correct.") << endl << endl;
}

void run_tests() {

  // test({}, {{0}});
  test({1,2,2}, {
      {},
      {1},
      {1,2},
      {1,2,2},
      {2},
      {2,2}
  });

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  } else {
    cout << "\nCorrect: ALL results.\n";
  }
}

#endif  // INC_070__CPP_A_BT_TEST_REC_L11_H_
