#ifndef INC_070__CPP_A_BT_TEST_REC_L01_03_H_
#define INC_070__CPP_A_BT_TEST_REC_L01_03_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> candidates, int k, int correct) {
  cout << "K: " << k << " Set: ";
  for (auto i : candidates) cout << i << " ";
  cout << endl;

  auto result = count_subsequences(candidates, k);
  bool wrong = result != correct;
  _wrong|=wrong;

  cout << "Result: " << result << " ";
  cout << (wrong? "WRONG!" : "Correct.") << endl << endl;
}

void run_tests() {

  test({1,2,1,4}, 2, 2);
  test({1,2,2,3,4}, 4, 3);

  if (_wrong) {
    cout << "WRONG RESULTS.\n";
  } else {
    cout << "Correct: ALL results.\n";
  }
}

#endif  // INC_070__CPP_A_BT_TEST_REC_L01_03_H_