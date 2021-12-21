#include <list>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#include "test/input-traversal.h"

// DEFINED: struct Edge: int id, int weight

void BFS(const vector<list<Edge>>& G, int src) {
  vector<bool> visit_sched(G.size(), false);
  queue<int> q;
  q.push(src);
  visit_sched[src]=true;

  while(!q.empty()) {
    auto n = q.front(); q.pop();
    cout << n << " ";
    for (auto e: G[n]) {
      if (!visit_sched[e.id]) {
        visit_sched[e.id]=true;
        q.push(e.id);
      }
    }
  }
}

#include "test/01.h"
int main () { run_tests(); return 0; }