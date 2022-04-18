#include <list>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int id {};
  int weight {};
};

void DFS(const vector<list<Edge>>& G, int src) {
  static vector<bool> visited(G.size(), false);
  visited[src]=true;
  cout << src << " ";

  for (auto e: G[src]) {
    if (!visited[e.id]) {
      DFS(G, e.id);
    }
  }
}



#include "test/02.h"
int main() { run_tests(); return 0; }