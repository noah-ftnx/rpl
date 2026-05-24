#ifndef INC_070__CPP_A_BT_TEST_REC_L19_H_
#define INC_070__CPP_A_BT_TEST_REC_L19_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool _wrong=false;

void print_vec(const vector<string> &paths) {
  cout << "{ ";
  for (auto path: paths) cout << '"' << path << "\" ";
  cout << "}";
}

void test(string name, vector<vector<int>> maze, vector<string> correct) {
  auto result = findPath(maze);
  bool wrong = correct!=result;
  _wrong|=wrong;
  cout << (wrong ? "[FAIL] " : "[PASS] ") << name;
  if (wrong) {
    cout << "\n  result:   ";
    print_vec(result);
    cout << "\n  expected: ";
    print_vec(correct);
  }
  cout << "\n";
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

void test3() {
  vector<vector<int>> maze {
      {1}};

  test("single open cell", maze, {""});
}

void test4() {
  vector<vector<int>> maze {
      {0}};

  test("single blocked cell", maze, {});
}

void test5() {
  vector<vector<int>> maze {
      {0, 1},
      {1, 1}};

  test("blocked start", maze, {});
}

void test6() {
  vector<vector<int>> maze {
      {1, 1},
      {1, 0}};

  test("blocked destination", maze, {});
}

void test7() {
  vector<vector<int>> maze {
      {1, 1},
      {1, 1}};

  test("2x2 all open", maze, {"DR", "RD"});
}

void test8() {
  vector<vector<int>> maze {
      {1, 1, 0},
      {0, 1, 0},
      {0, 1, 1}};

  test("single narrow path", maze, {"RDDR"});
}

void test9() {
  vector<vector<int>> maze {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1}};

  test("two border paths", maze, {"DDRR", "RRDD"});
}

void test10() {
  vector<vector<int>> maze {
      {1, 1, 1, 0},
      {1, 0, 1, 1},
      {1, 1, 1, 1},
      {0, 1, 0, 1}};

  test("multiple paths with turns", maze, {"DDRRRD", "DDRRURDD", "RRDDRD", "RRDRDD"});
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


#endif  // INC_070__CPP_A_BT_TEST_REC_L19_H_
