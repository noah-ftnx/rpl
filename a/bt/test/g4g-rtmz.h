#ifndef RPL_A_BT_TEST_G3G_RTMZ_H_
#define RPL_A_BT_TEST_G3G_RTMZ_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool _wrong=false;

void print_matrix(const vector<vector<int>> &mat) {
  for (auto row: mat) {
    cout << "  ";
    for (auto cell: row) cout << cell << " ";
    cout << "\n";
  }
}

void test(string name, vector<vector<int>> maze,
          bool correct_a, vector<vector<int>> correct_b) {
  const int N = maze.size();
  vector<vector<int>> result_b(N, vector<int>(N));
  bool result_a = solve_maze(maze, result_b);

  bool ok = result_a == correct_a && (!result_a || result_b == correct_b);
  _wrong |= !ok;
  cout << (ok ? "[PASS] " : "[FAIL] ") << name << ": Result: "
       << result_a << " Expected: " << correct_a << "\n";
  if (!ok) {
    cout << "result solution:\n";
    print_matrix(result_b);
    cout << "expected solution:\n";
    print_matrix(correct_b);
  }
}

void test1() {
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

  test("Maze 1", maze, true, correct_b);
}

void test2() {
  vector<vector<int>> maze
      {{1, 0, 0, 0},
       {1, 0, 0, 1},
       {0, 1, 0, 0},
       {1, 1, 1, 1}};

  test("Maze 2", maze, false, {});
}

void test3() {
  test("single open cell", {{1}}, true, {{1}});
}

void test4() {
  test("single blocked cell", {{0}}, false, {});
}

void test5() {
  test("2x2 all open",
      {{1, 1},
       {1, 1}},
      true,
      {{1, 1},
       {0, 1}});
}

void test6() {
  test("2x2 right blocked",
      {{1, 0},
       {1, 1}},
      true,
      {{1, 0},
       {1, 1}});
}

void test7() {
  test("2x2 down blocked",
      {{1, 1},
       {0, 1}},
      true,
      {{1, 1},
       {0, 1}});
}

void test8() {
  test("destination blocked",
      {{1, 1},
       {1, 0}},
      false,
      {});
}

void test9() {
  test("right-first path",
      {{1, 1, 1},
       {0, 0, 1},
       {1, 1, 1}},
      true,
      {{1, 1, 1},
       {0, 0, 1},
       {0, 0, 1}});
}

void test10() {
  test("down then right path",
      {{1, 0, 1},
       {1, 1, 1},
       {0, 0, 1}},
      true,
      {{1, 0, 0},
       {1, 1, 1},
       {0, 0, 1}});
}

void run_tests() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();

  cout << (_wrong ? "[FAIL]\n" : "[PASS]: ALL results.\n");
}

#endif  // RPL_A_BT_TEST_G3G_RTMZ_H_
