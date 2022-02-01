#ifndef RPL_DCP_TEST_030_H_
#define RPL_DCP_TEST_030_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void test(vector<int> input, int correct) {
  int result = capacity(input);

  cout << "input:";
  string str;
  for (auto i: input)  str+= " " + to_string(i);
  cout << setw(20) << str << ": capacity: " << setw(2) << result;
  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << (wrong? " WRONG": " correct") << endl;
}

void run_tests() {
  test({}, 0);
  test({1}, 0);
  test({2,1}, 0);
  test({4, 0, 1, 3, 0, 5}, 12);
  test({0, 4, 3, 1, 4}, 4);
  test({5, 0, 1, 3, 0, 5}, 16);

  test({1, 2, 3, 4}, 0);

  test({1,1,1,3,1,2}, 1);
  test({1,1,1,3,1,2,3}, 3);
  test({3, 4, 5, 0, 1, 3, 0, 5}, 16);
  test({3, 4, 5, 0, 1, 3, 4, 5, 0, 5}, 17);
  test({3, 2, 1, 2, 3}, 4);
  test({10, 3, 5, 1, 5}, 6); // BUG BUG TRICKY

  test({4, 3, 2, 1}, 0);  // BUG TRICKY
  test({1, 2, 3, 2, 1}, 0); // BUG TRICKY
  test({4, 3, 2, 1, 2}, 1); // BUG VERY TRICKY

  test({5, 3, 7, 1, 5}, 6); // BUG VERY TRICKY

  // original examples:
  test({2,1,2}, 1);
  test({3, 0, 1, 3, 0, 5}, 8);

  test({4, 3, 0, 5, 1, 3, 0, 5}, 16);

  // test({}, 1);

  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_DCP_TEST_030_H_
