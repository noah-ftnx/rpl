#include <deque>
#include <vector>
using namespace std;

class Solution {

  void tsortDFS(int V, vector<int> adj[], vector<bool> &visited, deque<int> &toposort, int v) {
    visited[v]=true;

    for (int nei: adj[v]) {
      if (!visited[nei]) tsortDFS(V, adj, visited, toposort, nei);
    }

    toposort.push_front(v);
  }

  deque<int> topologicalSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    deque<int> res;
    for (int i=0; i<V; i++) {
      if (!visited[i]) tsortDFS(V, adj, visited, res, i);
    }
    return res;
  }

  vector<vector<int>> getTranspose(int V, vector<int> adj[]) {
    vector<vector<int>> adj_tr(V, vector<int>());

    for (int from=0; from<V; from++) {
      for (int to: adj[from]) {
        // was from -> to
        // create the reverse edge (to -> from)
        adj_tr[to].push_back(from);
      }
    }
    return adj_tr;
  }

  void trDFS(int V, vector<vector<int>> &adj_tr, vector<bool> &visited, int v) {
    visited[v]=true;

    for (int nei: adj_tr[v]) {
      if (!visited[nei]) trDFS(V, adj_tr, visited, nei);
    }
  }


  int countSCC(int V, vector<vector<int>> &adj_tr, deque<int> &toposort) {
    vector<bool> visited(V, false);
    int cnt=0;
    for (int i=0; i<V; i++) {
      int vertex = toposort[i];
      if (!visited[vertex]) {
        trDFS(V, adj_tr, visited, vertex);
        cnt++;
      }
    }
    return cnt;
  }

 public:
  //Function to find number of strongly connected components in the graph.
  int kosaraju(int V, vector<int> adj[])
  {
    // step 1
    auto toposort = topologicalSort(V, adj);

    // step 2:
    auto adj_tr = getTranspose(V, adj);

    // step 3: DFS on the transpose
    return countSCC(V, adj_tr, toposort);
  }
};