#include <vector>
#include <unordered_map>

using namespace std;


void DFS(vector<vector<int>> &G,
  vector<pair<int, int>> &tree_edges,
  vector<pair<int, int>> &forward_edges,
  vector<pair<int, int>> &back_edges,
  vector<pair<int, int>> &cross_edges,
  vector<bool> &visited,
  vector<int> &pre,
  vector<int> &post,
  int &cnt,
  int node) {
    pre[node]=cnt++;
    visited[node]=true;

    for (auto nei: G[node]) {
      if (!visited[nei]) {  // not visited
        // 1. TREE-EDGE:
        // - part of the DFST
        //   (Depth First Spanning Tree)
        tree_edges.push_back(make_pair(node, nei));
        DFS(G, tree_edges, forward_edges, back_edges, cross_edges,
          visited, pre, post, cnt, nei);
      } else { // special edges: one of fwd, back, or cross
        // 2. FORWARD-EDGE:
        // nei: started after, and finished already
        // - no need to compare with post[node], as it is obvious
        //   that it is still going on
        //   ie, still in this loop, node haven't yet updated it's post cnt
        if (pre[nei] > pre[node] && post[nei] != 0) {
          forward_edges.push_back(make_pair(node, nei));
        }
        // 3. BACKWARD-EDGE:
        // could have used in_stack bool set for this
        // but this can easily be emulated with timers,
        // in_stack means: (nei=target node)
        // - nei has started before
        // - nei is still going on (hasn't finished yet; ie in the stack)
        else if (pre[nei] < pre[node] && post[nei]==0) {
          back_edges.push_back(make_pair(node, nei));
        }
        // 4. CROSS-EDGES:
        // remaining cases. regarding timers, this will be:
        // - nei started and finished (both indices not zero)
        //    - thats the difference between backedge,
        //      ie it is not in_stack
        else {
          cross_edges.push_back(make_pair(node, nei));
        }
      }
    }
    post[node]=cnt++;
}

void solve(vector<vector<int>> &G,
  vector<pair<int, int>> &tree_edges,
  vector<pair<int, int>> &forward_edges,
  vector<pair<int, int>> &back_edges,
  vector<pair<int, int>> &cross_edges) {
    const int V = G.size();
    int cnt=0;
    vector<bool> visited(V, false);
    vector<int> pre(V, 0), post(V, 0);
    for (int i=0; i<V; i++) {
      if (!visited[i]) { // not visited
        DFS(G, tree_edges, forward_edges, back_edges, cross_edges, visited, pre, post, cnt, i);
      }
    }
}



#include "test/17.h"
int main() { run_tests(); return 0; }