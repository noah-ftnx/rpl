#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Graph {
  const int V;
  vector<list<int>> AL;
  vector<int> indegree;

  Graph(int V) : V{V} {
    AL.resize(V);
    indegree = move(vector<int>(V, 0));
  }

  void addEdge(int v, int w) {
    AL[v].push_back(w);
    indegree[w]++;
  }

  vector<int> linearize() {
    queue<int> q;
    for (int v=0; v<V; v++) {
      if (indegree[v]==0) q.push(v);
    }

    vector<int> ind = indegree;
    vector<int> order;
    int visited=0;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      visited++;
      order.push_back(v);
      for (auto nei: AL[v]) {
        if (--ind[nei]==0) {
          q.push(nei);
        }
      }
    }

    if (visited!=V) return {};

    return order;
  }
};



#include "test/10.h"
int main() { run_tests(); return 0; }
