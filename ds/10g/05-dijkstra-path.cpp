struct Edge {
  int to;
  int w;
};


deque<int> spt_path(vector<list<Edge>> G, int src, int target);



#include "test/test-dij-path.h"
int main() { run_tests(); }
