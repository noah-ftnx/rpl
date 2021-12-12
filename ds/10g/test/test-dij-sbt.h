#ifndef REPL_DS_10G_TEST_DIJ_SBT_H_
#define REPL_DS_10G_TEST_DIJ_SBT_H_

#include "input-spt.h"
#include <iomanip>

void print_result_spt(vector<int> dist) {
  vector<int> cr {0,4,12,19,21,11,9,8,14};

  for (int i=0; i<V; i++) {
    cout << i << "\t\t" << setw(2)
         << dist[i] << " | " << cr[i] <<
         ((dist[i]!=cr[i])?" (WRONG)":"") << endl;
  }
}

vector<int> spt(vector<list<Edge>> G, int src);
void test_spt() {
  cout << "dijkstra: spt: priority-queue\n";
  auto dist = spt(input_adj_list(), 0);
  print_result_spt(dist);
}



#endif //REPL_DS_10G_TEST_DIJ_SBT_H_
