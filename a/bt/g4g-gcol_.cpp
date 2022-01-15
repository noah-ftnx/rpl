#include <vector>
using namespace std;

bool solve(const vector<vector<int>>& graph, const int& V, const int& m,
           int vertex, vector<int>& coloring) {
  // check if color neighbors are colored with [color]
  auto is_valid = [&](int vertex, int color) -> bool {
    auto neighbors = graph[vertex];
    for (int i=0; i<neighbors.size(); i++) {
      if (neighbors[i] != 0 && i < coloring.size() && color == coloring[i]) return false;
    }
    return true;
  };
  if (coloring.size()==V) return true; //solved

  int cur_color = coloring[vertex];
  auto neighbors = graph[vertex];
  for (int i=0; i<neighbors.size(); i++) {
    if (neighbors[i] == 1) { // exists
      if (i < coloring.size()) { // color was assigned to neighbor
        if (coloring[i] == cur_color) return false; // backtrack
      } else { // attempt to color it
        for (int color=1; color<=m; color++) {
          if (is_valid(i, color)) {

            coloring.push_back(color); // try solution

            if (solve(graph, V, m, i, coloring)) return true;

            coloring.pop_back(); // undo
          }
        }
      }
    }
  }
  return false;
}

bool color_graph(vector<vector<int>> graph, int m, vector<int>& coloring) {
  if (graph.empty() || m==0) return false;
  const int V = graph.size();
  coloring.push_back(1);  // color first node
  return solve(graph, V, m, 0, coloring);
}

#include "test/g4g-gcol.h"
int main() { run_tests(); return 0; }
