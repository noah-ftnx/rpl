#include <vector>

using namespace std;

void DFS(vector<vector<int>> &G, vector<bool> &visited,
  vector<int> &previsit, vector<int> &postvisit, int node, int &cnt) {
    visited[node]=true;
    previsit[node]=cnt++;

    for (int nei: G[node]) {
      if (!visited[nei])
        DFS(G, visited, previsit, postvisit, nei, cnt);
    }

    postvisit[node]=cnt++;
}

void solve(vector<vector<int>> &G,
  vector<int> &previsit, vector<int> &postvisit) {
  int V = G.size();
  vector<bool> visited(V, false);
  previsit.resize(V);
  postvisit.resize(V);

  int cnt=0;
  for (int i=0; i<V; i++) {
    if (!visited[i]) DFS(G, visited, previsit, postvisit, i, cnt);
  }
}



#include "test/16.h"
int main() { run_tests(); return 0; }