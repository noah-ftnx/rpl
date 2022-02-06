#ifndef RPL_DCP_051_TEST_054_H_
#define RPL_DCP_051_TEST_054_H_

#include <iostream>
using namespace std;

const int N=9;

void print_grid(const vector<vector<int>>& grid) {
  for (int i=0; i<N; i++) {
    if(i%3==0) cout << "-------------------------\n";
    for (int j=0; j<N; j++) {
      if(j%3==0) cout << "| ";
      cout << grid[i][j] << " ";
    }
    cout << "|" << endl;
  }
  cout << "-------------------------\n";
}

void run_tests() {
  // 0 means unassigned cells
  vector<vector<int>> grid {
      {3, 0, 6, 5, 0, 8, 4, 0, 0},
      {5, 2, 0, 0, 0, 0, 0, 0, 0},
      {0, 8, 7, 0, 0, 0, 0, 3, 1},
      {0, 0, 3, 0, 1, 0, 0, 8, 0},
      {9, 0, 0, 8, 6, 3, 0, 0, 5},
      {0, 5, 0, 0, 9, 0, 6, 0, 0},
      {1, 3, 0, 0, 0, 0, 2, 5, 0},
      {0, 0, 0, 0, 0, 0, 0, 7, 4},
      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

  vector<vector<int>> correct {
      {3, 1, 6, 5, 7, 8, 4, 9, 2 },
      {5, 2, 9, 1, 3, 4, 7, 6, 8 },
      {4, 8, 7, 6, 2, 9, 5, 3, 1 },
      {2, 6, 3, 4, 1, 5, 9, 8, 7 },
      {9, 7, 4, 8, 6, 3, 1, 2, 5 },
      {8, 5, 1, 7, 9, 2, 6, 4, 3 },
      {1, 3, 8, 9, 4, 7, 2, 5, 6 },
      {6, 9, 2, 3, 5, 1, 8, 7, 4 },
      {7, 4, 5, 2, 8, 6, 3, 1, 9 }
  };

  if (solve_sudoku(grid) == true) {
    print_grid(grid);
    bool verified = true;
    for (int i=0; verified && i<N; i++)
      for (int j=0; verified && j<N; j++) verified = (grid[i][j]==correct[i][j]);
    if (!verified) cout << "\nWRONG RESULT\n";
    else cout << "\nCorrect.\n";
  }
  else
    cout << "No solution exists\n";
}

#endif  // RPL_DCP_051_TEST_054_H_
