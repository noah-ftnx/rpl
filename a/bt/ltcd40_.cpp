#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& input, vector<vector<int>> &res,
           vector<int> &cur, int target, int idx) {

  // base case: target == 0 add to sol. ret.
  if (target==0) {
    res.push_back(cur); // O(K)
    return;
  }

  for (int i=idx; i<(int)input.size(); i++) {

    if (i>idx && input[i]==input[i-1]) continue;

    if (target-input[i] <0) break;

    cur.push_back(input[i]);
    solve(input, res, cur, target-input[i], i+1);
    cur.pop_back();
  }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  if (candidates.empty()) return {{}};

  sort(candidates.begin(), candidates.end());

  vector<vector<int>> res;
  vector<int> cur;
  solve(candidates, res, cur, target, 0);

  return res;

}



#include "test/ltcd40.h"
int main() { run_tests(); return 0; }