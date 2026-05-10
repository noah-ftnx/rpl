#ifndef REPL_DS_10G_TEST_DIJ_PATH_H_
#define REPL_DS_10G_TEST_DIJ_PATH_H_

#include "input-spt.h"

deque<int> spt_path(vector<list<Edge>> G, int src, int target);

string path_to_string(deque<int> path) {
  string result;
  for (auto p: path) {
    if (!result.empty()) result += " ";
    result += to_string(p);
  }
  return result;
}

void test_path(vector<list<Edge>> g, int src, int tgt, string expected, string desc) {
  auto path = spt_path(g, src, tgt);
  string result = path_to_string(path);
  bool wrong = result != expected;
  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << desc << ": " << src << " -> " << tgt << ": " << result;
  if (wrong) cout << " Expected: " << expected;
  cout << endl;
}

vector<list<Edge>> input_local_edge_bug() {
  vector<list<Edge>> g(4);
  auto addEdge = [&](int from, int to, int weight) {
    g[from].push_back({to, weight});
    g[to].push_back({from, weight});
  };

  addEdge(0, 1, 10);
  addEdge(0, 2, 5);
  addEdge(2, 3, 7);
  addEdge(1, 3, 1);

  return g;
}

vector<list<Edge>> input_unreachable() {
  vector<list<Edge>> g(4);
  g[0].push_back({1, 2});
  g[1].push_back({0, 2});
  g[2].push_back({3, 1});
  g[3].push_back({2, 1});
  return g;
}

void run_tests() {
  cout << "spt_path-dijkstra\n";
  test_path(input_adj_list(), 0, 0, "0", "main");
  test_path(input_adj_list(), 0, 1, "0 1", "main");
  test_path(input_adj_list(), 0, 2, "0 1 2", "main");
  test_path(input_adj_list(), 0, 3, "0 1 2 3", "main");
  test_path(input_adj_list(), 0, 4, "0 7 6 5 4", "main");
  test_path(input_adj_list(), 0, 5, "0 7 6 5", "main");
  test_path(input_adj_list(), 0, 6, "0 7 6", "main");
  test_path(input_adj_list(), 0, 7, "0 7", "main");
  test_path(input_adj_list(), 0, 8, "0 1 2 8", "main");
  test_path(input_local_edge_bug(), 0, 3, "0 1 3", "total-cost pq");
  test_path(input_unreachable(), 0, 3, "", "unreachable");
}

#endif //REPL_DS_10G_TEST_DIJ_PATH_H_
