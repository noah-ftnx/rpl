#include <vector>
#include <list>
#include <deque>
using namespace std;

struct Graph {
  const int V;
  vector<list<int>> AL;

  Graph(int V) : V{V} { AL.resize(V); }

  void addEdge(int v, int w) {
    AL[v].push_back(w);
  }

  bool DFS(vector<int>& state, deque<int>& order, int v) {
    state[v]=1; // open

    for (auto nei: AL[v]) {
      if (state[nei]==1) return true; // cycle
      if (state[nei]==0 && DFS(state, order, nei)) return true;
    }

    state[v]=2; // closed
    order.push_front(v);
    return false;
  }

  vector<int> linearize() {
    vector<int> state(V, 0);

    deque<int> order;
    for (int v=0; v<V; v++) {
      if (state[v]==0 && DFS(state, order, v)) return {};
    }

    vector<int> result;
    result.insert(result.begin(), order.begin(), order.end());
    return result;
  }
};



#include "test/10.h"
int main() { run_tests(); return 0; }
