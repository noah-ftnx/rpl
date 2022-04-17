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

  bool cyclesDFS(vector<bool>& visited, int u, int parent) {
    visited[u]=true;

    for (auto n: AL[u]) {
      if (visited[n]) {
        // it's not from where we just came from
        if (n != parent) return true;
      } else {
        if (cyclesDFS(visited, n, u)) return true;
      }
    }
    return false;
  }

  bool has_cycles() {
    static vector<bool> visited(V, false);
    for (int i=0; i<V; i++) {
      if (!visited[i] && cyclesDFS(visited, i, -1)) return true;
    }

    return false;
  }

};



#include "test/08.h"
int main() { run_tests(); return 0; }