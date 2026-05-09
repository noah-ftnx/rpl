
struct Graph {

  Graph(int V);
  // IMPLEMENT: addEdge
  void addEdge(int src, int tgt);
  // IMPLEMENT: has_cycles
  bool has_cycles();

};



#include "test/08.h"
int main() { run_tests(); return 0; }