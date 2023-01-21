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
  addEdge(G, 5, 1);
  addEdge(G, 4, 3);
  addEdge(G, 4, 6);
  addEdge(G, 4, 7);
  addEdge(G, 0, 7);
  
  return std::move(G);
}


bool _wrong=false;
void test(vector<vector<int>> &graph,
  vector<pair<int,int>> ctree_edges,
  vector<pair<int,int>> cforward_edges,
  vector<pair<int,int>> cback_edges,
  vector<pair<int,int>> ccross_edges) {

  vector<pair<int,int>> tree_edges, forward_edges, back_edges, cross_edges;

  solve(graph, tree_edges, forward_edges, back_edges, cross_edges);

  if(!check_result("tree", ctree_edges, tree_edges)) {
    cout << "found: " << to_string(tree_edges) << endl;
    _wrong|=true;
  }

   if(!check_result("forward", cforward_edges, forward_edges)) {
    cout << "found: " << to_string(forward_edges) << endl;
    _wrong|=true;
  }

  if(!check_result("backward", cback_edges, back_edges)) {
    cout << "found: " << to_string(back_edges) << endl;
    _wrong|=true;
  }

   if(!check_result("cross", ccross_edges, cross_edges)) {
    cout << "found: " << to_string(cross_edges) << endl;
    _wrong|=true;
  }

  cout << endl << endl;
}



void run_tests() {
  vector<vector<int>> g1(_input_graph1()); //ex1
  // order: tree, fwd, back, cross
  cout << "Graph1:" << endl;
  test(g1,
    {{0,1}, {1,3}, {0,2}, {2,4}, {2,5}}, // tree
    {{0,3}}, // fwd
    {{4,0}}, // back
    {{4,3}}); // cross


  vector<vector<int>> g2(_input_graph2()); //ex2
  cout << "Graph2:" << endl;
  test(g2,
    {{0, 1}, {1, 2}, {0,3}, {3, 4}}, // tree
    {}, // fwd
    {}, // back
    {{3, 2}}); // cross

  vector<vector<int>> g3(_input_graph3()); //ex2
  cout << "Graph3:" << endl;
  test(g3,
    {{0, 1}, {1, 3}, {3, 5}, {0, 2}, {2, 4}, {4, 6}, {4, 7}}, // tree
    {{0, 7}}, // fwd
    {{5, 1}}, // back
    {{4, 3}}); // cross

  cout << (_wrong? "WRONG RESULTS!" : "Correct results!") << "\n";
  
}

#endif  // INC_070__CPP_DS_10G_TEST_16_H_