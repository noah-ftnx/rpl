#ifndef __H__
#define __H__

#include <string>
#include <iostream>
#include <iomanip>

int prototype(vector<int>& nums);
using fptr = decltype(prototype);

bool _wrong{};
void test(fptr function, vector<int> vec, int correct) {
  auto result = function(vec);

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

  test(function, {3,1,5,8}, 167);
  test(function, {1,5}, 10);
  test(function, {5,2,3,4}, 115);

  cout << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}



#endif  // __H__