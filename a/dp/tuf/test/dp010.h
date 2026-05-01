#ifndef INC_070__CPP_A_DP_TUF_TEST_010_H_
#define INC_070__CPP_A_DP_TUF_TEST_010_H_

#include <iostream>
#include <iomanip>

int prototype(vector<vector<int>> &grid);
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
  int result = function(maze);
  bool wrong = result != correct;
  _wrong|=wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << ": ways: "  << result  << endl;
}

void test1(fptr function) {
  vector<vector<int>> maze {
      {2, 1, 9},
      {5, 9, 9},
      {1, 1, 1}
  };
  test(function, "Maze 1", maze, 10);
}

void test2(fptr function) {
  vector<vector<int>> maze {
      {2, 10, 9},
      {5, 5, 9},
      {1, 3, 1}
  };
  test(function, "Maze 2", maze, 12);
}


void test3(fptr function) {
  vector<vector<int>> maze {
      {2, 1, 9},
      {6, 1, 6},
  };
  test(function, "Maze 3", maze, 10);
}


void run_tests(string msg, fptr function) {
  cout << msg << ":\n";
  test1(function);
  test2(function);
  test3(function);
  cout << endl;
}

void print_errors() {
  if (_wrong) cout << "[FAIL]\n";
  else cout << "[PASS] (all results).\n";
}

#endif  // INC_070__CPP_A_DP_TUF_TEST_010_H_
