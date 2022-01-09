#include <unordered_set>
#include <vector>
using namespace std;

void _nqueens(vector<vector<int>>& solutions, vector<int>& board,
              unordered_set<int> col,
              unordered_set<int> pdiag,
              unordered_set<int> ndiag,
              const int& N,
              int r) {
  if (r == N) {  // reached a solution
    solutions.push_back(board);
    return;
  }

  for (int c=0; c<N; c++) {
    if (col.contains(c) || pdiag.contains(r+c) || ndiag.contains(r-c)) continue;

    // update board and sets:
    col.insert(c);
    pdiag.insert(r+c);
    ndiag.insert(r-c);
    board.push_back(c);

    _nqueens(solutions, board, col, pdiag, ndiag, N, r+1);

    // backtrack
    col.erase(c);
    pdiag.erase(r+c);
    ndiag.erase(r-c);
    board.pop_back();
  }
}

vector<vector<int>> n_queensBT(int N) {
  unordered_set<int> col;
  unordered_set<int> pdiag; // r + c
  unordered_set<int> ndiag; // r - c

  vector<vector<int>> solutions;
  vector<int> board;

  _nqueens(solutions, board, col, pdiag, ndiag, N, 0);
  return solutions;
}

#include "test/018-bonus.h"
int main() { run_tests(); return 0; }