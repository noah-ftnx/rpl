class SolutionDFS {
  void DFS(vector<vector<char>>& grid, int i, int j, int N, int M) {
    grid[i][j]='2'; // mark as visited

    vector<int> X {-1, 1,  0, 0};
    vector<int> Y { 0, 0, -1, 1};

    // move to all 4 directions
    for (int d=0; d<4; d++) {
      int x = i+X[d];
      int y = j+Y[d];

      if (x>=0 && x<N && y>=0 && y<M) { // in bounds
        if (grid[x][y]=='1') DFS(grid, x, y, N, M);
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    const int N = grid.size();
    const int M = grid[0].size();
    int islands=0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (grid[i][j]=='1') {
          DFS(grid, i, j, N, M);
          islands++;
        }
      }
    }

    // fix grid
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (grid[i][j]=='2') grid[i][j]='1';
      }
    }
    return islands;
  }
};


class SolutionBFS {
  void BFS(vector<vector<char>>& grid, int startX, int startY, int N, int M) {

    queue<pair<int, int>> q;
    q.push({startX, startY});
    grid[startX][startY]='2';

    // offsets
    vector<int> X {1, -1,  0, 0};
    vector<int> Y {0,  0, -1, 1};

    while(!q.empty()) {
      // pop and visit
      auto p = q.front(); q.pop();
      int i = p.first, j=p.second;

      // push valid children..
      for (int d=0; d<4; d++) {
        // neighbouring positions
        int x=i+X[d];
        int y=j+Y[d];

        if (x>=0 && x<N && y>=0 && y<M) { // valid
          if (grid[x][y]=='1') { // valid land neighbor
            grid[x][y]='2';
            q.push({x, y});
          }
        }
      }
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int N = grid.size();
    int M = grid[0].size();


    int islands=0;
    for (int i=0; i<N; i++) {
      for (int j=0; j<M; j++) {
        if (grid[i][j]=='1') { // land
          BFS(grid, i, j, N, M);
          islands++;
        }
      }
    }

    // fixup grid
    for (int i=0; i<N; i++)
      for (int j=0; j<M; j++)
        if (grid[i][j]=='2') grid[i][j]='1';

    return islands;
  }
};