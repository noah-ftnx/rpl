#ifndef INC_070__CPP_A_BT_TEST_REC_L01_01_H_
#define INC_070__CPP_A_BT_TEST_REC_L01_01_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> candidates, int k, vector<vector<int>> correct) {
  cout << "K: " << k << " Set: ";
  for (auto i : candidates) cout << i << " ";
  cout << endl;

  auto result = any_subsequence(candidates, k);
  cout << "Result:\n";
  bool wrong = true; // assumption
  for (auto any: correct) {
    if (any==result) {
      for (int i: any) cout << i << " ";
      cout << endl;
      wrong=false;
      break;
    }
  }

  _wrong|=wrong;

  cout << (wrong? "WRONG!" : "Correct.") << endl << endl;
}

void run_tests() {

  test({1,2,2, 3, 4}, 4, {
                      {1, 3},
                      {2,2},
                      {4},
                  });

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  } else {
    cout << "\nCorrect: ALL results.\n";
  }
}

#endif  // INC_070__CPP_A_BT_TEST_REC_L01_01_H_