#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int> &num, int x);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> num, int x, int correct) {
  auto result = function(num, x);

  bool wrong = result != correct;
  _wrong|=wrong;
  string s;
  for (auto n: num) s += to_string(n) + " ";
  cout << setw(25) << (s.empty()?"{}":s) << " ";

  cout << "\tCost: " << setw(15) << result << " " << setw(10) << (wrong? "(WRONG)":"Correct") << endl;
}

void run_tests(string msg, fptr function) {
  cout << msg << ":\n";

  test(function, {}, 3, 0);
  test(function, {10}, 0, INT_MIN);
  test(function, {10}, 1, 10);
  test(function, {10}, 10, 10);
  test(function, {1,15,7,9,2,5,10}, 1, 49);
  test(function, {1,15,7,9,2,5,10}, 2, 75);
  test(function, {1,15,7,9,2,5,10}, 3, 84);
  test(function, {1,15,7,9,2,5,10}, 7, 105);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}



#endif  // __H__