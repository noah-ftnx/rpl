#include <vector>
using namespace std;

void solve(const vector<int> &input, vector<bool> &mark,
           vector<vector<int>> &res, vector<int> &cur) {
  const int N = (int) input.size();

  if (cur.size() == N) {  // base case: picked all numbers
    res.push_back(cur);
    return;
  }

  for (int i=0; i<N; i++) {
    if (!mark[i]) {
      mark[i]=true;
      cur.push_back(input[i]);

      solve(input, mark, res, cur);

      cur.pop_back();
      mark[i]=false;
    }
  }

}

vector<vector<int>> permute(vector<int> input) {
  const int N = (int) input.size();

  vector<vector<int>> res; vector<int> cur;
  vector<bool> mark(N, false);
  solve(input, mark, res, cur);
  return res;
}



#include "test/rec-l12.h"
int main() { run_tests(); return 0; }