#ifndef RPL_DS_10G_TEST_09_G_BELLMAN_FORD_H_
#define RPL_DS_10G_TEST_09_G_BELLMAN_FORD_H_

#include <iostream>
#include <iomanip>

Graph* input1() {
  int V = 5;
  int E = 8;
  Graph *graph = new Graph(V, E);

  graph->edges[0].src = 0;
  graph->edges[0].dest = 1;
  graph->edges[0].weight = -1;

  graph->edges[1].src = 0;
  graph->edges[1].dest = 2;
  graph->edges[1].weight = 4;

  graph->edges[2].src = 1;
  graph->edges[2].dest = 2;
  graph->edges[2].weight = 3;

  graph->edges[3].src = 1;
  graph->edges[3].dest = 3;
  graph->edges[3].weight = 2;

  graph->edges[4].src = 1;
  graph->edges[4].dest = 4;
  graph->edges[4].weight = 2;

  graph->edges[5].src = 3;
  graph->edges[5].dest = 2;
  graph->edges[5].weight = 5;

  graph->edges[6].src = 3;
  graph->edges[6].dest = 1;
  graph->edges[6].weight = 1;

  graph->edges[7].src = 4;
  graph->edges[7].dest = 3;
  graph->edges[7].weight = -3;

  return graph;
}

void test(Graph* graph, int src, vector<int> correct) {
  auto result = graph->BellmanFord(src);
  cout << "NODE: ";
  for (int i=0; i<result.size(); i++) cout << setw(3) <<  i << " "; cout << endl;
  cout << "COST: ";
  for (auto cost: result) cout << setw(3) << cost << " ";
  cout << (correct!=result? " (WRONG)": "") << endl;

}

void run_tests() {
  test(input1(), 0, {0, -1, 2, -2, 1});
}

#endif  // RPL_DS_10G_TEST_09_G_BELLMAN_FORD_H_
