#ifndef RPL_DS_10G_TEST_07_H_
#define RPL_DS_10G_TEST_07_H_

#include <iostream>

Graph input_cyclic() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  return g;
}

Graph input_acyclic() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  return g;
}

void run_tests() {
  auto gCyclic=input_cyclic();
  bool gc=gCyclic.has_cycles();
  cout << "Graph: Cyclic: has_cycles " << gc << (!gc?" (WRONG)": "")  << endl;

  auto gAcyclic=input_acyclic();
  bool ga=gAcyclic.has_cycles();
  cout << "Graph: Acyclic: has_cycles " << ga << (ga?" (WRONG)": "")  << endl;
}

#endif  // RPL_DS_10G_TEST_07_H_
