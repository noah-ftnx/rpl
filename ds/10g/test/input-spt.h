#ifndef DATA_STRUCTURES_10_GRAPH_6_DIJKSTRA_INPUT_H_
#define DATA_STRUCTURES_10_GRAPH_6_DIJKSTRA_INPUT_H_

#include <iostream>
#include <deque>
#include <string>

const int V = 9;
vector<list<Edge>> input_adj_list() {
  vector<list<Edge>> g(9);

  auto addEdge = [&](int from, int to, int weight) {
    g[from].push_back({to, weight});
    g[to].push_back({from, weight});
  };

  addEdge(0, 1, 4);
  addEdge(0, 7, 8);
  addEdge(1, 7, 11);
  addEdge(7, 6, 1);
  addEdge(7, 8, 7);
  addEdge(1, 2, 8);
  addEdge(6, 8,6 );
  addEdge(8, 2, 2);
  addEdge(6, 5, 2);
  addEdge(2, 5, 4);
  addEdge(2, 3, 7);
  addEdge(3, 5, 14);
  addEdge(3, 4, 9);
  addEdge(5, 4, 10);

  return g;
}

#endif  // DATA_STRUCTURES_10_GRAPH_6_DIJKSTRA_INPUT_H_