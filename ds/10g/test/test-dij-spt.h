#ifndef REPL_DS_10G_TEST_DIJ_SPT_H_
#define REPL_DS_10G_TEST_DIJ_SPT_H_

#include "input-spt.h"
#include <iomanip>

void print_result_spt(vector<int> result) {
  const vector<int> correct {0,4,12,19,21,11,9,8,14};

  for (int i=0; i<V; i++) {
    cout << i << "\t" << setw(2)
         << result[i] << " | " << correct[i] << endl;
  }

   cout << endl << (result!=correct?"WRONG.":"Correct.") << endl;
}


void run_tests() {
  cout << "dijkstra: spt: priority-queue\n";
  auto dist = spt(input_adj_list(), 0);
  print_result_spt(dist);
}


#endif //REPL_DS_10G_TEST_DIJ_SPT_H_
