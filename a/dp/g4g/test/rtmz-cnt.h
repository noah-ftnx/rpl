#ifndef RPL_A_BT_TEST_G3G_RTMZ_CNT_H_
#define RPL_A_BT_TEST_G3G_RTMZ_CNT_H_

#include <iostream>
#include <iomanip>

int prototype(vector<vector<int>> maze);
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
void test(fptr function, vector<vector<int>> maze, int correct) {
  const int N = maze.size();
  int result = function(maze);
  bool wrong = result != correct;
  _wrong|=wrong;
  cout << "ways: " << result << (wrong? " (WRONG)": " correct.") << endl;
}

void test1(fptr function) {
  cout << "Maze 1: ";
  vector<vector<int>> maze
      {{0,  0, 0, 0},
       {0, -1, 0, 0},
       {-1, 0, 0, 0},
       {0,  0, 0, 0}};

  test(function, maze, 4);
}

void test2(fptr function) {
  cout << "Maze 2: ";
  vector<vector<int>> maze
      {{0,  0, 0, 0},
       {0, -1, -1, 0},
       {-1, 0, 0, 0},
       {0,  0, 0, 0}};

  test(function, maze, 1);
}


void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test1(function);
  test2(function);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect (all results).\n";
}

#endif  // RPL_A_BT_TEST_G3G_RTMZ_CNT_H_
