#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

void prototype(vector<int>& nums);
using fptr = decltype(prototype);

void test(fptr function, vector<int> vec, vector<int> correct) {
  string s;

  for (auto v: vec) s+=to_string(v) + " ";
  cout << setw(20) << s << "   | Res: ";

  function(vec);
  bool wrong = correct!=vec;
  _wrong|=wrong;

  s="";
  for (auto v: vec) s+=to_string(v) + " ";
  cout << setw(20) << s;

  cout  << ": " << setw(5) << (wrong? " (WRONG)": " correct") << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {1, 2, 0, 0, 0, 1, 2, 1, 1}, {0, 0, 0, 1, 1, 1, 1, 2, 2});

  cout << endl;
}

#endif  // _H_
