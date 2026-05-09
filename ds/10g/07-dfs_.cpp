#include <vector>
#include <list>
using namespace std;

struct Graph {
  vector<list<int>> AL;
  int V;

  Graph(int V) : V{V} {
    AL.resize(V);
  }

  void addEdge(int src, int tgt) {
    AL[src].push_back(tgt);
  }

  bool cycleDFS(vector<bool>& visited, vector<bool>& in_stack, int vertex) {
    visited[vertex]=true;
    in_stack[vertex]=true;

    for (auto n: AL[vertex]) {
      if(!visited[n] && cycleDFS(visited, in_stack, n))  return true;
      else if(in_stack[n]) return true; // back-edge
    }

    in_stack[vertex]=false;

    return false;
  }

  bool hasCyclesDFS() {
    vector<bool> visited(V, false);
    vector<bool> in_stack(V, false);
    for (int i=0; i<V; i++) { // O(|V|)
      if(!visited[i] && cycleDFS(visited, in_stack, i)) return true;
    }

    return false;
  }


};


#include "test/07.h"
int main() { run_tests(); return 0; }
