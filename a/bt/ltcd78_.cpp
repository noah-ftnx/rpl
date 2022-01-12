#include <vector>
using namespace std;

void solve(const vector<int>& nums,
           vector<int>& subset,
           vector<vector<int>>& powerset,
            int start) {
  powerset.push_back(subset); // push solution. stores initially empty set too.

  for (int i=start; i < nums.size(); i++) {
    int num = nums[i];
    subset.push_back(num);
    solve(nums, subset, powerset, i+1);
    subset.pop_back(); // backtrack
  }
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> powerset;
  vector<int> subset;
  solve(nums, subset, powerset, 0);
  return powerset;
}



#include "test/ltcd78.h"
int main() { run_tests(); return 0; }