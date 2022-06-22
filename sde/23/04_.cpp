class Solution {
 private:
  bool cycleBFS(int V, vector<int> adj[], vector<bool> &visited, int idx) {
    queue<pair<int, int>> q;
    visited[idx]=true;
    q.push({idx, -1});
    while (!q.empty()) {
      auto p = q.front(); q.pop();
      int idx = p.first;
      int par = p.second; // parent

      for (int nei: adj[idx]) {
        if (!visited[nei]) {
          visited[nei]=true;
          q.push({nei, idx});
        } else {
          // reaching a visited node that is NOT from where we came from
          // (remember: undirected graph..)
          if (nei != par) return true; // CYCLE
        }
      }
    }

    return false;
  }

 public:
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i=0; i<V; i++) {
      if (!visited[i])  {
        if (cycleBFS(V, adj, visited, i)) return true;
      }
    }

    return false;
  }
};