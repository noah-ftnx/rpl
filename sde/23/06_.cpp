class Solution {
  bool cycleDFS(int V, vector<int> adj[],
                vector<bool> &visited, vector<bool> &in_stack, int i) {
    visited[i]=in_stack[i]=true;
        
    for (int nei: adj[i]) {
      if (!visited[nei]) {
        if (cycleDFS(V, adj, visited, in_stack, nei)) return true;
      } else {
        if (in_stack[nei]) return true; // CYCLE (back-edge)
      }
    }

    in_stack[i]=false;
    return false;
  }
    
 public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> in_stack(V, false);
    for (int i=0; i<V; i++) {
      if (!visited[i] && cycleDFS(V, adj, visited, in_stack, i)) return true;
    }
        
    return false;
  }
};