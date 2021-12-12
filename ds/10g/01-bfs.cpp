#include "test/input-traversal.h"

#include <list>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void BFS(const vector<list<Edge>>& G, int src);

int main () {
  const int src = 3;
  cout << "BFS (src:" << src << ") undirected graph:\n";
  vector<list<Edge>> G(input_graph_undirected());
  BFS(G, src);

  cout << endl;
  cout << "3 2 4 1 7 5 6   <- correct traversal (src:3)\n";
}

// SLV
void BFS(const vector<list<Edge>>& G, int src) {
}
