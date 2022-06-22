class Solution {
  void dfs(int V, vector<int> adj[],
           vector<bool> &visited, deque<int> &toposort, int i) {
    visited[i]=true;

    for (int nei: adj[i]) {
      if (!visited[nei]) dfs(V, adj, visited, toposort, nei);
    }

    toposort.push_front(i);
  }

 public:
  //Function to return list containing vertices in Topological order.
  vector<int> topoSort(int V, vector<int> adj[])
  {
    deque<int> toposort;
    vector<bool> visited(V, false);

    for (int i=0; i<V; i++) {
      if (!visited[i]) dfs(V, adj, visited, toposort, i);
    }

    vector<int> res;
    res.insert(res.begin(), toposort.begin(), toposort.end());
    // could have push_back to a vector (in DFS) and reverse it here:
    // reverse(toposort.begin(), toposort.end());

    return res;
  }
};