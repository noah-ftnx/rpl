#include <vector>
#include <list>
#include <queue>
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
    auto cycleBFS = [&, this](int vertex) -> bool {
      struct VisitFrom { int id, par; };
      queue<VisitFrom> q;
      q.push({vertex, -1});
      visited[vertex]=true;

      while(!q.empty()) {
        auto vf = q.front(); q.pop();

        for (int neighbor: AL[vf.id]) {
          if (!visited[neighbor]) {
            visited[neighbor]=true;
            q.push({neighbor, vf.id});
          } else {
            if (vf.par != neighbor) return true;
          }
        }
      }
      return false;
    };

    for (int i =0; i<V; i++) {
      if (!visited[i] && cycleBFS(i)) return true;
    }
    return false;
  }
};



#include "test/08.h"
int main() { run_tests(); return 0; }