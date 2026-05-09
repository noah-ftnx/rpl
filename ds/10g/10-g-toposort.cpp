struct Graph {
  // IMPLEMENT: store edges in a DS
  Graph(int V);

  // IMPLEMENT: addEdge
  void addEdge(int v, int w);

  // IMPLEMENT: linearize
  vector<int> linearize();

};



#include "test/10.h"
int main() { run_tests(); return 0; }
