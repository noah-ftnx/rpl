#include <vector>

using namespace std;

class SolutionBT {
  bool checkDFS(int N, vector<vector<int>> AL, vector<bool> &visited, int cnt, int i) {
    visited[i]=true;
    if (cnt==N) return true; // visited all V vertices
        
    for (int nei: AL[i]) {
      if (!visited[nei] && checkDFS(N, AL, visited, cnt+1, nei)) return true;
    }
        
    visited[i]=false; // backtrack
    return false;
  }
    
 public:
  bool check(int N,int M, vector<vector<int>> Edges) {
    // build AL
    vector<vector<int>> AL(N+1, vector<int>());
    for (auto edge: Edges) {
      int from = edge[0];
      int to = edge[1];
      AL[from].push_back(to);
      AL[to].push_back(from);
    }

    // try
    for (int i=1; i<=N; i++) {
      vector<bool> visited(N+1, false);
      int cnt=0;
      if (checkDFS(N, AL, visited, 1, i)) return true;
    }
        
    return false;
  }
};

#include ".inc/check.h"

void run_test(string name, int N, vector<vector<int>> edges, bool correct) {
  SolutionBT s;
  check_bool(name, s.check(N, (int)edges.size(), edges), correct);
}

int main() {
  run_test("path", 4, {{1, 2}, {2, 3}, {3, 4}}, true);
  run_test("star", 4, {{1, 2}, {1, 3}, {1, 4}}, false);
  return 0;
}
