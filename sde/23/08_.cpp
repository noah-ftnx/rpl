class Solution {
 public:
  //Function to return list containing vertices in Topological order.
  vector<int> topoSort(int V, vector<int> adj[])
  {
    // find indegrees
    vector<int> indegree(V, 0);
    for (int i=0; i<V; i++)
      for (int nei: adj[i]) indegree[nei]++;
	        
    // graph entrypoints
    queue<int> q;
    for (int i=0; i<V; i++) if (indegree[i]==0) q.push(i);
	   
    vector<int> toposort;
    while(!q.empty()) {
      int vertex = q.front(); q.pop();
      toposort.push_back(vertex);
	       
      for (int nei: adj[vertex]) {
        if(--indegree[nei]==0) {
          q.push(nei);
        }
      }
    }
	   
    return toposort.size() == V? toposort : vector<int>();
  }
};