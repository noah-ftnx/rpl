#include <vector>
using namespace std;

void solve(int k, int n, int x, vector<int> &cur, vector<vector<int>> &res) {
  if (cur.size() == k) {
    if (n == 0) res.push_back(cur);
    return;
  }

  if (n < 0) return;

  for (int i=x; i<=9; i++) {
    cur.push_back(i);
    solve(k, n-i, i+1, cur, res);
    cur.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> res;
  vector<int> cur;
  solve(k, n, 1, cur, res);
  return res;
}



#include "test/ltcd216.h"
int main() { run_tests(); return 0; }
