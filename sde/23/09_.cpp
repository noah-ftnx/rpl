class Solution {
    bool toposortDFS(int V, vector<int> adj[],
                     vector<bool> &visited,
                     vector<bool> &in_stack,
                     deque<int> &toposort, int i) {
        visited[i]=true;
        in_stack[i]=true;

        for (int nei: adj[i]) {
            if (visited[nei]) {
                if (in_stack[nei]) return true; // cycle detected (back-edge)
            } else {
                if (toposortDFS(V, adj, visited, in_stack, toposort, nei)) return true; // cycle
            }
        }

        in_stack[i]=false;
        toposort.push_front(i);

        return false;
    }

public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        deque<int> toposort;
        vector<bool> visited(V, false);

        for (int i=0; i<V; i++) {
            vector<bool> in_stack(V, false);
            if (!visited[i]) {
                if(toposortDFS(V, adj, visited, in_stack, toposort, i)) return {}; // cycles
            }
        }

        vector<int> res(toposort.begin(), toposort.end());

        // could have push_back to a vector (in DFS) and reverse it here:
        // reverse(toposort.begin(), toposort.end());

        return res;
    }
};