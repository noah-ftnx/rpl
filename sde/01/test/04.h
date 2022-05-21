#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

int prototype(vector<int>& nums);
using fptr = decltype(prototype);

void test(fptr function, vector<int> vec, int correct) {
  string s;
  int res=function(vec);
  bool wrong = correct!=res;
  _wrong|=wrong;

  for (auto v: vec) s+=to_string(v) + " ";
  cout << setw(40) << s;

  cout  << ": " << setw(5) << (res==INT_MIN? "<nan>":to_string(res)) << setw(5) << (wrong? " (WRONG)": " correct") << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {}, -1);
  test(function, {-2, 3, -1, 10, -1, 3}, 14);
  test(function, {-12, -11}, -11);
  test(function, {-12, 10}, 10);
  test(function, {-2, -3, 4, -1, -2, 1, 5, -3}, 7);

  cout << endl;
}

#endif  // _H_
