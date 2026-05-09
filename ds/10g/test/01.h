#ifndef RPL_DS_10G_TEST_01_H_
#define RPL_DS_10G_TEST_01_H_

#include "input-traversal.h"
#include <sstream>

void BFS(const vector<list<Edge>>& G, int src);

bool _wrong {};

vector<int> run_bfs(const vector<list<Edge>>& G, int src) {
  ostringstream out;
  auto *old = cout.rdbuf(out.rdbuf());
  BFS(G, src);
  cout.rdbuf(old);

  vector<int> result;
  istringstream in(out.str());
  int x {};
  while (in >> x) result.push_back(x);
  return result;
}

void check(string name, const vector<list<Edge>>& G, int src, vector<int> correct) {
  auto result = run_bfs(G, src);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << ": ";
  for (auto x: result) cout << x << " ";
  if (wrong) {
    cout << "(WRONG. Expected: ";
    for (auto x: correct) cout << x << " ";
    cout << ")";
  }
  cout << endl;
}

void run_tests() {
  check("input graph", input_graph_undirected(), 3, {3, 2, 4, 1, 7, 5, 6});

  vector<list<Edge>> diamond(4);
  diamond[0].push_back({1});
  diamond[0].push_back({2});
  diamond[1].push_back({3});
  diamond[2].push_back({3});
  check("duplicate scheduling", diamond, 0, {0, 1, 2, 3});

  vector<list<Edge>> fan_in(5);
  fan_in[0].push_back({1});
  fan_in[0].push_back({2});
  fan_in[0].push_back({3});
  fan_in[1].push_back({4});
  fan_in[2].push_back({4});
  fan_in[3].push_back({4});
  check("fan in", fan_in, 0, {0, 1, 2, 3, 4});

  vector<list<Edge>> cycle(4);
  cycle[0].push_back({1});
  cycle[1].push_back({2});
  cycle[2].push_back({0});
  cycle[2].push_back({3});
  check("cycle", cycle, 0, {0, 1, 2, 3});

  vector<list<Edge>> self_loop(3);
  self_loop[0].push_back({0});
  self_loop[0].push_back({1});
  self_loop[1].push_back({2});
  check("self loop", self_loop, 0, {0, 1, 2});

  vector<list<Edge>> disconnected(5);
  disconnected[0].push_back({1});
  disconnected[3].push_back({4});
  check("disconnected", disconnected, 0, {0, 1});

  cout << endl;
}

#endif  // RPL_DS_10G_TEST_01_H_
