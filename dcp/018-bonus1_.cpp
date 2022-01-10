#include <vector>
using namespace std;

bool is_valid(const vector<int>& board) {
  // last queen
  int queen_row=board.size()-1;
  int queen_col=board[queen_row];

  // check if attacked by other queens
  for (int i=0; i<board.size()-1; i++) {
    int row=i;
    int col=board[row];

    int diff_col = abs(queen_col-col);
    if (diff_col==0 || diff_col == queen_row-row) return false;
  }

  return true;
}

int _n_queensBT(int N, vector<int>& board) {
  if (board.size()==N) {
    return 1; // found solution
  }
  int count = 0;

  for (int col=0; col<N; col++) {
    board.push_back(col); // try a solution

    if (is_valid(board)) {
      count+=_n_queensBT(N, board);
    }

    board.pop_back(); // backtrack
  }

  return count;
}

int n_queensBT(int N) {
  vector<int> board;
  return _n_queensBT(N, board);
}

#include <unordered_set>
int _n_queensST(const int& N, vector<int>& board,
                unordered_set<int>& cols,
                unordered_set<int>& ndiag,
                unordered_set<int>& pdiag) {
  if (N == board.size()) return 1;

  int row = board.size()-1;
  int count = 0;
  for (int col=0; col<N; col++) {
    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2
    if (cols.contains(col) || ndiag.contains(row-col) || pdiag.contains(row+col)) continue;

    cols.insert(col);
    ndiag.insert(row-col);
    pdiag.insert(row+col);
    board.push_back(col);

    count+=_n_queensST(N, board, cols, ndiag, pdiag);

    // backtrack
    cols.erase(col);
    ndiag.erase(row-col);
    pdiag.erase(row+col);
    board.pop_back();
  }

  return count;
}

// solution with sets
int n_queensST(int N) {
  vector<int> board;
  unordered_set<int> cols;
  unordered_set<int> ndiag;
  unordered_set<int> pdiag;
  return _n_queensST(N, board, cols, ndiag, pdiag);
}

#include "test/018-bonus1.h"
int main() {
  run_tests("BF", n_queensBT);
  run_tests("ST", n_queensST);
  return 0;
}