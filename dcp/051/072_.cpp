#include <string>
#include <vector>
#include <list>
#include <utility>
#include <deque>
using namespace std;

struct Graph {
  const int V, E;
  vector<char> names;
  vector<int> indegree;
  vector<list<int>> AL;

  Graph(string nodes, list<pair<int, int>> edges) :
        V{(int) nodes.size()},
        E{(int) edges.size()}
  {
    AL.resize(V);
    indegree = vector<int>(V, 0);
    for (char name: nodes) names.push_back(name);
    for (auto e: edges) insert(e.first, e.second);

  }

  void insert(int src, int tgt) {
    AL[src].push_back(tgt);
    indegree[tgt]++;
  }

  bool cyclesDFS(vector<bool> &visited, vector<bool> &in_stack,
                 deque<int> &order, int v) {
    visited[v]=true;
    in_stack[v]=true;

    for (int nei: AL[v]) {
      if (!visited[nei] && cyclesDFS(visited, in_stack, order, nei)) return true;
      else if (in_stack[nei]) return true;
    }

    in_stack[v]=false;
    order.push_front(v);
    return false;
  }

  int hasCycles(deque<int> &order) {
    vector<bool> visited(V, false), in_stack(V, false);

    for (int v=0; v<V; v++)
      if (!visited[v] && cyclesDFS(visited, in_stack, order, v)) return true;

    return false;
  }

  int charIdx(int v) {
    return names[v]-'A';
  }

  int solveDFS(vector<int> &sum, int v) {
    sum[charIdx(v)]++;

    int mx=sum[charIdx(v)];
    for (int nei: AL[v]) {
      mx=max(mx, solveDFS(sum, nei));
    }

    sum[charIdx(v)]--;
    return mx;
  }

  int solveSLOW() {
    deque<int> order;
    if (hasCycles(order)) return -1;

    int mx=-1;
    vector<int> sum(26, 0);
    for (int v=0; v<V; v++) {
      if (indegree[v]==0) {
        mx=max(mx, solveDFS(sum, v));
      }
    }

    return mx;
  }

  int solve() {
    deque<int> order;
    if (hasCycles(order)) return -1;

    int mx=-1;
    vector<vector<int>> tab(V, vector<int>(26, 0));

    for (int v=0; v<V; v++) {
      if (indegree[v]==0) {
        tab[v][charIdx(v)]++;
      }
    }

    for (int v: order) {
      for (int nei: AL[v]) {
        for (int c=0; c<26; c++) {
          tab[nei][c]=max(tab[nei][c], tab[v][c]);
          // tab[nei][c]=tab[v][c];
        }
        tab[nei][charIdx(nei)]=tab[v][charIdx(nei)]+1;
        mx=max(mx, tab[nei][charIdx(nei)]);
      }
    }

    return mx;
  }

};



#include "test/072.h"
int main() { run_tests(); return 0; }