
#include <vector>
using namespace std;

bool solve(vector<vector<int>> graph, int m, vector<int>& coloring, int vertex) {
  const int N = (int) graph.size();
  auto isValid = [&] (int color) {
    for (int i=0; i<N; i++) {
      if (graph[vertex][i] && coloring[i]==color) return false;
    }
    return true;
  };
  
  // base case: solved
  if (vertex == N) return true;

  for (int color=1; color<=m; color++) {
    if (isValid(color)) {
      coloring[vertex]=color; // tentatively assign
      if (solve(graph, m, coloring, vertex+1)) return true;
      coloring[vertex]=0; // backtrack
    }
  }

  return false;
}

// coloring: is an empty vector
bool color_graph(vector<vector<int>> graph, int m, vector<int>& coloring) {
  if (m<=0 || graph.empty()) return false;
  
  coloring.resize(graph.size(), 0);

  return solve(graph, m, coloring, 0);
}



#include "test/g4g-gcol.h"
int main() { run_tests(); return 0; }