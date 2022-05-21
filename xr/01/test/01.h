#ifndef _H_
#define _H_

#include <iostream>
#include <sstream>
#include <iomanip>

bool _wrong=false;

vector<int> prototype(vector<int> array, int targetSum);
using fptr = decltype(prototype);

void test(fptr function, vector<int> vec, int k, vector<int> correct) {
  auto res = function(vec, k);
  bool wrong = correct!=res;
  _wrong|=wrong;

  stringstream ss;
  for (auto v: vec) ss << setw(2) << v << " ";
  cout << setw(30) << ss.str();

  ss.str("");
  for (auto v: res) ss << setw(2) << v <<  " ";
  cout << "| " << setw(10) << ss.str();

  cout  << ": " << setw(5) << (wrong? " (WRONG)": " correct") << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {3, 5, -4, 8, 11, 1, -1, 6}, 10, {});
  test(function, {4, 6, 1, -3}, 3, {});
  test(function, {3, 5, -4, 8, 11, 1, -1, 6}, 15, {});

  cout << endl;
}

#endif  // _H_
