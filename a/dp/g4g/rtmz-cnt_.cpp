#include <vector>
using namespace std;


int isBlocked(vector<vector<int>> maze, int i, int j) {
  return maze[i][j]==-1;
}

int solveBF(vector<vector<int>> maze, int i, int j) {
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();

  if (i==N-1 && j==M-1) { return 1; }

  int sum {};
  // try right
  if (j+1 < M && !isBlocked(maze, i, j+1)) {
    sum+=solveBF(maze, i, j+1);
  }

  // try down
  if (i+1 < N && !isBlocked(maze, i+1, j)) {
    sum+=solveBF(maze, i+1, j);
  }

  return sum;
}

int solve_mazeBF(vector<vector<int>> maze) {
  // EDGE CASES
  if (maze.empty() || maze[0].empty()) return 0; // empty grid
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();
  // blocked start/end positions
  if (isBlocked(maze, 0, 0) || isBlocked(maze, N-1, M-1)) return 0;

  return solveBF(maze, 0, 0);
}


// MMZ
int solveMMZ(vector<vector<int>> maze, int i, int j, vector<vector<int>> &mmz) {
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();

  if (i==N-1 && j==M-1) { return 1; }
  if (mmz[i][j]!=-1) return mmz[i][j];

  int sum {};
  // try right
  if (j+1 < M && !isBlocked(maze, i, j+1)) {
    sum+=solveMMZ(maze, i, j+1, mmz);
  }

  // try down
  if (i+1 < N && !isBlocked(maze, i+1, j)) {
    sum+=solveMMZ(maze, i+1, j, mmz);
  }

  mmz[i][j]=sum;
  return sum;
}

int solve_mazeMMZ(vector<vector<int>> maze) {
  // EDGE CASES
  if (maze.empty() || maze[0].empty()) return 0; // empty grid
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();

  vector<vector<int>> mmz(N, vector<int>(M, -1));

  // blocked start/end positions
  if (isBlocked(maze, 0, 0) || isBlocked(maze, N-1, M-1)) return 0;

  return solveMMZ(maze, 0, 0, mmz);
}



// BU
int solve_mazeBU(vector<vector<int>> maze) {
  // EDGE CASES
  if (maze.empty() || maze[0].empty()) return 0; // empty grid
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();

  // blocked start/end positions
  if (isBlocked(maze, 0, 0) || isBlocked(maze, N-1, M-1)) return 0;

  vector<vector<int>> tab(N, vector<int>(M, 0));

  tab[N-1][M-1]=1;
  for (int i=N-1; i>=0; i--) {
    for (int j=M-1; j>=0; j--) {
      // try left
      if (j+1 < M && !isBlocked(maze, i, j+1)) {
        tab[i][j]+=tab[i][j+1];
      }

      // try down
      if (i+1 < N && !isBlocked(maze, i+1, j)) {
        tab[i][j]+=tab[i+1][j];
      }
    }
  }

  return tab[0][0];
}


// BU+SP1
int solve_mazeOPT(vector<vector<int>> maze) {
  // EDGE CASES
  if (maze.empty() || maze[0].empty()) return 0; // empty grid
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();

  // blocked start/end positions
  if (isBlocked(maze, 0, 0) || isBlocked(maze, N-1, M-1)) return 0;

  vector<int> prev, cur(M, 0);
  cur[M-1]=1;

  for (int i=N-1; i>=0; i--) {
    for (int j=M-1; j>=0; j--) {
      // try left
      if (j+1 < M && !isBlocked(maze, i, j+1)) {
        cur[j]+=cur[j+1];
      }

      // try down
      if (i+1 < N && !isBlocked(maze, i+1, j)) {
        cur[j]+=prev[j];
      }
    }
    prev=cur;
    fill(cur.begin(), cur.end(), 0); // reset cur
  }

  return prev[0];
}


// BU+ in place
int solve_mazeIN_PLACE(vector<vector<int>> maze) {
  // EDGE CASES
  if (maze.empty() || maze[0].empty()) return 0; // empty grid
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();

  // blocked start/end positions
  if (isBlocked(maze, 0, 0) || isBlocked(maze, N-1, M-1)) return 0;

  maze[N-1][M-1]=1;

  for (int i=N-1; i>=0; i--) {
    for (int j=M-1; j>=0; j--) {
      if(isBlocked(maze, i, j)) continue;  // TRICKY

      // try left
      if (j+1 < M && !isBlocked(maze, i, j+1)) {
        maze[i][j]+=maze[i][j+1];
      }

      // try down
      if (i+1 < N && !isBlocked(maze, i+1, j)) {
        maze[i][j]+=maze[i+1][j];
      }
    }
  }

  return maze[0][0];
}


int solve_mazeDP_ALT(vector<vector<int>> maze) {
  const int N = maze.size();

  if (maze[0][0]==-1 || maze[N-1][N-1]==-1) return 0;

  // mark valid paths in first row/col.
  // when we find a -1 break, as we won't be able to move further down/right
  for (int j=0; j<N; j++) { if (maze[0][j]==0) maze[0][j]=1; else break; }
  // tricky: start from [1][0], as [0][0] was already covered
  for (int i=1; i<N; i++) { if (maze[i][0]==0) maze[i][0]=1; else break; }


  for (int i=1; i<N; i++) {
    for (int j=1; j<N; j++) {
      if (maze[i][j]==-1) continue;

      // valid paths: positives means valid paths..
      // path from top
      if (maze[i-1][j]>0) maze[i][j]+=maze[i-1][j];
      // path from left
      if (maze[i][j-1]>0) maze[i][j]+=maze[i][j-1];
    }
  }

  // print_maze(maze);

  return maze[N-1][N-1];
}



#include "test/rtmz-cnt.h"
int main() {
  run_tests("BF", solve_mazeBF);
  run_tests("MMZ", solve_mazeMMZ);
  run_tests("BU", solve_mazeBU);
  run_tests("OPT", solve_mazeOPT);
  run_tests("IN PLACE", solve_mazeIN_PLACE);  // if allowed to modify input arr
  run_tests("DP ALT", solve_mazeDP_ALT);      // complicated DP

  print_errors();
  return 0;
}