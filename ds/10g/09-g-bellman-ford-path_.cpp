#include <vector>
#include <deque>
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

    // struct Graph* graph = new Graph;
    // graph->V = V;
    // graph->E = E;
    // graph->edge = new Edge[E];

  }

  deque<int> BellmanFord(int src, int tgt) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[src]=0;
    int relaxations=V-1;
    while (relaxations--) {
      for (auto edge: edges) {
        if (
            dist[edge.src] != INT_MAX && // no need to check on this case
            dist[edge.dest] > dist[edge.src] + edge.weight) {
          dist[edge.dest] = dist[edge.src] + edge.weight;
          parent[edge.dest]=edge.src;
        }
      }
    }

    deque<int> path;
    int u = tgt;
    do {
      path.push_front(u);
      u=parent[u];
    } while(u!=src);
    path.push_front(src);

    return path;
  }
};



#include "test/09-g-bellman-ford-path.h"
int main() { run_tests(); return 0; }