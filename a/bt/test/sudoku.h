#ifndef RPL_A_BT_TEST_SUDOKU_H_
#define RPL_A_BT_TEST_SUDOKU_H_

#include <iostream>
#include <vector>
using namespace std;

bool valid_solution(const vector<vector<int>>& grid) {
  const int N = 9;
  for (int i=0; i<N; i++) {
    vector<int> row(N + 1), col(N + 1);
    for (int j=0; j<N; j++) {
      int r = grid[i][j];
      int c = grid[j][i];
      if (r < 1 || r > 9 || c < 1 || c > 9) return false;
      if (row[r]++ || col[c]++) return false;
    }
  }

  for (int sr=0; sr<N; sr+=3) {
    for (int sc=0; sc<N; sc+=3) {
      vector<int> seen(N + 1);
      for (int i=sr; i<sr+3; i++)
        for (int j=sc; j<sc+3; j++)
          if (seen[grid[i][j]]++) return false;
    }
  }

  return true;
}

bool givens_preserved(const vector<vector<int>>& before,
                      const vector<vector<int>>& after) {
  for (int i=0; i<9; i++)
    for (int j=0; j<9; j++)
      if (before[i][j] != 0 && before[i][j] != after[i][j])
        return false;
  return true;
}

void test(string name, vector<vector<int>> grid, bool expected) {
  vector<vector<int>> before = grid;
  bool result = solve_sudoku(grid);
  bool ok = result == expected;
  if (result)
    ok = ok && valid_solution(grid) && givens_preserved(before, grid);

  cout << (ok ? "[PASS] " : "[FAIL] ");
  cout << name << ": Result: " << result << " Expected: " << expected << "\n";
}

void run_tests() {
  test("classic puzzle",
      {{3, 0, 6, 5, 0, 8, 4, 0, 0},
       {5, 2, 0, 0, 0, 0, 0, 0, 0},
       {0, 8, 7, 0, 0, 0, 0, 3, 1},
       {0, 0, 3, 0, 1, 0, 0, 8, 0},
       {9, 0, 0, 8, 6, 3, 0, 0, 5},
       {0, 5, 0, 0, 9, 0, 6, 0, 0},
       {1, 3, 0, 0, 0, 0, 2, 5, 0},
       {0, 0, 0, 0, 0, 0, 0, 7, 4},
       {0, 0, 5, 2, 0, 6, 3, 0, 0}},
      true);

  test("one empty cell",
      {{5, 3, 4, 6, 7, 8, 9, 1, 2},
       {6, 7, 2, 1, 9, 5, 3, 4, 8},
       {1, 9, 8, 3, 4, 2, 5, 6, 7},
       {8, 5, 9, 7, 6, 1, 4, 2, 3},
       {4, 2, 6, 8, 5, 3, 7, 9, 1},
       {7, 1, 3, 9, 2, 4, 8, 5, 6},
       {9, 6, 1, 5, 3, 7, 2, 8, 4},
       {2, 8, 7, 4, 1, 9, 6, 3, 5},
       {3, 4, 5, 2, 8, 6, 1, 7, 0}},
      true);

  test("already solved",
      {{5, 3, 4, 6, 7, 8, 9, 1, 2},
       {6, 7, 2, 1, 9, 5, 3, 4, 8},
       {1, 9, 8, 3, 4, 2, 5, 6, 7},
       {8, 5, 9, 7, 6, 1, 4, 2, 3},
       {4, 2, 6, 8, 5, 3, 7, 9, 1},
       {7, 1, 3, 9, 2, 4, 8, 5, 6},
       {9, 6, 1, 5, 3, 7, 2, 8, 4},
       {2, 8, 7, 4, 1, 9, 6, 3, 5},
       {3, 4, 5, 2, 8, 6, 1, 7, 9}},
      true);

  test("blocked empty cell",
      {{1, 2, 3, 4, 5, 6, 7, 8, 0},
       {4, 5, 6, 7, 8, 9, 1, 2, 3},
       {7, 8, 9, 1, 2, 3, 4, 5, 6},
       {2, 3, 4, 5, 6, 7, 8, 9, 1},
       {5, 6, 7, 8, 9, 1, 2, 3, 4},
       {8, 9, 1, 2, 3, 4, 5, 6, 7},
       {3, 4, 5, 6, 7, 8, 9, 1, 2},
       {6, 7, 8, 9, 1, 2, 3, 4, 5},
       {9, 1, 2, 3, 4, 5, 6, 7, 9}},
      false);

  test("invalid start: duplicate row",
      {{5, 5, 0, 0, 7, 0, 0, 0, 0},
       {6, 0, 0, 1, 9, 5, 0, 0, 0},
       {0, 9, 8, 0, 0, 0, 0, 6, 0},
       {8, 0, 0, 0, 6, 0, 0, 0, 3},
       {4, 0, 0, 8, 0, 3, 0, 0, 1},
       {7, 0, 0, 0, 2, 0, 0, 0, 6},
       {0, 6, 0, 0, 0, 0, 2, 8, 0},
       {0, 0, 0, 4, 1, 9, 0, 0, 5},
       {0, 0, 0, 0, 8, 0, 0, 7, 9}},
      false);

  test("invalid start: duplicate column",
      {{5, 3, 0, 0, 7, 0, 0, 0, 0},
       {5, 0, 0, 1, 9, 5, 0, 0, 0},
       {0, 9, 8, 0, 0, 0, 0, 6, 0},
       {8, 0, 0, 0, 6, 0, 0, 0, 3},
       {4, 0, 0, 8, 0, 3, 0, 0, 1},
       {7, 0, 0, 0, 2, 0, 0, 0, 6},
       {0, 6, 0, 0, 0, 0, 2, 8, 0},
       {0, 0, 0, 4, 1, 9, 0, 0, 5},
       {0, 0, 0, 0, 8, 0, 0, 7, 9}},
      false);

  test("invalid start: duplicate box",
      {{5, 3, 0, 0, 7, 0, 0, 0, 0},
       {6, 5, 0, 1, 9, 0, 0, 0, 0},
       {0, 9, 8, 0, 0, 0, 0, 6, 0},
       {8, 0, 0, 0, 6, 0, 0, 0, 3},
       {4, 0, 0, 8, 0, 3, 0, 0, 1},
       {7, 0, 0, 0, 2, 0, 0, 0, 6},
       {0, 6, 0, 0, 0, 0, 2, 8, 0},
       {0, 0, 0, 4, 1, 9, 0, 0, 5},
       {0, 0, 0, 0, 8, 0, 0, 7, 9}},
      false);

  test("fully filled but invalid",
      {{5, 3, 4, 6, 7, 8, 9, 1, 2},
       {6, 7, 2, 1, 9, 5, 3, 4, 8},
       {1, 9, 8, 3, 4, 2, 5, 6, 7},
       {8, 5, 9, 7, 6, 1, 4, 2, 3},
       {4, 2, 6, 8, 5, 3, 7, 9, 1},
       {7, 1, 3, 9, 2, 4, 8, 5, 6},
       {9, 6, 1, 5, 3, 7, 2, 8, 4},
       {2, 8, 7, 4, 1, 9, 6, 3, 5},
       {3, 4, 5, 2, 8, 6, 1, 7, 7}},
      false);
}

#endif  // RPL_A_BT_TEST_SUDOKU_H_
