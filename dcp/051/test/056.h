#ifndef RPL_DCP_051_TEST_056_H_
#define RPL_DCP_051_TEST_056_H_

#include <iostream>
#include <iomanip>

void test(vector<vector<int>> graph, int k, bool correct) {
  vector<int> result_a;
  bool result = color_graph(graph, k);

  string msg = "Graph can";
  if (result) msg += "not";
  msg+=" be colored.";

  bool wrong = correct != result;
  cout << setw(25) << msg << (wrong?" WRONG":" Correct") << ".\n";
}

void test1() {
  vector<vector<int>> graph =
      {{0, 1, 1, 1},
       {1, 0, 1, 0},
       {1, 1, 0, 1},
       {1, 0, 1, 0}};
  int m = 3;

  test(graph, m, true);
}


void test2() {
  vector<vector<int>> graph =
      {
          {0, 1, 1, 1},
          {1, 0, 1, 1},
          {1, 1, 0, 1},
          {1, 1, 1, 0}
      };

  int m = 3;

  test(graph, m, false);
}

void test3() {
  vector<vector<int>> graph =
      {
          {0, 1, 1, 1},
          {1, 0, 1, 1},
          {1, 1, 0, 1},
          {1, 1, 1, 0}
      };

  int m = 4;

  test(graph, m, true);
}


void test4() {
  vector<vector<int>> graph =
      {{1, 1, 1, 1},
       {1, 1, 1, 1},
       {1, 1, 1, 1},
       {1, 1, 1, 1}};
  int m = 3;

  test(graph, m, false);
}

void run_tests() {
  test1();
  test2();
  test3();
  test4();
}

#endif  // RPL_DCP_051_TEST_056_H_
