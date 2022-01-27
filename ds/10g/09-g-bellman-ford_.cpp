#include <vector>
using namespace std;

struct Edge {
  int src;
  int dest;
  int weight;
};

struct Graph {

  const int V, E;
  vector<Edge> edges;

  Graph(int V, int E) : V{V}, E{E} {
    edges.resize(E);
  }

  vector<int> BellmanFord(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src]=0;
    int relaxations=V-1;
    while (relaxations--) {
      for (auto edge: edges) {
        if (
            dist[edge.src] != INT_MAX && // no need to check on this case
            dist[edge.dest] > dist[edge.src] + edge.weight) {
          dist[edge.dest] = dist[edge.src] + edge.weight;
        }
      }
    }
    return dist;
  }
};



#include "test/09-g-bellman-ford.h"
int main() { run_tests(); return 0; }