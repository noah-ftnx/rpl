class Solution {

    bool cycleBFS(vector<int> adj[],
                  vector<bool> &enqueued, queue<pair<int, int>> &q) {
        while(!q.empty()) {
            auto pair=q.front(); q.pop(); // node we came from
            int node=pair.first;
            int from=pair.second;

            for (int nei: adj[node]) {
                if (enqueued[nei]) { // already scheduled
                    if (nei != from) return true; // not where we came from -> cycle!
                    // else: all is good (ignore)
                } else {
                    q.push(make_pair(nei, node));
                    enqueued[nei]=true;
                }
            }
        }
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {

        vector<bool> enqueued(V, false);
        queue<pair<int, int>> q; // pair: node, from
        for (int i=0; i<V; i++) {
            // do traversal on each component
            if (!enqueued[i]) {
                q.push({i, -1}); // -1: starting point
                enqueued[i]=true;
                if (cycleBFS(adj, enqueued, q)) return true;
            }
        }
        return false; // no cycles
    }
};