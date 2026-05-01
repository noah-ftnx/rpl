#ifndef INC_070__CPP_A_DP_TUF_TEST_009_H_
#define INC_070__CPP_A_DP_TUF_TEST_009_H_

#include <iostream>
#include <iomanip>

int prototype(int n, int m, vector<vector<int>> &mat);
using fptr = decltype(prototype);

void print_maze(vector<vector<int>> maze) {
  const int N = maze.size();
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << setw(2) << maze[i][j] << " ";
    }
    cout << endl;
  }
}

bool _wrong=false;
void test(fptr function, string name, vector<vector<int>> maze, int correct) {
  const int N = (int) maze.size();
  const int M = (int) maze[0].size();
  int result = function(N, M, maze);
  bool wrong = result != correct;
  _wrong|=wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << ": ways: "  << result  << endl;
}

void test1(fptr function) {
  vector<vector<int>> maze
      {{0,  0, 0, 0},
       {0, -1, 0, 0},
       {-1, 0, 0, 0},
       {0,  0, 0, 0}};

  test(function, "Maze 1", maze, 4);
}

void test2(fptr function) {
  vector<vector<int>> maze
      {{0,  0, 0, 0},
       {0, -1, -1, 0},
       {-1, 0, 0, 0},
       {0,  0, 0, 0}};

  test(function, "Maze 2", maze, 1);
}


void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test1(function);
  test2(function);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS] (all results).\n";
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_009_H_
