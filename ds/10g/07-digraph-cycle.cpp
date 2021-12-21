
struct Graph {
  Graph(int V);
  void addEdge(int src, int tgt);
};

bool has_cycles(const Graph& g);


#include "test/07.h"
int main() {test_cycles(); return 0; }
