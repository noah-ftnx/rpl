#include <vector>
using namespace std;

bool solve_sudoku(vector<vector<int>>& grid) {
  const int N = static_cast<int>(grid.size());
  struct Pos { int x, y; };

  auto next_empty_pos = [&](Pos& p) -> bool {
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        if (grid[i][j]==0) {
          p.x=i; p.y=j;
          return true;
        }
      }
    }
    return false;
  };

  auto is_valid = [&](Pos p, int value)->bool {
    // not in row
    for (int i=0; i<N; i++)
      if (grid[p.x][i]==value) return false;

    // not in col
    for (int i=0; i<N; i++)
      if (grid[i][p.y]==value) return false;

    // not in box
    int bx=p.x-(p.x%3);
    int by=p.y-(p.y%3);
    for (int i=bx; i<bx+3; i++)
      for (int j=by; j<by+3; j++)
        if (grid[i][j]==value) return false;

    return true;
  };

  Pos p;
  if (!next_empty_pos(p)) return true; // SOLVED

  for (int i=1; i<=9; i++) {
    if (is_valid(p, i)) {
      grid[p.x][p.y]=i; // tentatively assign

      if (solve_sudoku(grid)) return true;

      grid[p.x][p.y]=0; // undo REVIEW:HL
    }
  }

  return false;  // backtrack REVIEW:HL
}



#include "test/054.h"
int main() { run_tests(); return 0; }