#ifndef RPL_DCP_051_TEST_058_H_
#define RPL_DCP_051_TEST_058_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void test(vector<int> input, int num, int correct) {
  int result = find_index(input, num);
  bool wrong = (result != correct);
  _wrong|=wrong;
  cout << "index: " << result <<
      (wrong? " (WRONG)": "") << endl;

}

void run_tests() {
  test({13, 18, 25, 2, 8, 10}, 8, 4);
  test({10, 13, 18, 25, 2, 8}, 8, 5); // BUGFIX
  test({8, 10, 13, 18, 25, 2}, 8, 0);
  test({2, 8, 10, 13, 18, 25}, 8, 1);
  test({25, 2, 8, 10, 13, 18}, 8, 2);
  test({18, 25, 2, 8, 10, 13}, 8, 3); // BUGFIX

  test({1, 2}, 3, -1);
  test({1, 2}, 1, 0);
  test({1, 2}, 2, 1);
  test({2, 1}, 1, 1);
  test({2, 1}, 2, 0);
  test({}, 2, -1);
  test({1}, 2, -1);
  test({1}, 1, 0);

  cout << endl << (_wrong? "WRONG RESULTS.":"Correct results.") << endl;
}

#endif  // RPL_DCP_051_TEST_058_H_
