class Solution {

  int DFS(int V, vector<int>adj[],
          vector<bool> &visited, vector<bool> &isAP,
          int latestTime, vector<int> &times, int cur, int par) {
    visited[cur]=true;
    times[cur]=++latestTime;

    int mnTime=times[cur];
    int child=0;
    for (int nei: adj[cur]) {
      if (nei == par) continue;

      if (!visited[nei]) {
        child++;
        int mnInner=DFS(V, adj, visited, isAP, latestTime, times, nei, cur);
        // at most, mnInner can reach ourselves
        // it cannot reach a vertex before us
        // meaning: removing cur will create more components
        // ==> CUR IS AN AP
        if (par != -1 && mnInner >= times[cur]) isAP[cur]=true;

        mnTime=min(mnTime, mnInner);
      }

      mnTime=min(mnTime, times[nei]);
    }

    // if par and child GT 1: root isAP
    if (par==-1 && child>1) isAP[cur]=true;

    return mnTime; // the node that we can reach at most
  }

 public:
  vector<int> articulationPoints(int V, vector<int> adj[]) {
    vector<bool> visited(V, false), isAP(V, false);
    vector<int> times(V);
    int latestTime=0;

    DFS(V, adj, visited, isAP, latestTime, times, 0, -1);

    vector<int> res;
    for (int i=0; i<V; i++) if (isAP[i]) res.push_back(i);
    return res;
  }
};