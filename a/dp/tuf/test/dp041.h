#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int>& nums);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, int correct) {
  int result = function(vec);
  bool wrong = result !=correct;
  _wrong|=wrong;
  string s;
  for (int p: vec) s += to_string(p) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";
  cout << "\tLIS: " << setw(3) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 0);
  test(function, {10}, 1);
  test(function, {8, 8, 8}, 1);
  test(function, {7, 1, 5, 3, 6, 4}, 3);
  test(function, {7, 1, 5, 3, 6, 4, 5}, 4);
  test(function, {1, 10, 11, 4, 2, 3, 5, 5, 6, 7, 5}, 6);
  test(function, {10, 9, 2, 5, 3, 7, 101, 18}, 4);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}

#endif  // __H__