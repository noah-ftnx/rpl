#ifndef INC_070__CPP_A_BT_TEST_REC_L13_H_
#define INC_070__CPP_A_BT_TEST_REC_L13_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> input, vector<vector<int>> correct) {
  cout << "Input: ";
  for (auto i : input) cout << i << " ";
  cout << endl;

  auto result = permute(input);
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

  test({1,2,3}, {
      {1,2,3},
      {1,3,2},
      {2,1,3},
      {2,3,1},
      {3,2,1},
      {3,1,2},
  });

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  } else {
    cout << "\nCorrect: ALL results.\n";
  }
}


#endif  // INC_070__CPP_A_BT_TEST_REC_L13_H_