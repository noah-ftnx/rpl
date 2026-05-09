#ifndef RPL_DS_10G_TEST_07_BFS_H_
#define RPL_DS_10G_TEST_07_BFS_H_

#include <iostream>
#include <string>
using namespace std;

void check(string name, Graph& g, bool expected) {
  bool res = g.hasCyclesBFS();
  bool wrong = res != expected;
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << name << ": " << res;
  if (wrong) cout << " (Expected: " << expected << ")";
  cout << endl;
}

Graph input_simple_cycle() {
  auto g = Graph(3);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  return g;
}

Graph input_self_loop() {
  auto g = Graph(3);
  g.addEdge(0, 1);
  g.addEdge(1, 1);
  return g;
}

Graph input_disconnected_cycle() {
  auto g = Graph(5);
  g.addEdge(0, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 2);
  return g;
}

Graph input_long_cycle() {
  auto g = Graph(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 1);
  return g;
}

Graph input_chain() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  return g;
}

Graph input_diamond() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  return g;
}

Graph input_cross_edge() {
  auto g = Graph(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(1, 3);
  return g;
}

void run_tests() {
  auto simpleCycle = input_simple_cycle();
  check("simple cycle", simpleCycle, true);

  auto selfLoop = input_self_loop();
  check("self loop", selfLoop, true);

  auto disconnectedCycle = input_disconnected_cycle();
  check("disconnected cycle", disconnectedCycle, true);

  auto longCycle = input_long_cycle();
  check("long cycle", longCycle, true);

  auto chain = input_chain();
  check("chain", chain, false);

  auto diamond = input_diamond();
  check("diamond", diamond, false);

  auto crossEdge = input_cross_edge();
  check("cross edge", crossEdge, false);
}

#endif  // RPL_DS_10G_TEST_07_BFS_H_
