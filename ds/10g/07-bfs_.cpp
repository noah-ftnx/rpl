#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Graph {
  int V;
  vector<list<int>> AL;

  Graph(int V) : V{V} {
    AL.resize(V);
  }

  void addEdge(int src, int tgt) {
    AL[src].push_back(tgt);
  }

  bool hasCyclesBFS() {
    vector<int> indegree(V, 0);
    for (int src=0; src<V; src++) {
      for (int tgt: AL[src]) {
        indegree[tgt]++;
      }
    }

    queue<int> q;
    for (int i=0; i<V; i++) {
      if (indegree[i]==0) q.push(i);
    }

    int visited=0;
    while (!q.empty()) {
      int node=q.front(); q.pop();
      visited++;

      for (int nei: AL[node]) {
        if (--indegree[nei]==0) {
          q.push(nei);
        }
      }
    }

    return visited != V;
  }
};



#include "test/07-bfs.h"
int main() { run_tests(); return 0; }
