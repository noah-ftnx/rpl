
struct Graph {
  // IMPLEMENT: store edges in a DS
  Graph(int V);
  // IMPLEMENT: addEdge
  void addEdge(int src, int tgt);
  // IMPLEMENT: hasCyclesDFS
  bool hasCyclesDFS();

};



#include "test/07.h"
int main() { run_tests(); return 0; }
