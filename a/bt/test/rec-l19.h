#ifndef INC_070__CPP_A_BT_TEST_REC_L19_H_
#define INC_070__CPP_A_BT_TEST_REC_L19_H_

#include <iostream>

bool _wrong=false;
void test(string name, vector<vector<int>> maze, vector<string> correct) {
  auto result = findPath(maze);
  bool wrong = correct!=result;
  _wrong|=wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name << ":\n";
  for (auto r: result) cout << r << endl;
  cout << endl;
}

void test1() {
  vector<vector<int>> maze {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};

  test("Maze 1", maze, {"DDRDRR", "DRDDRR"});
}

void test2() {
  vector<vector<int>> maze {
      {1, 0},
      {1, 0}};

  test("Maze 2", maze, {});
}


void run_tests() {
  test1();
  test2();

  if (_wrong) cout << "[FAIL]\n";
}


#endif  // INC_070__CPP_A_BT_TEST_REC_L19_H_
