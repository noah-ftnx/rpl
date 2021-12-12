#include "test/input-mst.h"

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct EdgeCmp {
  bool operator()(const Edge& a, const Edge& b) {
    return a.w > b.w; // MinHeap on weight (w)
  }
};

int cfind(vector<int>& st, int u) {
  int x = u;
  while (st[x] > 0) x=st[x];

  while (x != u) {
    int t = st[u];
    st[u]=x;
    u=t;
  }
  return x;
}
void wunion(vector<int>& st, int u, int v) {
  if (st[u] < st[v]) { // u parent
    st[u]+=st[v];
    st[v]=u;
  } else {
    st[v]+=st[u];
    st[u]=v;
  }
}

void MST(vector<Edge> edges, int V) {
  vector<Edge> mst(V-1);
  vector<int> st(V, -1);
  priority_queue<Edge, vector<Edge>, EdgeCmp> pq;
  for(auto e: edges) pq.push(e); // O(n) Floyd..

  int found_edges=0;
  while(!pq.empty() && found_edges < V-1) {
    auto min = pq.top(); pq.pop(); // logn
    int spar = cfind(st, min.src);
    int tpar = cfind(st, min.tgt);
    if (spar != tpar) { // no cycle
      mst[found_edges]=min;
      wunion(st, spar, tpar);
      found_edges++;
    }
  }

  for (auto e: mst) {
    cout << "(" << e.src << "," << e.tgt << "): " << e.w << endl;
  }
}
///////////////////////////////////////


int main () {
  cout << "MST: undirected graph:\n";
  vector<Edge> edges(input_kruskal());

  MST(edges, V);

  cout << endl;

  cout << "Correct output:\n"
       << "(1,6) 5\n"
       << "(3,4) 8\n"
       << "(2,7) 10\n"
       << "(2,3) 12\n"
       << "(4,5) 16\n"
       << "(5,6) 20\n";
}
