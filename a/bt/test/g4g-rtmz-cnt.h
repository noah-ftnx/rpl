#ifndef RPL_A_BT_TEST_G3G_RTMZ_CNT_H_
#define RPL_A_BT_TEST_G3G_RTMZ_CNT_H_

#include <iostream>

bool _wrong=false;
void test(vector<vector<int>> maze, int correct) {
  const int N = maze.size();
  int result = solve_maze(maze);
  cout << "ways: " << result << (result != correct? " (WRONG)": " correct.") << endl;
}

void test1() {
  cout << "Maze 1:\n";
  vector<vector<int>> maze
      {{0,  0, 0, 0},
       {0, -1, 0, 0},
       {-1, 0, 0, 0},
       {0,  0, 0, 0}};

  test(maze, 4);
}

void test2() {
  cout << "Maze 2:\n";
  vector<vector<int>> maze
      {{0,  0, 0, 0},
       {0, -1, -1, 0},
       {-1, 0, 0, 0},
       {0,  0, 0, 0}};

  test(maze, 1);
}



void run_tests() {
  test1();
  // test2();

  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_A_BT_TEST_G3G_RTMZ_CNT_H_
