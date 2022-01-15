#include <vector>
using namespace std;

struct Position { int x {-1}, y{-1}; };

int solve_slow(const vector<vector<int>>& maze, Position p) {
  const int N = maze.size();
  auto is_valid = [&](Position p) { return p.x<N && p.y<N && maze[p.x][p.y]==0; };
  auto finished = [&](Position p) { return p.x == N-1 && p.y == N-1; };

  int count = 0;
  if (is_valid(p)) {

    if (finished(p)) { return 1; }

    count+= solve_slow(maze, {p.x, p.y+1});
    count+= solve_slow(maze, {p.x+1, p.y});

  }
  return count;
}


#include <iostream>
#include <iomanip>
void print_maze(vector<vector<int>> maze) {
  const int N = maze.size();
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << setw(2) << maze[i][j] << " ";
    }
    cout << endl;
  }
}

int solve_smart(vector<vector<int>> maze) {
  const int N = maze.size();

  if (maze[0][0]==-1 || maze[N-1][N-1]==-1) return 0;

  // mark valid paths in first row/col.
  // when we find a -1 break, as we won't be able to move further down/right
  for (int j=0; j<N; j++) { if (maze[0][j]==0) maze[0][j]=1; else break; }
  // tricky: start from [1][0], as [0][0] was already covered
  for (int i=1; i<N; i++) { if (maze[i][0]==0) maze[i][0]=1; else break; }


  for (int i=1; i<N; i++) {
    for (int j=1; j<N; j++) {
      if (maze[i][j]==-1) continue;

      // valid paths: positives means valid paths..
      // path from top
      if (maze[i-1][j]>0) maze[i][j]+=maze[i-1][j];
      // path from left
      if (maze[i][j-1]>0) maze[i][j]+=maze[i][j-1];
    }
  }


  print_maze(maze);

  return maze[N-1][N-1];
}


int solve_maze(vector<vector<int>> maze) {
  // return solve_slow(maze, {0, 0});
  return solve_smart(maze);
}



#include "test/g4g-rtmz-cnt.h"
int main() { run_tests(); return 0; }