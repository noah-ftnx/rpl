#ifndef _H_
#define _H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

bool _wrong=false;

int prototype(vector<int> &A);
using fptr = decltype(prototype);

string to_s(const vector<int> &vec) {
  string s="{";
  for (int i=0; i<(int) vec.size(); i++) {
    if (i) s+=", ";
    s+=to_string(vec[i]);
  }
  s+="}";
  return s;
}

void test(fptr fun, vector<int> input, int correct) {
  int res=fun(input);
  bool wrong=res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(34) << to_s(input);
  cout << " -> " << setw(2) << res;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg << ":\n";
  test(fun, {}, 0);
  test(fun, {0}, 1);
  test(fun, {1, 2, -3, 3}, 3);
  test(fun, {15, -2, 2, -8, 1, 7, 10, 23}, 5);
  test(fun, {1, 2, 3}, 0);
  test(fun, {1, -1, 3, -3, 4}, 4);
  test(fun, {-1, 1, -1, 1}, 4);
  cout << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]\n";
}

#endif  // _H_
