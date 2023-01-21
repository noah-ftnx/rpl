#ifndef INC_070__CPP_DS_10G_TEST_16_H_
#define INC_070__CPP_DS_10G_TEST_16_H_

#include <iostream>
#include ".inc/check.h"
#include ".inc/to_string.h"

void addEdge(vector<vector<int>> &G, int from, int to) {
  G[from].push_back(to);
}

vector<vector<int>> _input_graph1() {
  const int V=6;
  vector<vector<int>> G(V);
  addEdge(G, 0, 1);
  addEdge(G, 0, 3);
  addEdge(G, 0, 2);
  addEdge(G, 1, 3);
  addEdge(G, 2, 4);
  addEdge(G, 2, 5);
  addEdge(G, 4, 0);
  addEdge(G, 4, 3);

  return std::move(G);
}

vector<vector<int>> _input_graph2() {
  const int V=5;
  vector<vector<int>> G(V);
  addEdge(G, 0, 1);
  addEdge(G, 0, 3);
  addEdge(G, 1, 2);
  addEdge(G, 3, 2);
  addEdge(G, 3, 4);
  
  return std::move(G);
}


vector<vector<int>> _input_graph3() {
  const int V=8;
  vector<vector<int>> G(V);
  addEdge(G, 0, 1);
  addEdge(G, 0, 2);
  addEdge(G, 1, 3);
  addEdge(G, 2, 4);
  addEdge(G, 3, 5);
  addEdge(G, 4, 3);
  addEdge(G, 4, 6);
  addEdge(G, 4, 7);
  addEdge(G, 5, 1);
  
  return std::move(G);
}


void test(vector<vector<int>> &graph, vector<int> c_pre, vector<int> c_post) {
  vector<int> previsit, postvisit;
  solve(graph, previsit, postvisit);
  // cout << "pre: " << to_string(previsit);


  if(!check_result("previsit", c_pre, previsit)) {
    cout << "found: " << to_string(previsit) << endl;;
  }
  if(!check_result("postvisit", c_post, postvisit)) {
    cout << "found: " << to_string(postvisit) << endl;;
  }
  cout << endl << endl;

  // for (auto cost: result) cout << setw(3) << cost << " ";
  // cout << (correct!=result? " (WRONG)": "Correct.") << endl;
}



void run_tests() {
  vector<vector<int>> g1(_input_graph1()); //ex1
  test(g1, {0, 1, 5, 2, 6, 8}, {11, 4, 10, 3, 7, 9});

  vector<vector<int>> g2(_input_graph2()); //ex2
  test(g2, {0, 1, 2, 5, 6}, {9, 4, 3, 8, 7});

  vector<vector<int>> g3(_input_graph3()); //ex3
  test(g3, {0, 1, 7, 2, 8, 3, 9, 11}, {15, 6, 14, 5, 13, 4, 10, 12});
}

#endif  // INC_070__CPP_DS_10G_TEST_16_H_