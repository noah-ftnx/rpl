#include <vector>
using namespace std;

bool solve(vector<vector<bool>> AM, int k, vector<int>& colors, int start) {
  auto is_valid = [&](int vertex, int color) -> bool {
    for (int i=0; i<AM[vertex].size(); i++) {
      if (AM[vertex][i]==1) { // neighbor exists
        if (i < colors.size() && colors[i]==color) return false;
      }
    }
    return true;
  };

  if (colors.size() == AM.size()) return true;

  for (int i=start; i<AM.size(); i++) {
    for (int color=0; color<k; color++) {
      if (is_valid(i, color)) {
        colors.push_back(color);  // tentatively assign

        if (solve(AM, k, colors, i+1)) return true;

        colors.pop_back();  // undo
      }
    }
  }

  return false; // backtrack
}


bool color_graph(vector<vector<bool>> AM, int k) {  // 3
  if (AM.empty()) return false;
  vector<int> colors;

  return solve(AM, k, colors, 0);
}



#include "test/056.h"
int main() { run_tests(); return 0; }