#include <vector>
using namespace std;

// Same as dcp/000/037.
void solve(const vector<int>& nums,
           vector<int>& subset,
           vector<vector<int>>& powerset,
           int i) {
  if (i == (int) nums.size()) {
    powerset.push_back(subset);
    return;
  }

  // pick
  subset.push_back(nums[i]);
  solve(nums, subset, powerset, i+1);
  subset.pop_back(); // backtrack

  // skip
  solve(nums, subset, powerset, i+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> powerset;
  vector<int> subset;
  solve(nums, subset, powerset, 0);
  return powerset;
}

#include "test/ltcd78.h"
int main() { run_tests(); return 0; }
