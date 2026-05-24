#include <vector>
using namespace std;

// Same as dcp/000/037.
void solve(const vector<int>& input,
           vector<int>& subset,
           vector<vector<int>>& powerset,
           int i) {
  if (i == (int) input.size()) {
    powerset.push_back(subset);
    return;
  }

  // pick
  subset.push_back(input[i]);
  solve(input, subset, powerset, i+1);
  subset.pop_back(); // backtrack

  // skip
  solve(input, subset, powerset, i+1);
}

vector<vector<int>> subsets(vector<int>& input) {
  vector<vector<int>> powerset;
  vector<int> subset;
  solve(input, subset, powerset, 0);
  return powerset;
}

#include "test/ltcd78.h"
int main() { run_tests(); return 0; }
