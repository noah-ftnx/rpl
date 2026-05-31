#ifndef _H_
#define _H_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

bool _wrong=false;

vector<vector<int>> prototype(vector<int>& nums, int target);
using fptr = decltype(prototype);

string to_s(const vector<vector<int>> &vec) {
  string s="{";
  for (int i=0; i<(int) vec.size(); i++) {
    if (i) s+=", ";
    s+="{";
    for (int j=0; j<(int) vec[i].size(); j++) {
      if (j) s+=", ";
      s+=to_string(vec[i][j]);
    }
    s+="}";
  }
  s+="}";
  return s;
}

string to_s(const vector<int> &vec) {
  string s="{";
  for (int i=0; i<(int) vec.size(); i++) {
    if (i) s+=", ";
    s+=to_string(vec[i]);
  }
  s+="}";
  return s;
}

vector<vector<int>> norm(vector<vector<int>> v) {
  for (auto &q: v) sort(q.begin(), q.end());
  sort(v.begin(), v.end());
  return v;
}

void test(fptr fun, vector<int> input, int target, vector<vector<int>> correct) {
  auto res = norm(fun(input, target));
  correct = norm(correct);
  bool wrong=res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(24) << to_s(input);
  cout << " t=" << setw(3) << target;
  cout << " -> " << setw(24) << to_s(res);
  if (wrong) cout << " (WRONG. Expected: " << to_s(correct) << ")";
  cout << endl;
}

void run_tests(string msg, fptr fun) {
  cout << msg << ":\n";
  test(fun, {1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}});
  test(fun, {2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});
  test(fun, {-3, -1, 0, 2, 4, 5}, 2, {{-3, -1, 2, 4}});
  test(fun, {0, 0, 0, 0}, 0, {{0, 0, 0, 0}});
  cout << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]\n";
}

#endif  // _H_
