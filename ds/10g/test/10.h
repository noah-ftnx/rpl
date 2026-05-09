#ifndef INC_070__CPP_DS_10G_TEST_10_H_
#define INC_070__CPP_DS_10G_TEST_10_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool _wrong {};

string show(const vector<int>& vec) {
  string res;
  for (auto v: vec) res += to_string(v) + " ";
  if (!res.empty()) res.pop_back();
  return res;
}

bool is_topological(int V, const vector<pair<int, int>>& edges, const vector<int>& order) {
  if (order.size() != V) return false;

  vector<int> pos(V, -1);
  for (int i=0; i<order.size(); i++) {
    if (order[i] < 0 || order[i] >= V || pos[order[i]] != -1) return false;
    pos[order[i]]=i;
  }

  for (auto [from, to]: edges) {
    if (pos[from] > pos[to]) return false;
  }
  return true;
}

void test(string name, int V, vector<pair<int, int>> edges) {
  Graph g(V);
  for (auto [from, to]: edges) {
    g.addEdge(from, to);
  }

  auto order = g.linearize();
  bool wrong = !is_topological(V, edges, order);
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(14) << name;
  cout << show(order);
  if (wrong) cout << " (WRONG)";
  cout << endl;
}

void run_tests() {
  test("classic", 6, {
    {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1},
  });
  test("chain", 4, {
    {0, 1}, {1, 2}, {2, 3},
  });
  test("diamond", 4, {
    {0, 1}, {0, 2}, {1, 3}, {2, 3},
  });
  test("disconnected", 5, {
    {0, 1}, {3, 4},
  });

  cout << endl;
}

#endif  // INC_070__CPP_DS_10G_TEST_10_H_
