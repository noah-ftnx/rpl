#include <vector>
#include <algorithm>

using namespace std;

class Solution {

  int DFS(vector<vector<int>> &AL, vector<vector<int>> &res, vector<bool> &visited,
          int &latestTime, vector<int> &times, int cur, int par) {
    visited[cur]=true;
    times[cur]=++latestTime;

    int mnTime=times[cur];
    for (int nei: AL[cur]) {

      if (!visited[nei]) {
        int innerMnTime = DFS(AL, res, visited, latestTime, times, nei, cur);
        // found a bridge edge
        if (innerMnTime > times[cur]) res.push_back({cur, nei});
        mnTime=min(mnTime, innerMnTime);
      }

      if (nei != par) { // update min time
        mnTime=min(mnTime, times[nei]);
      }
    }
    return mnTime;
  }

 public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    const int V = n;
    const int E = (int) connections.size();
    // create an adjacency list
    vector<vector<int>> AL(V, vector<int>());
    for (int i=0; i<E; i++) {
      auto edge = connections[i];
      int from = edge[0], to = edge[1];
      AL[from].push_back(to);
      AL[to].push_back(from);
    }

    int latestTime=0;
    vector<int> times(V, 0);
    vector<bool> visited(V, false);

    vector<vector<int>> res;
    DFS(AL, res, visited, latestTime, times, 0, -1);
    return res;
  }
};

#include ".inc/check.h"

void run_test(string name, int n, vector<vector<int>> connections, vector<vector<int>> correct) {
  Solution s;
  auto result = s.criticalConnections(n, connections);
  check_result(name, result, correct);
}

int main() {
  run_test("triangle-tail", 4, {{0, 1}, {1, 2}, {2, 0}, {1, 3}}, {{1, 3}});
  run_test("single-edge", 2, {{0, 1}}, {{0, 1}});
  return 0;
}
