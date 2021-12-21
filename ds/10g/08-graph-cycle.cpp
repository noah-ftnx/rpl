
struct Graph {
  Graph(int n);
  void addEdge(int src, int tgt);
};


bool has_cycles(Graph g);



#include "test/08.h"
int main() { run_tests(); return 0; }