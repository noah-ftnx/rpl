#ifndef RPL_A_BT_G4G_GCOL_H_
#define RPL_A_BT_G4G_GCOL_H_

#include <iostream>

void test(vector<vector<bool>> graph, int m, vector<int> correct_a, bool correct_b) {
  vector<int> result_a;
  bool result_b = color_graph(graph, m, result_a);

  if (!result_b) {
    cout << "Graph cannot be colored:";
  } else {
    cout << "Coloring:";
    for (auto c: result_a) cout << " " << c;
    cout << ": ";
  }

  bool wrong = !((correct_b == result_b) && (correct_a == result_a || correct_b==false));

  cout << (wrong?" WRONG":" Correct") << ".\n";
}

void test1() {
  vector<vector<bool>> graph =
      {{0, 1, 1, 1},
       {1, 0, 1, 0},
       {1, 1, 0, 1},
       {1, 0, 1, 0}};
  int m = 3;

  test(graph, m, {1, 2, 3, 2}, true);
}

void test2() {
  vector<vector<bool>> graph =
      {{1, 1, 1, 1},
       {1, 1, 1, 1},
       {1, 1, 1, 1},
       {1, 1, 1, 1}};
  int m = 3;

  test(graph, m, {}, false);
}

void run_tests() {
  test1();
  test2();
}


#endif  // RPL_A_BT_G4G_GCOL_H_
