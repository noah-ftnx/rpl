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

Graph input_cyclic() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  return g;
}

Graph input_acyclic() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  return g;
}


void test_cycles() {
  cout << "Cycles in a Digraph" << endl;
  auto gCyclic = input_cyclic();
  bool gc =has_cycles(gCyclic);
  cout << "Graph: Cyclic: has_cycles " << gc << (!gc?" (WRONG)": "")  << endl;

  auto gAcyclic= input_acyclic();
  bool ga =has_cycles(gAcyclic);
  cout << "Graph: Acyclic: has_cycles " << ga << (ga?" (WRONG)": "")  << endl;
}

int main() {
  test_cycles();
  return 0;
}