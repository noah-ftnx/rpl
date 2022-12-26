class Solution
{
public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Khans algo
        // BFS: add edges w/ zero indegree to a worklist
        // when visiting: decrease indegrees
        vector<int> indegree(V, 0);
        for (int from=0; from<V; from++) {
            for (int to: adj[from]) { // neighbor
                indegree[to]++;
            }
        }

        queue<int> worklist;
        for (int i=0; i<V; i++) {
            if (indegree[i]==0) worklist.push(i);
        }

        vector<int> order; // will be IN CORRECT ORDER!

        // BFS
        while (!worklist.empty()) {
            int node = worklist.front(); worklist.pop();
            order.push_back(node);

            for (int nei: adj[node]) {
                // decrease indegree (satisfied that contraint)
                if (--indegree[nei]==0) {
                    worklist.push(nei);
                }
            }
        }

        // topo order size doesn't match? -> cycle
        if(order.size() != V) return {}; // empty ordering

        return order; // no it's not rev anymore!
    }
};