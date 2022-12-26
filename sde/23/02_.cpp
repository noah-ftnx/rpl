class Solution {
    void dfs(vector<int> adj[],
             vector<bool> &visited, vector<int> &result, int node) {
        // VISIT
        visited[node]=true;
        result.push_back(node);

        // VISIT NEIGHBORS
        for (int nei: adj[node]) {
            if (!visited[nei]) dfs(adj, visited, result, nei);
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        if (V<=0) return {};

        vector<bool> visited(V, false);
        vector<int> result;
        dfs(adj, visited, result, 0);
        return result;
    }
};