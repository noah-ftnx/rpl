#include <vector>
#include <list>
#include <iostream>
using namespace std;

struct Graph {
  const int V;
  vector<list<int>> AL;

  Graph(int V) : V {V} {
    AL.resize(V);
  }

  void addEdge(int src, int tgt) {
    AL[src].push_back(tgt);
    AL[tgt].push_back(src);
  }

  bool has_cycles() {
    vector<bool> visited(V, false);

    queue<int> q;
    for (int i=0; i<V; i++) {
      q.push(i);

      while(!q.empty()) {
        auto vertex = q.front(); q.pop();
        visited[vertex]=true;

      }

    }
  }

};



#include "test/08.h"
int main() { run_tests(); return 0; }