#ifndef RPL_SDE_23_TEST_04_H_
#define RPL_SDE_23_TEST_04_H_

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool _wrong {};

using Adj = vector<vector<int>>;

void add_edge(Adj &adj, int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

Adj input_cyclic() {
  Adj adj(5);
  add_edge(adj, 1, 0);
  add_edge(adj, 0, 2);
  add_edge(adj, 2, 1);
  add_edge(adj, 0, 3);
  add_edge(adj, 3, 4);
  return adj;
}

Adj input_acyclic() {
  Adj adj(3);
  add_edge(adj, 0, 1);
  add_edge(adj, 1, 2);
  return adj;
}

Adj input_disconnected_cyclic() {
  Adj adj(6);
  add_edge(adj, 0, 1);
  add_edge(adj, 2, 3);
  add_edge(adj, 3, 4);
  add_edge(adj, 4, 2);
  return adj;
}

Adj input_disconnected_acyclic() {
  Adj adj(5);
  add_edge(adj, 0, 1);
  add_edge(adj, 2, 3);
  return adj;
}

Adj input_single_node() {
  return Adj(1);
}

Adj input_star_tree() {
  Adj adj(3);
  add_edge(adj, 0, 1);
  add_edge(adj, 0, 2);
  return adj;
}

Adj input_self_loop() {
  Adj adj(1);
  add_edge(adj, 0, 0);
  return adj;
}

Adj input_branch_cycle() {
  Adj adj(6);
  add_edge(adj, 0, 1);
  add_edge(adj, 0, 2);
  add_edge(adj, 1, 3);
  add_edge(adj, 2, 4);
  add_edge(adj, 3, 5);
  add_edge(adj, 4, 5);
  return adj;
}

void check(string name, Adj adj, bool correct) {
  Solution sol;
  bool result = sol.isCycle(adj.size(), adj.data());
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
  check("single node", input_single_node(), false);
  check("star tree", input_star_tree(), false);
  check("self loop", input_self_loop(), true);
  check("branch cycle", input_branch_cycle(), true);

  cout << endl;
}

#endif  // RPL_SDE_23_TEST_04_H_
