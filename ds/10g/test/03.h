#ifndef RPL_DS_10G_TEST_03_H_
#define RPL_DS_10G_TEST_03_H_

#include <iostream>

void run_tests () {
  cout << "MST: undirected graph:\n";
  vector<Edge> edges(input_mst());

  auto mst = MST(edges, V);
  for (auto e: mst) {
    cout << "(" << e.src << "," << e.tgt << "): " << e.w << endl;
  }

  cout << endl;

  cout << "Correct output:\n"
       << "(1,6) 5\n"
       << "(3,4) 8\n"
       << "(2,7) 10\n"
       << "(2,3) 12\n"
       << "(4,5) 16\n"
       << "(5,6) 20\n";
}

#endif  // RPL_DS_10G_TEST_03_H_
