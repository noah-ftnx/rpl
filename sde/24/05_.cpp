class SolutionG4G {
  struct Edge { int from, to, w; };
  struct EdgeCmp {
    bool operator()(Edge a, Edge b) {
      return a.w > b.w; // bigger weight will perc down (MinHeap on w/weight)
    }
  };
 public:
  //Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    int start=0; // starting idx

    // avoid picking an edge that leads to a node that was already visited
    vector<bool> visited(V, false);
    priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
    for (auto edge: adj[start]) { // add edges of the starting vertex
      int to=edge[0];
      int w=edge[1];
      pq.push({start, to, w});
    }

    visited[start]=true;

    int visitedVertices=0, mstWeight=0;
    while (!pq.empty() && visitedVertices<=V) {
      auto tp = pq.top(); pq.pop();

      if (visited[tp.to]) continue;

      mstWeight+=tp.w;
      visitedVertices++;
      visited[tp.to]=true;

      for (auto edge: adj[tp.to]) { // add the new edges
        int from = tp.to; // from that vertex to it's neighbors
        int to=edge[0];
        int w=edge[1];
        if (visited[to]) continue; // avoid
        pq.push({from, to, w});
      }
    }
    return mstWeight;
  }
};



#include <vector>
#include <queue>
using namespace std;
vector<Edge> replMST(vector<Edge> edges, int V) {

  const int V=7;
  const int E=9;

  struct Edge {
    int from;
    int to;
    int w; // weight
  };

  struct EdgeCmp {
    bool operator()(Edge a, Edge b) {
      return a.w > b.w; // bigger weights will perc down
    }
  };

  // must create an AL for fast access
  // usually this exists. when it does, and the graph
  // is connected, we can use Prim's directly.
  vector<vector<Edge>> AL(V, vector<Edge>());
  for (auto edge: edges) {
    AL[edge.from].push_back(edge);
  }

  priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
  vector<bool> visited(V, false);

  // add edges of start vertex
  int start=0;
  visited[start]=true;
  for (auto edge: AL[start]) {
    pq.push(edge);
  }

  vector<Edge> res;
  while(!pq.empty() && res.size() < V) {
    auto tp = pq.top(); pq.pop();
    visited[tp.to]=true;
    // add it to result:
    res.push_back(tp);

    for (auto edge: AL[tp.to]) {
      if (visited[edge.to]) continue;
      pq.push(edge);
    }
  }
  return res;
}