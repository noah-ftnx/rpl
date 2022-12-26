class Solution { // G4G
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        if (V<=0) return {};

        // to visit each vertex once -> enqueue them once
        // otherwise: same node might be enqueued multiple times
        // (it is the neighbor of two graphs that we are currently visiting)
        vector<bool> enqueued(V, false);
        queue<int> q;
        q.push(0);
        enqueued[0]=true;

        vector<int> result;

        while(!q.empty()) {
            int vertex=q.front(); q.pop();
            result.push_back(vertex);

            for (int nei: adj[vertex]) {
                if (!enqueued[nei]) {
                    q.push(nei);
                    enqueued[nei]=true;
                }
            }
        }
        return result;
    }
};