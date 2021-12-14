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

  return false;
}

Graph input_cyclic() {
  auto g = Graph(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  return g;
}

Graph input_acyclic() {
  auto g = Graph(3);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  return g;
}


void test_cycles() {
  cout << "Cycles in a Graph (non-directed)" << endl;
  auto gCyclic=input_cyclic();
  bool gc=has_cycles(gCyclic);
  cout << "Graph: Cyclic: has_cycles " << gc << (!gc?" (WRONG)": "")  << endl;

  auto gAcyclic=input_acyclic();
  bool ga=has_cycles(gAcyclic);
  cout << "Graph: Acyclic: has_cycles " << ga << (ga?" (WRONG)": "")  << endl;
}

int main() {
  test_cycles();
  return 0;
}