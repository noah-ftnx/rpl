#include <iostream>

#include <vector>
using namespace std;

bool solve(const vector<vector<int>>& graph, const int& k,
           vector<int>& coloring, int start) {
  const int V = (int) graph.size();

  // check if color neighbors are colored with [color]
  auto is_valid = [&](int vertex, int color) -> bool {
    auto neighbors = graph[vertex];
    for (int i=0; i<V; i++) {
      if (neighbors[i] == 1 && i < coloring.size() && color == coloring[i]) return false;
    }
    return true;
  };

  if (coloring.size()==V) return true; // solved

  // int cur_color = coloring[vertex];
  // auto neighbors = graph[start];
  for (int i=start; i<V; i++) {
    for (int color = 1; color<=k; color++) {
      if (is_valid(i, color)) {
        coloring.push_back(color);  // tentatively assign

        if (solve(graph, k, coloring, i + 1)) return true;

        coloring.pop_back();  // undo
      }
    }
  }

  return false;
}

bool color_graph(vector<vector<int>> graph, int k, vector<int>& coloring) {
  if (graph.empty() || k==0) return false;
  return solve(graph, k, coloring, 0);
}



#include "test/g4g-gcol.h"
int main() { run_tests(); return 0; }
