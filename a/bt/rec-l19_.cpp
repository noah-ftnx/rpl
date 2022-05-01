/**
0: blocked



DLRU

  */

#include <vector>
#include <string>
using namespace std;


bool isBlocked(const vector<vector<int>> &m, int i, int j) {
  return m[i][j]==0;
}

void solve(const vector<vector<int>> &m,
  vector<vector<bool>> &visited,
  vector<string> &res, string cur, int i, int j) {
  const int N = m.size();
  const int M = m[0].size();
  auto isValid = [&] (int i, int j) -> bool {
    const bool inBounds {i>=0 && j>=0 && i<N && j<M};
    return (inBounds && !isBlocked(m, i, j) && !visited[i][j]);
  };

  // base case: reached the end
  if (i==N-1 && j == M-1) {
    res.push_back(cur);
    return;
  }

  // explore valid directions: DLRU
  string DIR {"DLRU"};
  vector<int> I {+1, +0, +0, -1};
  vector<int> J {+0, -1, +1, +0};

  for (int x=0; x<4; x++) {
    int nextI = i+I[x];
    int nextJ = j+J[x];
    char dir = DIR[x];

    if (isValid(nextI, nextJ)) {
      visited[i][j]=true;
      solve(m, visited, res, cur+dir, nextI, nextJ);
      visited[i][j]=false;
    }
  }

}

vector<string> findPath(vector<vector<int>> &m) {
  if (m.empty() || m[0].empty()) return {};

  const int N = m.size();
  const int M = m[0].size();
  if (isBlocked(m, 0, 0) || isBlocked(m, N-1, M-1)) return {};

  vector<string> res;
  vector<vector<bool>> visited (N, vector<bool>(M, false));
  solve(m, visited, res, "", 0, 0);
  return res;
}



#include "test/rec-l19.h"
int main() { run_tests(); return 0; }