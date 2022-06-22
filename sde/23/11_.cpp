class SolutionBFS {
  enum Color { unvisited, red, blue };

  bool bipartiteBFS(vector<vector<int>> &graph, vector<Color> &colors, int start) {
    queue<int> q;
    q.push(start);
    colors[start]=red;

    while(!q.empty()) {
      int idx = q.front(); q.pop();
      // paint neighbors w/ diff color
      for (int nei: graph[idx]) {
        if (colors[nei] == unvisited) {
          colors[nei]= colors[idx]==red? blue: red;
          q.push(nei);
        } else {
          // NOT a bipartite: a neighbor has the same color w/ idx
          if (colors[nei] == colors[idx]) return false;
        }
      }
    }

    return true; // so far it is a bipartite
  }

 public:
  bool isBipartite(vector<vector<int>>& graph) {
    if (graph.empty()) return true;

    const int V = graph.size();
    vector<Color> colors(V, unvisited);

    for (int i=0; i<V; i++) {
      if (colors[i]==unvisited) {
        if (!bipartiteBFS(graph, colors, i)) return false;
      }
    }

    return true;
  }
};