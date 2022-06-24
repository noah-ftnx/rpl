class SolutionG4G {
 public:
  void shortest_distance(vector<vector<int>>&matrix) {
    if (matrix.empty()) return;

    const int V = matrix.size();
    for (int k=0; k<V; k++) {
      for (int i=0; i<V; i++) { // from
        for (int j=0; j<V; j++) { // to
          if (i==j) continue;
          // not a valid path yet
          if (matrix[i][k] == -1 || matrix[k][j]==-1) continue;

          // cost through k: (the node that we are checking)
          int cost = matrix[i][k]+matrix[k][j];
          // if there wasn't a direct path
          // or if it's cheaper to go through k than from i,j, then relax edges
          if (matrix[i][j]==-1 || cost < matrix[i][j]) matrix[i][j]=cost;
        }
      }
    }
  }
};


int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
  const int N = n+1;
  // create a 2D Matrix
  vector<vector<int>> matrix(N, vector<int>(N, 1e9));

  for (int i=0; i<m; i++) {
    int from = edges[i][0];
    int to = edges[i][1];
    int weight = edges[i][2];

    matrix[from][to]=weight;
  }

  for (int d=0; d<N; d++) matrix[d][d]=0; // diagonal: from src to src

  for (int k=1; k<N; k++) {
    // try to reach each node faster through k

    for (int i=1; i<N; i++) {
      for (int j=1; j<N; j++) {
        if (i==j) continue;

        // not relaxed yet, so no point continuing..
        if (matrix[i][k] == 1e9 ||
            matrix[k][j]==1e9) continue;

        int costThroughK = matrix[i][k]+matrix[k][j];
        matrix[i][j]=min(matrix[i][j], costThroughK);
      }
    }
  }
  return matrix[src][dest];
}