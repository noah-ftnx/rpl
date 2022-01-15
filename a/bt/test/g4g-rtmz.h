#ifndef RPL_A_BT_TEST_G3G_RTMZ_H_
#define RPL_A_BT_TEST_G3G_RTMZ_H_

#include <iostream>

bool _wrong=false;
void test(vector<vector<int>> maze, bool correct_a, vector<vector<int>> correct_b) {
  const int N = maze.size();
  vector<vector<int>> result_b(N, vector<int>(N));
  bool result_a = solve_maze(maze, result_b);

  if (!result_a) {
    cout << "No solution:\n";
  } else {
    cout << "Solution:\n";
    const int N = maze.size();
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) cout << result_b[i][j] << " ";
      cout << endl;
    }
  }

  if (result_a == correct_a && (!result_a || result_b == correct_b)) {
    cout << "Correct.\n";
  } else {
    _wrong=true;
    cout << " WRONG.\n";
  }
  cout << endl;
}

void test1() {
  cout << "Maze 1:\n";
  vector<vector<int>> maze
      {{1, 0, 0, 0},
       {1, 1, 0, 1},
       {0, 1, 0, 0},
       {1, 1, 1, 1}};

  vector<vector<int>> correct_b
      {{1, 0, 0, 0},
       {1, 1, 0, 0},
       {0, 1, 0, 0},
       {0, 1, 1, 1}};

  test(maze, true, correct_b);
}

void test2() {
  cout << "Maze 2:\n";
  vector<vector<int>> maze
      {{1, 0, 0, 0},
       {1, 0, 0, 1},
       {0, 1, 0, 0},
       {1, 1, 1, 1}};

  test(maze, false, {});
}



void run_tests() {
  test1();
  test2();

  if (_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_A_BT_TEST_G3G_RTMZ_H_
