#ifndef INC_070__CPP_DS_10G_TEST_02_H_
#define INC_070__CPP_DS_10G_TEST_02_H_


#include "input-traversal.h"
#include <iostream>

int run_tests() {
  const int src = 3;
  cout << "DFS (src:" << src << ") undirected graph:\n";
  vector<list<Edge>> G(input_graph_undirected());
  DFS(G, src);

  cout << endl;
  cout << "3 2 1 6 5 4 7  <- correct traversal (src:3)\n";
}

#endif  // INC_070__CPP_DS_10G_TEST_02_H_
