
struct Edge {
  int to;
  int w;
};

vector<int> spt(vector<list<Edge>> G, int src);



#include "test/test-dij-sbt.h"
int main() { run_tests(); }