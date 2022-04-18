struct Edge {
  int id {};
  int weight {};
};

void DFS(const vector<list<Edge>>& G, int src);



#include "test/02.h"
int main() { run_tests(); return 0; }