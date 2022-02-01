const int N=4;
const int M=4;

#include <climits>
#include <queue>
#include <vector>
using namespace std;

int min_steps(bool input[N][M], pair<int, int> start, pair<int, int> end) {
  struct Position { int x, y, cost; };
  vector<vector<bool>> visited(N, vector<bool>(M, false));
  Position s {start.first, start.second, 0};
  Position e {end.first, end.second, 0};

  auto is_wall = [&](Position p) { return input[p.x][p.y]; };
  auto visit = [&](Position p) { visited[p.x][p.y]=true; };
  auto is_visited = [&](Position p) { return visited[p.x][p.y]; };
  auto finished= [&](Position p) { return p.x == e.x && p.y == e.y; };

  if (is_wall(s) || is_wall(e)) return -1;

  queue<Position> q({s});
  visit(s);

  while(!q.empty()) {
    auto visit_if_valid = [&] (Position p) {
      if (p.x>=0 && p.y>=0 && p.x<N && p.y<M && !is_visited(p) && !is_wall(p)) {
        q.push(p);
        visit(p);
      }
    };

    auto p = q.front(); q.pop();

    if (finished(p)) return p.cost;

    visit_if_valid({p.x+1, p.y, p.cost+1});
    visit_if_valid({p.x-1, p.y, p.cost+1});
    visit_if_valid({p.x, p.y+1, p.cost+1});
    visit_if_valid({p.x, p.y-1, p.cost+1});
  }

  return -1;
}



#include "test/023.h"
int main() { run_tests(); return 0; }