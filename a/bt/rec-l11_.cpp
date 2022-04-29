/*
 * https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12
 */
#include <vector>
using namespace std;

void solve(vector<int>& nums, vector<vector<int>>& res,
           vector<int> cur, int idx) {
  int N = (int) nums.size();

  // no base base
  res.push_back(cur); // all are unique: O(N)

  for (int i=idx; i<N; i++) {

    // skip: don't consider the same number in the same sol (cur) idx
    if (i> idx && nums[i]==nums[i-1]) continue;

    // case 1: pick an element
    cur.push_back(nums[i]);
    solve(nums, res, cur, i+1);

    // case 2: skip element (let the loop advance)
    cur.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> res; vector<int> cur;
  sort(nums.begin(), nums.end());
  solve(nums, res, cur, 0);
  return res;
}



#include "test/rec-l11.h"
int main() { run_tests(); return 0; }