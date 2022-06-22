class Solution {
  bool DFS(int V, vector<int> adj[], vector<bool> visited, int idx, int par) {
    visited[idx]=true;

    for (int nei: adj[idx]) {
      if (!visited[nei]) {
        // found a cycle recursively
        if (DFS(V, adj, visited, nei, idx)) return true;
      } else {
        if (nei != par) return true; // CYCLE
      }
    }
    return false;
  }

 public:
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i=0; i<V; i++) {
      if (DFS(V, adj, visited, i, -1)) return true;
    }

    return false;
  }
};