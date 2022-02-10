#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void solve(vector<vector<int>>& grid, int& visit_num,
           int& cnt,int row, int col) {
  const int N = (int) grid.size();

  auto is_pos_valid = [&] (int i, int j) {
    return (i>=0 && i<N) && (j>=0 && j<N);
  };

  auto get_valid_moves = [&](int i, int j) {
    vector<pair<int, int>> res;
    auto add_if_valid = [&](int x, int y) {
      if (is_pos_valid(x, y) && grid[x][y]==0) res.push_back({x, y});
    };

    add_if_valid(i+1, j+2);
    add_if_valid(i+1, j-2);
    add_if_valid(i-1, j+2);
    add_if_valid(i-1, j-2);

    add_if_valid(i+2, j+1);
    add_if_valid(i+2, j-1);
    add_if_valid(i-2, j+1);
    add_if_valid(i-2, j-1);

    return res;
  };


  if (visit_num==N*N) { // found a solution
    cnt++;
    return;
  }

  auto moves = get_valid_moves(row, col);

#ifdef _WARNSDORFFS_HEURISTIC
  auto apply_warnsdorffs_heuristic = [&](vector<pair<int, int>>& moves) {
    sort(moves.begin(), moves.end(),
         [&](pair<int, int> a, pair<int, int> b){
           auto moves_a = get_valid_moves(a.first, a.second);
           auto moves_b = get_valid_moves(b.first, b.second);

           // use first the position with the least valid moves
           return moves_a.size() > moves_b.size();
         });
  };

  if (_apply_heuristic && moves.size() > 1) {
    apply_warnsdorffs_heuristic(moves);
  }
#endif

  for (auto move: moves) {
    int x=move.first, y=move.second;
    grid[x][y]=1;
    visit_num++;

    solve(grid, visit_num, cnt, x, y);

    grid[x][y]=0;
    visit_num--;
  }
}

int knights_tour(int N) {
  if (N<=0) return 0;
  vector<vector<int>> grid(N, vector<int>(N, 0));

  int cnt {};
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int visit_num{1};
      grid[i][j]=1;
      solve(grid, visit_num, cnt, i, j);
      grid[i][j]=0;
    }
  }
  // for each position
  return cnt;
}


#include "test/064.h"
int main() { run_tests(); return 0; }