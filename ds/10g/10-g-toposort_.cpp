#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Graph {
  const int V;
  vector<list<int>> AL;

  Graph(int V) : V{V} { AL.resize(V); }

  void addEdge(int v, int w) {
    AL[v].push_back(w);
  }

  void dfs(int v, vector<bool>& visited, vector<int>& order) {
    visited[v]=true;

    for (auto nei: AL[v]) {
      if (!visited[nei]) dfs(nei, visited, order);
    }

    order.push_back(v);
  }

  vector<int> linearize() {
    vector<bool> visited(V, false);
    vector<int> order;

    for (int v=0; v<V; v++) {
      if (!visited[v]) dfs(v, visited, order);
    }

    reverse(order.begin(), order.end());
    return order;
  }
};



#include "test/10.h"
int main() { run_tests(); return 0; }
