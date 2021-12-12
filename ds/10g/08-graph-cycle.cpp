#include <vector>
#include <list>
#include <iostream>
using namespace std;

struct Graph {
  Graph(int n);
  void addEdge(int src, int tgt);
};

bool has_cycles(Graph g);



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



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

void main() {test_cycles(); }