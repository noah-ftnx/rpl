#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(int n, int c, vector<int> &cuts);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, int n, int correct) {
  auto result = function(n, vec.size(), vec);

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (auto v: vec) s += to_string(v) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";

  cout << "\tCost: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  // test(function, {}, 0, -1);

  test(function, {1, 3}, 4, 7);
  test(function, {1, 3, 4}, 5, 10);
  test(function, {1,3,4,5}, 7, 16);
  // test(function, {10}, -1);
  // test(function, {10, 20}, 0);
  // test(function, {1, 4, 3, 2}, 18);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}



#endif  // __H__