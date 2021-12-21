#include <vector>
#include <list>
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
  }
};

bool _dfs_has_cycles(Graph& g, vector<bool>& visited, int v) {
  static vector<bool> in_stack(g.size, false);

  visited[v]=true;
  in_stack[v]=true;

  for (auto n: g.al[v]) {
   if(!visited[n] && _dfs_has_cycles(g, visited, n))  return true;
   else if(in_stack[n]) return true; // back-edge
  }

  in_stack[v]=false;

 return false;
}

bool has_cycles(Graph g) {
  vector<bool> visited(g.size, false);
  for (int i=0; i<g.size; i++) { // O(|V|)
    if(!visited[i] && _dfs_has_cycles(g, visited, i)) return true;
  }

  return false;
}

#include "test/07.h"
int main() {test_cycles(); return 0; }
