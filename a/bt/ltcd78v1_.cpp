#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int>& nums, int start,
           vector<vector<int>>& powerset, vector<int>& subset) {

  powerset.push_back(subset);
  for (int i=start; i<nums.size(); i++) {
    if (i>start && nums[i-1]==nums[i]) continue;

    subset.push_back(nums[i]);
    solve(nums, i+1, powerset, subset);
    subset.pop_back(); // backtrack
  }
}

vector<vector<int>> subsets(vector<int>& nums)  {

  sort(nums.begin(), nums.end()); // nlogn

  vector<vector<int>> powerset {};
  vector<int> subset {};
  solve(nums, 0, powerset, subset);
  return powerset;
}



#include "test/ltcd78v1.h"
int main() { run_tests(); return 0; }