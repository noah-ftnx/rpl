#ifndef _H_
#define _H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

bool _wrong=false;

int prototype(vector<int> &arr, int k);
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

void test(fptr fun, vector<int> input, int k, int correct) {
  int res=fun(input, k);
  bool wrong=res!=correct;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(26) << to_s(input);
  cout << " k=" << setw(2) << k << " -> " << setw(2) << res;
  if (wrong) cout << " (WRONG. Expected: " << correct << ")";
  cout << endl;
}

void run_tests(fptr fun, string msg) {
  cout << msg << ":\n";
  test(fun, {}, 6, 0);
  test(fun, {6}, 6, 1);
  test(fun, {4, 2, 2, 6, 4}, 6, 4);
  test(fun, {5, 6, 7, 8, 9}, 5, 2);
  test(fun, {1, 1, 1}, 0, 2);
  test(fun, {0, 0, 0}, 0, 6);
  test(fun, {3, 3, 3, 3}, 3, 6);
  cout << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]\n";
}

#endif  // _H_
