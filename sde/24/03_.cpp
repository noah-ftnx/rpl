vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
  const int E = adj.size();
  vector<int> dist(V, 1e8);
  dist[S]=0;

  auto relax_nodes = [&] () {
    for (int i=0; i<E; i++) { // each vertex
      // adjacent nodes are expanded:
      int from = adj[i][0];
      int to = adj[i][1];
      int cost = adj[i][2];

      if (dist[from]==1e8) continue;

      // // there's a shorter path to that node
      if (dist[from]+cost < dist[to]) {
        dist[to]=dist[from]+cost;
      }
    }
  };

  int times=V-1;
  while(times--) {
    relax_nodes();
  }
  return dist;
}
