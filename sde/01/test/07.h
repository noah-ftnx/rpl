#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

void prototype(vector<vector<int>>& matrix);
using fptr = decltype(prototype);

void test(fptr function, vector<vector<int>> vec, vector<vector<int>> correct) {

  auto cpy = vec;
  function(vec);

  for (int i=0; i<vec.size(); i++) {
    auto rowi = cpy[i]; // input
    auto rowr = vec[i]; // result
    for (auto v: rowi) cout << setw(2) << v <<" ";
    cout << "\t";
    for (auto v: rowr) cout << setw(2) << v <<" ";
    cout << endl;
  }

  bool wrong = correct!=vec;
  _wrong|=wrong;

  cout << "Rotation: " << (wrong? " (WRONG)": " correct") << endl << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function,
       {{ 1,  2,  3},
        { 5,  6,  7},
        { 9, 10, 11}},
       {{9,  5, 1},
        {10, 6, 2},
        {11, 7,  3}}
  );


  test(function,
       {{ 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}},
       {{13,  9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16 ,12, 8, 4}}
  );


  cout << endl;
}

#endif  // _H_
