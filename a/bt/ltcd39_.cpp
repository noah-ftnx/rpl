#include <vector>
using namespace std;

void solve(const vector<int>& input, vector<vector<int>> &res,
           vector<int> &cur, int i, int target) {
  if (i == input.size()) {
    if (target==0) {
      res.push_back(cur);
    }
    return;
  } else if (target < 0) return;

  // case 1: take it
  // can optimize: only if (target-input[i] >=0)
  cur.push_back(input[i]);
  solve(input, res, cur, i, target-input[i]);
  cur.pop_back();

  // case 2: not take it
  solve(input, res, cur, i+1, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> res;
  vector<int> cur;
  solve(candidates, res, cur, 0, target);

  return res;
}



#include "test/ltcd39.h"
int main() { run_tests(); return 0; }