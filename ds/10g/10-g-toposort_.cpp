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

  bool dfs(int v, vector<int>& state, vector<int>& order) {
    state[v]=1; // open

    for (auto nei: AL[v]) {
      if (state[nei]==1) return true; // cycle
      if (state[nei]==0 && dfs(nei, state, order)) return true;
    }

    state[v]=2; // closed
    order.push_back(v);
    return false;
  }

  vector<int> linearize() {
    vector<int> state(V, 0);
    vector<int> order;

    for (int v=0; v<V; v++) {
      if (state[v]==0 && dfs(v, state, order)) return {};
    }

    reverse(order.begin(), order.end());
    return order;
  }
};



#include "test/10.h"
int main() { run_tests(); return 0; }
