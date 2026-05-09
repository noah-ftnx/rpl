
struct Graph {
  // IMPLEMENT: store edges in a DS
  Graph(int V);
  // IMPLEMENT: addEdge
  void addEdge(int src, int tgt);
  // IMPLEMENT: hasCyclesBFS
  bool hasCyclesBFS();

};



#include "test/07-bfs.h"
int main() { run_tests(); return 0; }
