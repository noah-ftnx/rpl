#include <vector>
#include <list>
#include <iostream>
using namespace std;

struct Graph {
  vector<list<int>> al;
  int size;

  Graph(int n) {
    al.resize(n);
    size=n;
  }

  void addEdge(int src, int tgt) {
    al[src].push_back(tgt);
    al[tgt].push_back(src);
  }
};

bool _dfs_has_cycles(const Graph& g, vector<bool>& visited, int u, int parent) {
 visited[u]=true;

 for (auto n: g.al[u]) {
  if (!visited[n])  {
    if (_dfs_has_cycles(g, visited, n, u)) return true;
  } else if (n != parent) return true; // visited but was not visited from u
 }
 return false;
}

bool has_cycles(Graph g) {
  static vector<bool> visited(g.size, false);

  for (int i=0; i<g.size; i++) {
    if (!visited[i] && _dfs_has_cycles(g, visited, i, -1)) return true;
  }

  return false;
}


#include "test/08.h"
int main() { run_tests(); return 0; }