struct Coord {
  int x; int y;

  bool operator<(const Coord& o) const {
    if (x < o.x) return true;
    else if (x==o.x) return y < o.y;
    return false;
  }

  bool operator>(const Coord& o) const { return o < *this; }
};

#include <iostream>
#include <vector>
using namespace std;

void GOL(vector<Coord> live_cells, int steps,
         vector<vector<vector<bool>>>& result) {
  Coord TL {INT_MAX, INT_MAX}, BR {-1, -1};
  for (auto coord: live_cells) {
    if (coord < TL) TL=coord;
    if (coord > BR) BR=coord;
  }

  const int X = BR.x+1, Y=BR.y+1;
  vector<vector<bool>> board(X, vector<bool>(Y, false));
  for (auto cell: live_cells) board[cell.x][cell.y]=true;

  auto live_neighbors = [&](Coord cell)-> int {
    const int startX = max(cell.x-1, 0);
    const int startY = max(cell.y-1, 0);
    const int endX= min(cell.x+1, X-1);
    const int endY = min(cell.y+1, Y-1);

    int cnt {};
    for (int i=startX; i<=endX; i++)
      for (int j=startY; j<=endY; j++)
        if ((!(i==cell.x && j==cell.y)) && board[i][j]) cnt++;

    // cout << "Neighbors of: ["  << cell.x << "," << cell.y << "]: " << cnt << endl;

    return cnt;
  };

  auto run_gol = [&]() {
    vector<vector<bool>> new_state(X, vector<bool>(Y, false));
    for (int i=0; i<X; i++) {
      for (int j=0; j<Y; j++) {
        int live_n = live_neighbors({i, j});
        if (live_n==3) new_state[i][j]=true; // either for alive or dead
        else if (board[i][j] && live_n == 2) new_state[i][j]=true;
      }
    }
    swap(board, new_state);
  };

  auto print_board = [&]() {
    for (int i=TL.x; i<X; i++) {
      for (int j=TL.y; j<Y; j++) {
        cout << (board[i][j]? "*":".") << " ";
      }
      cout << endl;
    }
  };

  result.push_back(board);
  cout << "Board:\n";
  print_board();

  while(steps--) {
    run_gol();
    result.push_back(board);
    cout << "Step: "<< endl;
    print_board();
  }
}



#include "test/039.h"
int main() { run_tests(); return 0; }