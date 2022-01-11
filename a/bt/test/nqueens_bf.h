#ifndef RPL_A_BT__TEST_N_QUEENS_BF_H_
#define RPL_A_BT__TEST_N_QUEENS_BF_H_

#include <iostream>
#include <iomanip>

pair<int, int> prototype(int N);
using fptr = decltype(prototype);

// https://oeis.org/A000170
vector<pair<int, int>> _correct_results {{1, 1}, {1, 1}, {0, 6}, {0, 84}, {2, 1820}, {10, 53130}};

void print_board(const int N, const vector<int>& board) {
  cout << "Board " << N << "x" << N << ":\n";
  for (int i=0; i<N*N; i++) {
    if (i!= 0 && i%N == 0) cout << endl;
    bool in_board = false;
    for (auto b: board) if (i == b) { in_board=true; break; }
    if (in_board) cout << " Q ";
    else cout << " . ";
  }
  cout << endl << flush;
}

void print_permutations(const int N, const set<vector<int>>& permutations) {
  for (auto board: permutations) {
    print_board(N, board);
  }
}

void test(fptr function, int N, pair<int,int> correct) {
  cout << N << " Queens. Solutions: " << flush;
  auto solution = function(N);

  cout << setw(3) << solution.first
       << " permutations: " << setw(5) << solution.second
       << (solution != correct ? " (WRONG)": "") << endl << flush;
}


void run_tests(string msg, fptr function) {
  cout << msg << endl;
  for (int i=0; i<_correct_results.size(); i++) test(function, i, _correct_results[i]);
}

#endif  // RPL_A_BT__TEST_N_QUEENS_BF_H_