#include <vector>
using namespace std;

void solve (
    const vector<int> &input,
    vector<vector<int>> &res, vector<int> &cur,
    int K, int i) {

  // base case:
  if (i==input.size()) { // input consumed
    if (K==0) res.push_back(cur); // solved
    return;
  }

  // case 1: picking
  cur.push_back(input[i]);
  solve(input, res, cur, K-input[i], i+1);
  cur.pop_back();

  // case 2: skipping
  solve(input, res, cur, K, i+1);
}

vector<vector<int>> enumerate_subsequences(vector<int> input, int K) {
  vector<vector<int>> res; vector<int> cur;
  solve(input, res, cur, K, 0);
  return res;
}



#include "test/rec-l07-01.h"
int main() { run_tests(); return 0; }