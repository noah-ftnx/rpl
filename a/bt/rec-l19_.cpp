#include <vector>
#include <string>
using namespace std;

void solve(const vector<vector<int>> &grid,
           vector<string> &res, vector<vector<bool>> &visited,
           string cur, int i, int j) {
  const int N = (int) grid.size();
  const int M = (int) grid[0].size();

  auto isValid = [&](int i, int j) {
    return (i>=0 && j>=0 && i<N && j<M && grid[i][j] && !visited[i][j]);
  };

  // base cases:
  // blocked starting/ending points
  if (i==0 && j==0 && (!isValid(0, 0) || !isValid(N-1, M-1))) return;

  // reached the end (one of solutions)
  if (i==N-1 && j==M-1) {
    res.push_back(cur);
    return;
  }
  //

  string DIR { "DLRU" };
  vector<int> I {1,  0, 0, -1};
  vector<int> J {0, -1, 1,  0};

  // visit: DLRU (lexicograpically)
  for (int x=0; x<4; x++) {
    char c = DIR[x];
    int ii=i+I[x], jj=j+J[x];

    if (isValid(ii, jj)) {
      // CHECKS: works if i visited ii, jj ?
      visited[i][j]=true;
      solve(grid, res, visited, cur+c, ii, jj);
      visited[i][j]=false;
    }
  }
}

vector<string> findPath(vector<vector<int>> &m) {
  if (m.empty() || m[0].empty()) return {""};
  const int N = (int) m.size();
  const int M = (int) m[0].size();
  vector<vector<bool>> visited(N, vector<bool>(M, false));

  vector<string> res;
  solve(m, res, visited, "", 0, 0);
  return res;
}



#include "test/rec-l19.h"
int main() { run_tests(); return 0; }