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

  void DFS(vector<bool> &visited, deque<int>& order, int v) {
    visited[v]=true;

    for (auto nei: AL[v]) {
     if (!visited[nei]) DFS(visited, order, nei);
    }

    order.push_front(v);
  }

  vector<int> linearize() {
    vector<bool> visited(V, false);

    deque<int> order;
    for (int v=0; v<V; v++) {
      if (!visited[v]) DFS(visited, order, v);
    }

    vector<int> result;
    result.insert(result.begin(), order.begin(), order.end());
    return result;
  }
};



#include "test/10.h"
int main() { run_tests(); return 0; }
