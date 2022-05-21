#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

int prototype(vector<int>& prices);
using fptr = decltype(prototype);

void test(fptr function, vector<int> vec, int correct) {
  string s;

  for (auto v: vec) s+=to_string(v) + " ";
  cout << setw(20) << s << "   | Res: ";

  int res = function(vec);
  bool wrong = correct!=res;
  _wrong|=wrong;

  cout  << ": Profit: " << setw(3) << res << setw(5) << (wrong? " (WRONG)": " correct") << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {1, 2, 0, 0, 0, 1, 2, 1, 1}, 2);
  test(function, {7,1,5,3,6,4}, 5);
  test(function, {7,6,4,3,1}, 0);
  test(function, {4,2,1,3,2,5}, 4);

  cout << endl;
}

#endif  // _H_
