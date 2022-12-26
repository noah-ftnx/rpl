class Solution {

    // find cycles in curr dfs
    // might NOT be a component
    // - we start DFS from any non-visited node
    // - that node might not be the "entry-point" of the component
    // - we haven't topo-sorted the G first
    bool cycleDFS(vector<int> adj[],
                  vector<bool> &visited, vector<bool> &in_stack,
                  int node) {
        // VISIT
        visited[node]=true;
        in_stack[node]=true;

        // VISIT NEIG
        for (int nei: adj[node]) {
            if (visited[nei]) { // already visited: maybe cycle
                // nei is an actual back-edge (loop)
                if (in_stack[nei]) return true;
                // else: not a loop
            } else { // not visited
                if (cycleDFS(adj, visited, in_stack, nei)) return true; // cycle
            }
        }

        in_stack[node]=false;  // remove from stack

        return false; // no cycle (in this cmp)
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        // cycle, undirected, DFS
        for (int i=0; i<V; i++) { // each component
            vector<bool> in_stack(V, false);
            // found cycle in a particular component
            if (cycleDFS(adj, visited, in_stack, i)) return true;
        }

        return false; // no cycles (in any cmp)
    }
};