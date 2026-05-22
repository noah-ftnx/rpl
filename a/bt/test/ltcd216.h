#ifndef RPL_A_BT_TEST_LTCD216_H_
#define RPL_A_BT_TEST_LTCD216_H_

#include <iostream>
#include <vector>
using namespace std;

bool _wrong = false;

void print(vector<vector<int>> result) {
  for (auto combination: result) {
    for (int i: combination) cout << i << " ";
    cout << endl;
  }
}

void test(int k, int n, vector<vector<int>> correct) {
  cout << "k: " << k << " n: " << n << endl;

  auto result = combinationSum3(k, n);
  print(result);

  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ") << endl << endl;
}

void run_tests() {
  test(3, 7, {{1,2,4}});
  test(3, 9, {{1,2,6}, {1,3,5}, {2,3,4}});
  test(4, 1, {});
  test(3, 2, {});
  test(9, 45, {{1,2,3,4,5,6,7,8,9}});
  test(2, 17, {{8,9}});
  test(2, 18, {});
  test(1, 9, {{9}});

  if (_wrong) {
    cout << "[FAIL]\n";
  } else {
    cout << "[PASS]: ALL results.\n";
  }
}

#endif  // RPL_A_BT_TEST_LTCD216_H_
