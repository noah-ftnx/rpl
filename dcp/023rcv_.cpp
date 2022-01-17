
const int N=4;
const int M=4;

#include <climits>
#include <utility>
#include <vector>
using namespace std;

struct Position { int x, y; };

void find_steps(bool input[N][M], vector<vector<int>>& dist, Position p, int step=-1) {

  auto set_dist = [&](Position p, int val) { dist[p.x][p.y]=val; };
  auto get_dist = [&](Position p) { return dist[p.x][p.y]; };
  auto in_bounds= [&](Position p) { return p.x>=0 && p.y>=0 && p.x<N && p.y<M; };
  auto is_wall = [&](Position p) { return input[p.x][p.y]; };

  if (step > get_dist(p)) return; // slower method

  set_dist(p, min(get_dist(p), step+1));

  auto visit_if_valid = [&](Position p) {
    if (in_bounds(p) && !is_wall(p)) find_steps(input, dist, p, step+1);
  };

  visit_if_valid({p.x+1, p.y});
  visit_if_valid({p.x-1, p.y});
  visit_if_valid({p.x, p.y+1});
  visit_if_valid({p.x, p.y-1});
}

int min_steps(bool input[N][M], pair<int, int> start, pair<int, int> end) {
  vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
  Position s {start.first, start.second};

  find_steps(input, dist, s);

  return dist[end.first][end.second];
}



#include "test/023.h"
int main() { run_tests(); return 0; }