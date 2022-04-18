#ifndef RPL_DS_10G_TEST_01_H_
#define RPL_DS_10G_TEST_01_H_

#include "input-traversal.h"

void BFS(const vector<list<Edge>>& G, int src);

void run_tests() {
  const int src = 3;
  cout << "BFS (src:" << src << ") undirected graph:\n";
  vector<list<Edge>> G(input_graph_undirected());
  BFS(G, src);

  cout << endl;
  cout << "3 2 4 1 7 5 6   <- correct traversal (src:3)\n";
}

#endif  // RPL_DS_10G_TEST_01_H_
