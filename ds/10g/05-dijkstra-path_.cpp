#include <list>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
  int to;
  int w;
};

struct EdgeCmp {
  bool operator()(const Edge& a, const Edge& b) {
    return a.w > b.w; // MinHeap: perc down higher values
  }
};

deque<int> spt_path(vector<list<Edge>> G, int src, int target) {
  const int V=G.size();
  // here Edge is: to: vertex: w: total weight from src
  priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
  vector<int> dist(V, INT_MAX);
  vector<bool> visited(V, false);
  vector<int> parent(V, -1);

  pq.push({src, 0});
  dist[src]=0;
  while (!pq.empty() && !visited[target]) {
    auto min_vertex = pq.top(); pq.pop(); // logn
    visited[min_vertex.to]=true;
    // relax: update neighbors of min_v
    for (auto n: G[min_vertex.to]) { // E
      if (!visited[n.to] && dist[n.to] > dist[min_vertex.to] + n.w) {
        dist[n.to]=dist[min_vertex.to] + n.w;
        pq.push({n.to, dist[n.to]}); // logn
        parent[n.to]=min_vertex.to;
      }
    }
  }

  // construct the path
  deque<int> path;
  int v = target;
  while(v!=src) {
    path.push_front(v);
    v=parent[v];
  }
  path.push_front(src);

  return path;
}



#include "test/test-dij-path.h"
int main() { run_tests(); }
