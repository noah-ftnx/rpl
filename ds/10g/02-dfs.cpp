#include "test/input-traversal.h"

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void DFS(const vector<list<Edge>>& G, int src);

int main () {
  const int src = 3;
  cout << "DFS (src:" << src << ") undirected graph:\n";
  vector<list<Edge>> G(input_graph_undirected());
  DFS(G, src);

  cout << endl;
  cout << "3 2 1 6 5 4 7  <- correct traversal (src:3)\n";
}

void DFS(const vector<list<Edge>>& G, int src) {

}