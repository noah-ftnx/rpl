class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // Khan's Algorithm

        // find indegree for each node
        vector<int> indegree(V, 0);
        for (int from=0; from<V; from++) {
            for (int to: adj[from]) {
                // edge: from -> to
                // (an incoming edge for to)
                indegree[to]++;
            }
        }

        // do BFS for all indegrees that are zero
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i]==0) q.push(i);
        }

        int visited=0;
        while(!q.empty()) {
            int node=q.front(); q.pop();
            visited++;

            for (int nei: adj[node]) {
                // decrease indegree
                // when it becomes zero: enqueue
                if (--indegree[nei]==0) {
                    q.push(nei);
                }
            }
        }
        return V!=visited;
    }
};