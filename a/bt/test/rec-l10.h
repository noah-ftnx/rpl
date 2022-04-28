#ifndef INC_070__CPP_A_BT_TEST_REC_L10_H_
#define INC_070__CPP_A_BT_TEST_REC_L10_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> candidates, vector<int> correct) {

  cout << "Candidates: ";
  for (auto i: candidates) cout << i << " "; cout << endl;

  auto result = subsetSums(candidates);
  cout << "Result: ";
  for (int i: result) cout << i << " "; cout << endl;

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << (wrong? "WRONG!" : "Correct.") << endl << endl;
}

void run_tests() {

  test({}, {0});
  test({0}, {0, 0});
  test({1,2}, {0, 1, 2, 3});
  test({1}, {0, 1});
  test({1,2,3}, {0, 1, 2, 3, 3, 4, 5, 6});

  if (_wrong) {
    cout << "\nWRONG RESULTS.\n";
  } else {
    cout << "\nCorrect: ALL results.\n";
  }
}

#endif  // INC_070__CPP_A_BT_TEST_REC_L10_H_
