#include <vector>
using namespace std;

bool solve_sudoku(vector<vector<int>>& grid) {
  const int N = 9;

  auto is_valid = [&](int r, int c, int val) {
    for (int i=0; i<N; i++) {
      if (grid[r][i] == val) return false;
      if (grid[i][c] == val) return false;
    }

    int sr = r - (r % 3);
    int sc = c - (c % 3);
    for (int i=sr; i<sr+3; i++)
      for (int j=sc; j<sc+3; j++)
        if (grid[i][j] == val) return false;

    return true;
  };

  for (int r=0; r<N; r++) {
    for (int c=0; c<N; c++) {
      if (grid[r][c] != 0) continue;

      for (int val=1; val<=9; val++) {
        if (!is_valid(r, c, val)) continue;
        grid[r][c] = val;
        if (solve_sudoku(grid)) return true;
        grid[r][c] = 0;
      }

      return false;
    }
  }

  return true;
}

#include "test/sudoku.h"
int main() { run_tests(); return 0; }
