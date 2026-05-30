#ifndef RPL_SDE_23_TEST_08_H_
#define RPL_SDE_23_TEST_08_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

using Adj = vector<vector<int>>;

void add_edge(Adj &adj, int u, int v) {
  adj[u].push_back(v);
}

bool valid_topo(const Adj& adj, const vector<int>& order) {
  const int V = adj.size();
  if (order.empty()) return false;
  if ((int)order.size() != V) return false;

  vector<int> pos(V, -1);
  for (int i = 0; i < V; i++) pos[order[i]] = i;
  for (int u = 0; u < V; u++) {
    for (int v : adj[u]) {
      if (pos[u] >= pos[v]) return false;
    }
  }
  return true;
}

void check_dag(string name, Adj adj) {
  Solution sol;
  auto got = sol.topoSort(adj.size(), adj.data());
  bool wrong = !valid_topo(adj, got);
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
}

void check_cycle(string name, Adj adj) {
  Solution sol;
  auto got = sol.topoSort(adj.size(), adj.data());
  bool wrong = !got.empty();
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << endl;
}

void run_tests() {
  Adj dag1(3);
  add_edge(dag1, 0, 1);
  add_edge(dag1, 1, 2);
  check_dag("chain", dag1);

  Adj dag2(4);
  add_edge(dag2, 0, 1);
  add_edge(dag2, 0, 2);
  add_edge(dag2, 1, 3);
  add_edge(dag2, 2, 3);
  check_dag("diamond", dag2);

  Adj dag3(4);
  add_edge(dag3, 0, 1);
  add_edge(dag3, 2, 3);
  check_dag("disconnected", dag3);

  Adj cyc(3);
  add_edge(cyc, 0, 1);
  add_edge(cyc, 1, 2);
  add_edge(cyc, 2, 0);
  check_cycle("cycle", cyc);

  cout << endl;
}

#endif  // RPL_SDE_23_TEST_08_H_
