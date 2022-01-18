
struct Edge {
  int to;
  int w;
};

vector<int> spt(vector<list<Edge>> G, int src);



#include "test/test-dij-spt.h"
int main() { run_tests(); }