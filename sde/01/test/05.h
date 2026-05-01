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
  function(vec);
  bool wrong = correct!=vec;
  _wrong|=wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << setw(20) << s << "   | Res: ";

  s="";
  for (auto v: vec) s+=to_string(v) + " ";
  cout << setw(20) << s;

  cout << ": "  << endl;
}

void print_report() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS]: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {1, 2, 0, 0, 0, 1, 2, 1, 1}, {0, 0, 0, 1, 1, 1, 1, 2, 2});

  cout << endl;
}

#endif  // _H_
