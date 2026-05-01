#ifndef INC_070__CPP_A_BT_TEST_REC_L01_01_H_
#define INC_070__CPP_A_BT_TEST_REC_L01_01_H_

#include <iostream>

bool _wrong = false;

void test(vector<int> candidates, int k, vector<vector<int>> correct) {
  cout << "K: " << k << " Set: ";
  for (auto i : candidates) cout << i << " ";
  cout << endl;

  auto result = enumerate_subsequences(candidates, k);
  cout << "Result:\n";
  for (auto vec : result) {
    for (int i : vec) cout << i << " ";
    cout << endl;
  }

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << (wrong? "[FAIL]" : "[PASS]") << endl << endl;
}

void run_tests() {

  test({1,2,2, 3, 4}, 4, {
                      {1, 3},
                      {2,2},
                      {4},
                  });

  if (_wrong) {
    cout << "\n[FAIL]\n";
  } else {
    cout << "\n[PASS]: ALL results.\n";
  }
}

#endif  // INC_070__CPP_A_BT_TEST_REC_L01_01_H_