class Solution {
  struct Edge { int from, to, w; };
  struct EdgeCmp {
    bool operator()(Edge &a, Edge &b) {
      return a.w > b.w; // bigger weights will perc down
    }
  };

 public:
  //Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {

    priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
    for (int i=0; i<V; i++) {
      for (auto edges: adj[i]) {
        int to=edges[0];
        int weight=edges[1];
        // WORKS: Probably: as it's not a local object
        // eg not e=Edge(...); and then assign.
        pq.push({i, to, weight});
      }
    }

    // each node is parent of itself
    vector<int> par(V, -1);

    auto cfind = [&](int v) {
      int u=v;
      while(par[u]>=0) { // find the parent
        u=par[u];
      }

      // collapse parents
      while(v!=u) {
        int t=par[v];
        par[v]=u;
        v=t;
      }

      return u;
    };

    auto wunion = [&](int u, int v) {
      if (u<v) { // u becomes parent
        par[u]+=par[v];
        par[v]=u;
      } else {
        par[v]+=par[u];
        par[u]=v;
      }
    };


    int sum = 0;
    while(!pq.empty()) {
      auto mn = pq.top(); pq.pop();

      int pfrom = cfind(mn.from);
      int pto = cfind(mn.to);
      if (pfrom != pto) {
        // only then we can take them
        sum+=mn.w;
        wunion(pfrom, pto);
        // could have store the spt here:
        // in a vector: using {mn.from, mn.to}
      }
    }
    return sum;
  }
};