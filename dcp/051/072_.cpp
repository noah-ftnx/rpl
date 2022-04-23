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

#ifdef DP
struct Graph {
  vector<list<int>> AL;
  vector<char> names;
  vector<int> indegree;
  const int n; // V
  const int m; // E
  Graph(string nodes, list<pair<int, int>> edges):
        n{(int)nodes.size()},
        m{(int) edges.size()} {
    AL.resize(n);
    indegree=vector<int>(n, 0);

    for (auto name: nodes) names.push_back(name);

    for (auto edge: edges) insert(edge.first, edge.second);
  }

  void insert(int src, int tgt) {
    AL[src].push_back(tgt);

    indegree[tgt]++;
  }

  bool cyclesDFS(vector<bool> &visited, vector<bool> &in_stack,
                 deque<int> &order, int v) {
    visited[v]=true;
    in_stack[v]=true;

    for (auto nei: AL[v]) {
      if (!visited[nei] && cyclesDFS(visited, in_stack, order, nei)) return true;
      else if (in_stack[nei]) return true;
    }

    in_stack[v]=false;
    order.push_front(v);
    return false;
  }

  int solveDFS(vector<int>& freq, int v, int from,
               vector<vector<int>>& mmz) {
    if (mmz[v][from]!=-1) return mmz[v][from];

    int mx=-1;
    const int cIdx = names[v]-'A';
    freq[cIdx]++;
    mx=freq[cIdx];

    for(int nei: AL[v]) {
      mx=max(mx, solveDFS(freq, nei, v, mmz));
    }

    freq[cIdx]--;
    mmz[v][from]=mx;
    return mx;
  }

  int solveREC() {
    vector<bool> visited(n, false);
    vector<bool> in_stack(n, false);
    vector<vector<int>> mmz(n+1, vector<int>(n+1, -1));

    deque<int> order;
    for (int v=0; v<n; v++) {
      if (!visited[n] && cyclesDFS(visited, in_stack, order, v)) return -1;
    }

    // graph becomes a DAG
    int mx=-1;
    vector<int> freq(26, 0);
    for (int v=0; v<n; v++) {
      if (indegree[v]==0) {
        mx=max(mx, solveDFS(freq, v, n, mmz));
      }
    }

    return mx;
  }


  int solve() {
    vector<bool> visited(n, false);
    vector<bool> in_stack(n, false);
    deque<int> order;
    for (int v=0; v<n; v++) {
      if (!visited[n] && cyclesDFS(visited, in_stack, order, v)) return -1;
    }

    // graph becomes a DAG

    int mx=-1;
    vector<vector<int>> tab(n, vector<int>(26, 0));

    for (int v=0; v<n; v++) {
      const int cIdx = names[v]-'A';
      tab[v][cIdx]=1;
    }

    for (int v: order) {
      for (int nei: AL[v]) {
        for (int c=0; c<26; c++) {
          tab[nei][c]=max(tab[nei][c], tab[v][c]);
        }

        const int cIdx = names[nei]-'A';
        tab[nei][cIdx]=tab[v][cIdx]+1;
        mx=max(mx, tab[nei][cIdx]);
      }
    }

    return mx;
  }

};
#endif



#include "test/072.h"
int main() { run_tests(); return 0; }