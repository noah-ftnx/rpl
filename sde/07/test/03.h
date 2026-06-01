#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"

vector<vector<int>> prototype(vector<int>& nums);
using fptr = decltype(prototype);

vector<vector<int>> norm(vector<vector<int>> v) {
  for (auto &q: v) sort(q.begin(), q.end());
  sort(v.begin(), v.end());
  return v;
}

void test(fptr fun, vector<int> input, vector<vector<int>> correct) {
  auto res = norm(fun(input));
  correct = norm(correct);
  bool wrong = res != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << to_string(input);
  cout << " -> " << to_string(res);
  if (wrong) cout << " (WRONG. Expected: " << to_string(correct) << ")";
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg << ":\n";
  test(fun, {-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
  test(fun, {0, 1, 1}, {});
  test(fun, {0, 0, 0}, {{0, 0, 0}});
  test(fun, {0, 0, 0, 0}, {{0, 0, 0}});
  test(fun, {-1, -1, 0, 1, 1}, {{-1, 0, 1}});
  test(fun, {-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}});
  cout << endl;
}

#endif  // _H_
