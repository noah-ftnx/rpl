
struct Graph {

  Graph(int V);
  void addEdge(int src, int tgt);
  bool has_cycles();

};



#include "test/08.h"
int main() { run_tests(); return 0; }