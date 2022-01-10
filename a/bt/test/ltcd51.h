#ifndef RPL_LTCD_51_H_
#define RPL_LTCD_51_H_

#include <iostream>

bool _dbg_prt_vector=false;
bool _print_board=true;

bool _wrong = false;

vector<vector<int>> prototype(int N);
using fptr = decltype(prototype);

void print_vector(vector<vector<int>> solutions) {
   for (auto solution: solutions) {
     cout << "{ ";
     for  (auto i: solution) cout << i << ", ";
     cout << "},\n";
   }
}


void print_board(const int N, vector<vector<int>> solutions) {
  for (int i=0; i<solutions.size(); i++) {
    auto solution = solutions[i];
    cout << "Solution " << (i+1) << ":" << endl;
    for (int r=0; r<solution.size(); r++) {
      int c = solution[r];
      for (int k=0; k<N; k++) {
        if (k == c) cout << " Q";
        else cout << " .";
      }
      cout << endl;
    }
    cout << endl;
  }
}

void test(fptr function, int N, bool print, vector<vector<int>> correct) {
  auto solutions = function(N);
  cout << N << " Queens. Solutions: " << solutions.size() << endl;

  bool dbg=false;
  if(_dbg_prt_vector) print_vector(solutions);

  if (_print_board) print_board(N, solutions);

  if (correct != solutions) {
    _wrong=true;
    cout << "WRONG.\n";
  }
}


void test1(fptr function, bool print_board) {
  test(function, 4, print_board, {{1,3,0,2}, {2,0,3,1}});
}

void test2(fptr function, bool print_board) {
  test(function, 5, print_board,
       {
           { 0, 2, 4, 1, 3, },
           { 0, 3, 1, 4, 2, },
           { 1, 3, 0, 2, 4, },
           { 1, 4, 2, 0, 3, },
           { 2, 0, 3, 1, 4, },
           { 2, 4, 1, 3, 0, },
           { 3, 0, 2, 4, 1, },
           { 3, 1, 4, 2, 0, },
           { 4, 1, 3, 0, 2, },
           { 4, 2, 0, 3, 1, }
       });
}

void run_tests(string msg, fptr function) {
  cout << msg << endl;

  test1(function, true);
  test2(function, false);

  if (_wrong) {
    cout << "\n\nWrong results found.\n";
  }
}

#endif  // RPL_LTCD_51_H_
