#ifndef INC_070__CPP_DCP_051_TEST_072_H_
#define INC_070__CPP_DCP_051_TEST_072_H_

#include <iostream>

bool _wrong=false;
void test(string nodes, list<pair<int, int>> edges, int correct) {
  Graph g(nodes, edges);
  int result= g.solve();

  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << "MSG: "<< result << (wrong? " (WRONG)": "") << endl;
}

void run_tests() {

  test("ABACA", {{0, 1}, {0, 2}, {2, 3}, {3, 4}}, 3);
  test("A", {{0, 0}}, -1);
  test("ABACA", {{0, 1}, {1, 2}, {2, 3}, {4, 0}}, 3);
  test("ABBBB", {{0, 1}, {1, 2}, {2, 3}, {4, 0}}, 4);
  test("BAA", {{0, 1}, {0, 2}}, 1);
  test("ABCB", {{0,2},{1,2},{2,3}}, 2);
  test("GBFDEFFFGGAABBFFG", {{0, 1},{1, 2},{1, 3},{1, 4},{1, 5},{4, 6},{4, 7},{6, 8},{8, 9},{0, 10},{0, 11},{11, 12},{12, 13},{5, 14},{14, 15},{9,16}}, 4);
}

#endif  // INC_070__CPP_DCP_051_TEST_072_H_