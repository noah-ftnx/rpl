#ifndef RPL_DS_10G_TEST_08_H_
#define RPL_DS_10G_TEST_08_H_

#include <iostream>

Graph input_cyclic() {
  auto g = Graph(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  return g;
}

Graph input_acyclic() {
  auto g = Graph(3);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  return g;
}

void run_tests() {
  cout << "Cycles in a Graph (undirected)" << endl;
  auto gCyclic=input_cyclic();
  bool gc=gCyclic.has_cycles();
  cout << "Graph: Cyclic:  has_cycles: " << gc << (!gc?" (WRONG)": "")  << endl;

  auto gAcyclic=input_acyclic();
  bool ga=gAcyclic.has_cycles();
  cout << "Graph: Acyclic: has_cycles: " << ga << (ga?" (WRONG)": "")  << endl;
}

#endif  // RPL_DS_10G_TEST_08_H_
