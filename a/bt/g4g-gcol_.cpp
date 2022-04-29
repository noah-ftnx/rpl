#include <vector>
using namespace std;


bool solve(vector<vector<int>> graph, int m, vector<int>& coloring, int idx) {
  if (idx == (int) graph.size()) return true;

  for (int color=1; color<=m; color++) {
    bool valid=true;
    for (int i=0; valid && i<graph[idx].size(); i++) {
      if (graph[idx][i] && color==coloring[i]) valid=false;
    }

    if (!valid) continue;

    coloring[idx]=color;
    if (solve(graph, m, coloring, idx+1)) return true;
    coloring[idx]=0; // 0 is no color
  }

  return false;
}

bool color_graph(vector<vector<int>> graph, int m, vector<int>& coloring) {
  if (graph.empty() || m <=0) return false;

  coloring.resize(graph.size(), 0);
  return solve(graph, m, coloring, 0);
}



#include "test/g4g-gcol.h"
int main() { run_tests(); return 0; }