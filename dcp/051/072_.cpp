#include <string>
#include <list>
#include <deque>
#include <vector>
#include <utility>
using namespace std;
#include <iostream>

struct Graph {
  const int V;
  const int E;
  vector<list<int>> AL, REV;
  vector<char> vertices;
  vector<int> indegree;

  Graph(string nodes, list<pair<int, int>> edges) :
        V {(int) nodes.size()},
        E {(int) edges.size()} {
    AL.resize(V);
    REV.resize(V);
    indegree = std::move(vector(V, 0));

    for (char c: nodes) vertices.push_back(c);

    for (auto edge: edges) {
      insert(edge.first, edge.second);
    }
  }

  void insert(int src, int tgt) {
    AL[src].push_back(tgt);
    REV[tgt].push_back(src);
    indegree[tgt]++;
  }


  bool hasCyclesDFS(vector<bool> &visited, vector<bool> &in_stack, int v) {
    visited[v]=true;
    in_stack[v]=true;

    for (auto nei: AL[v]) {
      if (!visited[nei] && hasCyclesDFS(visited, in_stack, nei)) return true;
      else if (in_stack[nei]) return true;
    }

    in_stack[v]=false;
    return false;
  }

  bool hasCycles() {
    vector<bool> visited(V, false), in_stack(V, false);
    for (int v=0; v<V; v++) {
      if (!visited[v] && hasCyclesDFS(visited, in_stack, v)) return true;
    }
    return false;
  }

  int solve() {
    if (hasCycles()) return -1;

    int mx=-10;
    vector<int> freq(26, 0);
    for (int i=0; i<V; i++) {
      if (indegree[i]==0) {
        mx = max(mx, recv(i, freq));
      }
    }
    return mx;
  }

  int recv(int v, vector<int>& freq) {
    int fIdx = vertices[v]-'A';
    freq[fIdx]++; // increase before calling recv
    int mx = freq[fIdx];

    for (int nei: AL[v]) {
      mx=max(mx, recv(nei, freq));
    }

    freq[fIdx]--; // in another path it's reset
    return mx;
  }
};



#include "test/072.h"
int main() { run_tests(); return 0; }