#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int>& arr, int n);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, int correct) {
  auto result = function(vec, vec.size());

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (auto v: vec) s += to_string(v) + " ";
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(25) << (s.empty()?"{}":s) << " ";

  cout << "\tLIS: "  << setw(15) << result << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 0);
  test(function, {1, 2, 9, 4, 2, 5, 3, 1, 50}, 6);  // 1 2 4 5 3 1

  test(function, {1, 11, 2, 10, 4, 5, 2, 1}, 6);


  cout << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]: all results.\n";
}

#endif  // __H__