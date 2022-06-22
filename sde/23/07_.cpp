class Solution {
 public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    // find indegrees
    vector<int> indegree(V, 0);
    for (int i=0; i<V; i++)
      for (int nei: adj[i]) indegree[nei]++;

    queue<int> q;
    for (int i=0; i<V; i++) if (indegree[i]==0) q.push(i);

    int cnt=0;
    while(!q.empty()) {
      int vertex = q.front();
      q.pop(); cnt++; // total items in the queue must be |V|

      for (int nei: adj[vertex]) {
        if(--indegree[nei]==0) q.push(nei);
      }
    }
    return cnt != V;
  }
};