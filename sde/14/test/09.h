#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

int prototype(vector<int>& heights);
using fptr = decltype(prototype);

void test(fptr function, vector<int> vec, int correct) {
  int result = function(vec);
  bool wrong = result!=correct;
  _wrong|=wrong;
  string s;
  for (auto v: vec) s+= to_string(v) + " ";
  cout << setw(15) << s << " Max Area: " << setw(3) << result << (wrong? " (WRONG)": "") << endl;
}

void print_report() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";
  test(function, {2, 4, 5, 1, 5}, 8);
  test(function, {2, 4, 2, 1, 5}, 6);
  test(function, {2,1,5,6,2,3}, 10);
  test(function, {2,4}, 4);
  test(function, {2,1,1,2,1}, 5);
  cout << endl;
}

#endif  // _H_
