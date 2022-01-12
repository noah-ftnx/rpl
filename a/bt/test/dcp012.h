#ifndef RPL_DCP_BT_TEST_012_H_
#define RPL_DCP_BT_TEST_012_H_

#include <iostream>

bool _wrong = false;

void test(int n, vector<int> steps, vector<vector<int>> correct) {
  auto res = enumerate_ways(n, steps);
  cout << "stairs: " << n << " steps: ";
  for (int step: steps) cout << step << " ";
  cout << ":\n";

  for (auto way: res) {
    cout << "{ ";
    for (auto step: way) cout << step << ", ";
    cout << "},"<< endl;
  }

  bool wrong = correct != res;
  _wrong|=wrong;

  cout << (wrong? "WRONG!":"Correct.") << endl << endl;

  // << ssteps << ": ways: " <<  res << (wrong? " (WRONG)":"") << endl;
}

void run_tests() {

  test(4, {1,2,4},
       {{ 1, 1, 1, 1 },
        { 1, 1, 2 },
        { 2, 2 },
        { 4 } });

  test(4, {1,2},
       {{ 1, 1, 1, 1, },
       { 1, 1, 2, },
       { 2, 2, }});

  test(0, {1,2}, {{}});
  test(1, {1,2}, {{1}});
  test(2, {1,2}, {{1,1}, {2}});
  test(3, {1,2}, {{1,1,1}, {1,2}});
  test(3, {1,3}, {{1,1,1}, {3}});
  test(3, {1,2,3}, {{1,1,1}, {1,2}, {3}});
  test(4, {2,4}, {{2,2}, {4}});

  if (_wrong) cout << "\nWRONG RESULTS\n";
  cout << endl;
}

#endif  // RPL_DCP_BT_TEST_012_H_
