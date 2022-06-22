class Solution {
  enum Color { unvisited, red, blue };
  bool bipartiteDFS(vector<vector<int>>& graph, vector<Color> &colors, int i, Color prevColor) {
    Color color = prevColor==red? blue : red; // opposite color
    colors[i]=color;

    for (int nei: graph[i]) {
      if (colors[nei]==unvisited) {
        if (!bipartiteDFS(graph, colors, nei, color)) return false;
      } else {
        // it was already colored
        // if it's the same color with cur node then it's NOT a bipartite
        if (colors[nei] == colors[i]) return false;
      }
    }

    return true; // current component is bipartite
  }

 public:
  bool isBipartite(vector<vector<int>>& graph) {
    if (graph.empty()) return true;

    const int V = graph.size();
    vector<Color> colors(V, unvisited);

    for (int i=0; i<V; i++) { // check each component
      if (colors[i]==unvisited && !bipartiteDFS(graph, colors, i, blue)) return false;
    }

    return true;
  }
};
