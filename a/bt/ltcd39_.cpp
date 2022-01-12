#include <vector>
using namespace std;

void solve(const vector<int>& candidates, int target,
           vector<vector<int>>& result,
           vector<int>& combination, int start) {
  if (target==0) {
    result.push_back(combination);
    return;
  }
  if (target <0) return; // backtrack

  for (int i=start; i<candidates.size(); i++) {
    if (target-candidates[i]>=0) {
      combination.push_back(candidates[i]);

      solve(candidates, target-candidates[i], result, combination, i);

      combination.pop_back();
    }
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> combination;
  solve(candidates, target, result, combination, 0);
  return result;
}



#include "test/ltcd39.h"
int main() { run_tests(); return 0; }