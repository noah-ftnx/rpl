#ifndef _H_
#define _H_

#include <iostream>
#include <iomanip>

bool _wrong=false;

void prototype(vector<vector<int>>& matrix);
using fptr = decltype(prototype);

void test(fptr function, vector<vector<int>> vec, vector<vector<int>> correct) {
  auto cpy=vec;
  function(vec);
  bool wrong = correct!=vec;
  _wrong|=wrong;

  for (int i=0; i<vec.size(); i++) {
    auto orow=cpy[i];
    for (auto v: orow) cout<< to_string(v) <<" ";

    cout << (i==0? " ->  ":"     ");
    auto crow=vec[i];
    for (auto v: crow) cout<< to_string(v) <<" ";
    cout << endl;
  }

  cout  << "Result: " << setw(3) << (wrong? " (WRONG)": " correct") << endl << endl;
}

void print_report() {
  if (_wrong) cout << "WRONG RESULTS.\n";
  else cout << "Correct: all results.\n";
}


void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";
  test(function,
       {{1,1,1},
        {1,0,1},
        {1,1,1}},
       {{1,0,1},
        {0,0,0},
        {1,0,1}});

  test(function,
       {{0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}},
       {{0,0,0,0},
        {0,4,5,0},
        {0,3,1,0}});

  cout << endl;
}

#endif  // _H_
