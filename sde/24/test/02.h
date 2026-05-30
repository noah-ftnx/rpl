#ifndef RPL_SDE_24_TEST_02_H_
#define RPL_SDE_24_TEST_02_H_

#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

using Adj = vector<vector<int>>;

void add_edge(Adj adj[], int from, int to, int cost) {
  adj[from].push_back({to, cost});
}

void check(string name, int V, Adj adj[], int S, vector<int> correct) {
  Solution sol;
  auto got = sol.dijkstra(V, adj, S);
  bool wrong = got != correct;
  _wrong |= wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name;
  if (wrong) cout << " (expected diff)";
  cout << endl;
}

void run_tests() {
  {
    Adj adj[3];
    add_edge(adj, 0, 1, 1);
    add_edge(adj, 0, 2, 4);
    add_edge(adj, 1, 2, 2);
    check("triangle", 3, adj, 0, {0, 1, 3});
  }
  {
    Adj adj[4];
    add_edge(adj, 0, 1, 5);
    add_edge(adj, 0, 2, 10);
    add_edge(adj, 1, 2, 1);
    check("unreachable", 4, adj, 0, {0, 5, 6, INT_MAX});
  }
  cout << endl;
}

#endif  // RPL_SDE_24_TEST_02_H_
