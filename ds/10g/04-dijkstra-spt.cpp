
struct Edge {
  int to;
  int w;
};

// IMPLEMENT: return shortest cost from src to every vertex
vector<int> min_costs(vector<list<Edge>> G, int src);



#include "test/test-dij-spt.h"
int main() { run_tests(); }
