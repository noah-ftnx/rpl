#ifndef RPL_SDE_11_TEST_04_H_
#define RPL_SDE_11_TEST_04_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

void check(string name, vector<int> nums, int target, int correct) {
  int got = search(nums, target);
  bool wrong = got != correct;
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name;
  if (wrong) cout << " (expected " << correct << ", got " << got << ")";
  cout << endl;
}

void run_tests(string msg, int (*)(vector<int>&, int)) {
  cout << msg << ":\n";
  check("rotated_hit", {4, 5, 6, 7, 0, 1, 2}, 0, 4);
  check("rotated_miss", {4, 5, 6, 7, 0, 1, 2}, 3, -1);
  check("single", {1}, 0, -1);
  check("tiny", {1, 3}, 3, 1);
  cout << endl;
}

#endif  // RPL_SDE_11_TEST_04_H_
