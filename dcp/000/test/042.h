#ifndef RPL_DCP_TEST_042_H_
#define RPL_DCP_TEST_042_H_

#include <iostream>
#include <iomanip>

bool _wrong = false;

void test(vector<int> candidates, int target, vector<int> correct) {

  cout << "Target:" << setw(3) << target << ". Input: ";
  for (auto i: candidates) cout << i << " ";
  cout << "Result: ";

  auto result = find_subset(candidates, target);

  for (int i: result) cout << i << " ";

  bool wrong = result!=correct;
  _wrong|=wrong;

  cout << (wrong? " (WRONG)" : "") << endl ;
}

void run_tests() {
  test({12, 1, 61, 5, 9, 2}, 24, {12, 9, 2, 1});
  // test({2,3,6,7}, 7,  {7});
  // test({4,3,3,4,5,2}, 6,  {4,2});
  // test({2}, 1, {});
  // test({}, 0, {});

  cout << endl << (_wrong? "WRONG RESULTS.": "Correct results.") << endl;
}

#endif  // RPL_DCP_TEST_042_H_
