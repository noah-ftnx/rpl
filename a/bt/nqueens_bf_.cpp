#include <vector>
#include <utility>
#include <set>
using namespace std;

// bool _dbg = false;

// void print_board(const int N, const vector<int>& board); // IMPLEMENTED
// void print_permutations(const int N, const set<vector<int>>& permutations); // IMPLEMENTED

void get_permutations(const int N, vector<int>& board,
                      set<vector<int>>& permutations) {

  auto not_added = [&]() {
    vector<int> cp(board);
    sort(cp.begin(), cp.end());
    return permutations.contains(cp);
  };

  if (board.size() == N) {
    if(!not_added()) {
      permutations.insert(board);
      // if (_dbg) {
      //   cout << "added: ";
      //   for (auto b: board) cout << b; cout << endl;
      // }
    }
    return;
  }

  for (int i=0; i<N*N; i++) {
    bool in_board = false;
    for (auto b: board) if (b == i) { in_board = true; break; }
    if (!in_board) {
      board.push_back(i); // try solution

      get_permutations(N, board, permutations);

      board.pop_back(); // backtrack
    }
  }
}

int count_valid_permutations(const int N, const set<vector<int>>& permutations) {
  int cnt = 0;
  for (auto board: permutations) {

    // check if each queen attacks any other queen:
    bool attacked=false;
    for (int i=0; !attacked && i<board.size()-1; i++) {
      int selected_queen = board[i];
      int sq_row = selected_queen/N;
      int sq_col = selected_queen%N;

      for (int j=0; !attacked && j<board.size(); j++) { // other queens
        if (i==j) continue; // same queen

        int other_queen = board[j];
        int row = other_queen/N;
        int col = other_queen%N;

        int col_diff = abs(sq_col-col);
        int row_diff = abs(sq_row-row);  // check for rows too in Brute force
        if (col_diff == 0 || row_diff == 0 || col_diff == row_diff) attacked=true;
      } // other queens

    } // each queen

    if (!attacked) {
      cnt++;
    }
  }
  return cnt;
}


pair<int, int> n_queensBF(int N) {
  vector<int> board;
  if (N==0) return make_pair(1, 1);

  set<vector<int>> permutations;
  get_permutations(N, board, permutations);
  return make_pair(count_valid_permutations(N, permutations), permutations.size());
}


#include "test/nqueens_bf.h"
int main() {
  run_tests("BF", n_queensBF);
  return 0;
}