#include <vector>
using namespace std;

struct Position {
  int x{-1}, y{-1};
};

bool solve(vector<vector<int>> maze, vector<vector<int>>& solution, Position pos) {
  const int N = maze.size();
  auto mark = [&](Position p) { solution[p.x][p.y] = 1; };
  auto unmark = [&](Position p) { solution[p.x][p.y] = 0; };
  auto finished = [&]() { return pos.x==N-1 && pos.y==N-1; };
  auto is_valid = [&](Position p) {
    if (p.x>=N || p.y>=N) return false;
    return maze[p.x][p.y] == 1;
  };

  if (is_valid(pos)) {
    mark(pos);

    if (finished()) return true;

    if (solve(maze, solution, {pos.x, pos.y+1})) return true;
    if (solve(maze, solution, {pos.x+1, pos.y})) return true;

    unmark(pos);
  }
  return false; // backtrack
}

bool solve_maze(vector<vector<int>> maze, vector<vector<int>>& solution) {
  return solve(maze, solution, {0, 0});
}



#include "test/g4g-rtmz.h"
int main() { run_tests(); return 0; }