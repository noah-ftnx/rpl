#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

vector<vector<int>> prototype(int numRows);
using fptr = decltype(prototype);

void test(fptr function, int n, vector<vector<int>> correct) {
  auto res = function(n);
  bool wrong = correct!=res;
  _wrong|=wrong;

  for (auto row: res) {
    for (auto v: row) cout<< to_string(v) <<" ";
    cout << endl;
  }

  cout  << "Input: " << n << setw(5) << (wrong? " (WRONG)": " correct") << endl << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";


  test(function, -3, {});
  test(function, 0, {});

  test(function, 1, {{1}});

  test(function, 2,
       {{1},
        {1, 1}});

  test(function, 3,
       {{1},
        {1, 1},
        {1, 2, 1}});

  test(function, 4,
       {{1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1}});

  test(function, 5,
       {{1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}});

  cout << endl;
}

#endif  // _H_
