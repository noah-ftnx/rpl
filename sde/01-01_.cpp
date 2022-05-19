void setZeroes(vector<vector<int>>& matrix) {
  auto cpy=matrix;
  const int n = matrix.size();
  const int m = matrix[0].size();
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (cpy[i][j]==0) {
        // zero column
        for (int x=0; x<n; x++) matrix[x][j]=0;
        // zero row
        for (int y=0; y<m; y++) matrix[i][y]=0;
      }
    }
  }
}
