#ifndef REPL_DS_10G_TEST_DIJ_PATH_H_
#define REPL_DS_10G_TEST_DIJ_PATH_H_

#include "input-spt.h"

deque<int> spt_path(vector<list<Edge>> G, int src, int target);
void print_result_path(int src, int tgt, deque<int> path) {
  static vector<string> cresult {
      "0",
      "0 1",
      "0 1 2",
      "0 1 2 3",
      "0 7 6 5 4",
      "0 7 6 5",
      "0 7 6",
      "0 7",
      "0 1 2 8"
  };

  cout << src << " -> " << tgt << ": ";
  for (auto p: path) cout << p << " ";
  cout << endl << "   cor: ";
  cout << cresult[tgt] << endl;
}

void test_path() {
  cout << "spt_path-dijkstra\n";
  const int src = 0;
  for (int tgt=0; tgt<V; tgt++) {
    auto path = spt_path(input_adj_list(), src, tgt);
    print_result_path(src, tgt, path);
  }
}

#endif //REPL_DS_10G_TEST_DIJ_PATH_H_
