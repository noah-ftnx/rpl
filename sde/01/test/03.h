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
  cout << setw(10) << s << " -> ";

  function(vec);
  bool wrong = correct!=vec;
  _wrong|=wrong;

  s.clear();
  for (auto v: vec) s+=to_string(v) + " ";
  cout << setw(10) << s;

  cout  << ": " << setw(5) << (wrong? " (WRONG)": " correct") << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {}, {});
  test(function, {1}, {1});
  test(function, {2,3,1}, {3,1,2});
  test(function, {1,4,2,3}, {1,4,3,2});

  test(function, {2,3,4,1}, {2,4,1,3});
  test(function, {5,4,3,2,1}, {1,2,3,4,5});

  cout << endl;
}

#endif  // _H_
