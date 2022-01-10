#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

// rows are guaranteed to be different
// check for columns and diagonals
bool is_valid(const vector<int>& board) {
  int queen_row = board.size()-1;
  int queen_col = board.back();

  for (int i=0; i<board.size()-1; i++) { // all prev queens
    int row = i;
    int col = board[row];
    int col_diff= abs(queen_col-col);
    if (col_diff == 0 // is in same column
                       // check for diagonals
        || col_diff == abs(queen_row - row)) {
      return false;
    }
  }

  return true;
}

void _n_queensBT(const int N,
                 vector<int>& board,
                 vector<vector<int>>& solutions) {
  if (N == board.size()) {
    solutions.push_back(board);
  }

  for (int col=0; col<N; col++) { // check columns
    board.push_back(col);
    if (is_valid(board)) {
      _n_queensBT(N, board, solutions);
    }
    board.pop_back();
  }
}

vector<vector<int>> n_queensBT(int N) {
  vector<vector<int>> solutions;
  vector<int> board;
  _n_queensBT(N, board, solutions);

  return solutions;
}



#include "test/018-bonus.h"
int main() {
  run_tests("BF", n_queensBT);
  // run_tests("BT", count_td);
  return 0;
}