class Solution {
  void bfs(vector<int> adj[], vector<bool> &visited, vector<int> &traversal, int start) {
    // we must visit each vertex once:
    // means we must push them only once to the queue
    // so we mark them then enqueue them!
    queue<int> q;
    q.push(start);
    visited[start]=true;

    while(!q.empty()) {
      int idx = q.front(); q.pop();
      // visit:
      traversal.push_back(idx);

      for (int nei: adj[idx]) {
        if (!visited[nei]) {
          q.push(nei);
          visited[nei]=true;
        }
      }
    }
  }

 public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    if (V==0) return {};

    vector<int> traversal;
    vector<bool> visited(V, false);

    bfs(adj, visited, traversal, 0);

    return traversal;
  }
};
