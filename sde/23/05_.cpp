class Solution {

    // cycle in a particular component
    bool cycleDFS(vector<int> adj[], vector<bool> &visited,
                  int node, int from) {
        // VISIT
        visited[node]=true;

        // VISIT NEIGH (detect cycles)
        for (int nei: adj[node]) {
            if (visited[nei]) { // already visited: may have a cycle
                // not where we came from: nei visited from another path
                if (nei != from) return true; // cycle (just discovered!)
                // else: nei is where we just came from (undirected graph)
            } else { // not visited: go deeper
                if (cycleDFS(adj, visited, nei, node)) return true; // cycle
            }
        }
        return false; // no cycle (int 'node' component)
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i=0; i<V; i++) { // each component
            if (!visited[i]) {
                if (cycleDFS(adj, visited, i, -1)) return true;
            }
        }
        return false; // no cycle (in any component)
    }
};