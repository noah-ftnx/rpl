// INCLUDES

#include <vector>
using namespace std;


void solve(int target, const vector<int>& steps,
           vector<vector<int>>& combinations,
           vector<int>& attempt, int start) {

  if (target==0) { // reached the top. solved.
    combinations.push_back(attempt);
    return;
  }
  if (target<0) return; //backtrack

  for (int i=start; i<steps.size(); i++) { // try combinations
    if (target-steps[i] >=0) { // might be a solution
      attempt.push_back(steps[i]);

      solve(target-steps[i], steps, combinations, attempt, i);

      attempt.pop_back(); // undo and continue..
    }
  }
}

vector<vector<int>> enumerate_ways(int N, vector<int> steps) {
  vector<vector<int>> combinations;
  vector<int> attempt;
  solve(N, steps, combinations, attempt, 0);
  return combinations;
}


//////////////////////////////////////////////////////



#include "test/dcp012.h"
int main() { run_tests(); return 0; }