#ifndef RPL_DCP_000_TEST_047_H_
#define RPL_DCP_000_TEST_047_H_

#include <iostream>
#include <iomanip>

bool _wrong {};

void test(vector<int> input, int correct) {
  int result = max_profit(input);

  for (auto i: input) cout << " " << i;
  cout << ": " << result
       << (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test({9, 11, 8, 5, 7, 10}, 5);
  test({}, 0);
  test({10}, 0);
  test({10, 11}, 1);
  test({11, 10}, 0);
  test({11, 10, 9, 8, 10}, 2);
  test({9, 11, 8, 5, 4, 7, 10}, 6);
}


#endif  // RPL_DCP_000_TEST_047_H_
