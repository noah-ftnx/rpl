#ifndef REPL_DS_10_GRAPH_INPUT_TRAVERSAL_H_
#define REPL_DS_10_GRAPH_INPUT_TRAVERSAL_H_

#include <vector>
#include <list>
using namespace std;

bool _isDirected=false;

void addEdge(vector<list<Edge>> &G, int from, int to, int weight) {
  G[from].push_back({to, weight});
  if (_isDirected) {
    G[to].push_back({from, weight});
  }
}

vector<list<Edge>> _input_graph() {
  const int V=7;
  const int E=9;
  vector<list<Edge>> G(V+1);
  addEdge(G, 1, 2, 25);
  addEdge(G, 2, 3, 9);
  addEdge(G, 3, 4, 10);
  addEdge(G, 4, 5, 12);
  addEdge(G, 5, 6, 18);
  addEdge(G, 6, 1, 5);
  addEdge(G, 5, 7, 16);
  addEdge(G, 2, 7, 6);
  addEdge(G, 4, 7, 11);
  return std::move(G);
}

vector<list<Edge>> input_graph_directed() {
  _isDirected = false;
  return _input_graph();
}

vector<list<Edge>> input_graph_undirected() {
  _isDirected = true;
  return _input_graph();
}

#endif //REPL_DS_10_GRAPH_INPUT_TRAVERSAL_H_