#ifndef RPL_DS_10G_TEST_08_H_
#define RPL_DS_10G_TEST_08_H_

#include <iomanip>
#include <iostream>
using namespace std;

bool _wrong {};

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

Graph input_disconnected_cyclic() {
  auto g = Graph(6);
  g.addEdge(0, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 2);
  return g;
}

Graph input_disconnected_acyclic() {
  auto g = Graph(5);
  g.addEdge(0, 1);
  g.addEdge(2, 3);
  return g;
}

Graph input_self_loop() {
  auto g = Graph(1);
  g.addEdge(0, 0);
  return g;
}

void check(string name, Graph g, bool correct) {
  bool result = g.has_cycles();
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(24) << name;
  cout << (result ? "true" : "false");
  if (wrong) cout << " (WRONG. Expected: " << (correct ? "true" : "false") << ")";
  cout << endl;
}

void run_tests() {
  check("cyclic", input_cyclic(), true);
  check("acyclic", input_acyclic(), false);
  check("disconnected cyclic", input_disconnected_cyclic(), true);
  check("disconnected acyclic", input_disconnected_acyclic(), false);
  check("self loop", input_self_loop(), true);

  cout << endl;
}

#endif  // RPL_DS_10G_TEST_08_H_
