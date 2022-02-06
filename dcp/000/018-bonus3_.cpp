#define N 9

bool find_empty_loc(int grid[N][N], int& row, int &col) {
  for (row=0; row<N; row++)
    for (col=0; col<N; col++)
      if (grid[row][col]==0) return true;

  return false;
}

bool is_valid(int grid[N][N], int row, int col, int num) {
  auto in_row = [&]() {
    for (int i=0; i<N; i++)
      if (grid[row][i]==num) return true;
    return false;
  };
  auto in_col = [&]() {
   for (int i=0; i<N; i++)
     if (grid[i][col]==num) return true;
   return false;
  };
  auto in_box = [&]() {
    int box_row = row-row%3;
    int box_col = col-col%3;

    for (int i=box_row; i<box_row+3; i++)
      for (int j=box_col; j<box_col+3; j++)
        if (grid[i][j] == num) return true;
    return false;
  };

  return !in_row() && !in_col() && !in_box();
}

bool solve_sudoku(int grid[N][N]) {
  int row{}, col{};
  if(!find_empty_loc(grid, row, col)) { return true; } // SOLVED!

  // check for solutions:
  for (int num=1; num<=N; num++) {
    if (is_valid(grid, row, col, num)) {
      grid[row][col]=num;  // tentatively assign

      if (solve_sudoku(grid)) return true;

      grid[row][col]=0;  // undo assignment
    }
  }

  return false; // backtrack
}



#include "test/018-bonus3.h"
int main() { run_tests(); return 0;}