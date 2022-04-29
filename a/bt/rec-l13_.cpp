#include <vector>
using namespace std;

void solve(
    vector<int> &input,
    vector<vector<int>> &res, int firstIdx) {
  const int N = (int) input.size();

  if (firstIdx == input.size()) {
    res.push_back(input);
    return;
  }

  for (int i=firstIdx; i<N; i++) {
    swap(input[firstIdx], input[i]);
    solve(input, res, firstIdx+1);
    swap(input[firstIdx], input[i]);
  }

}

vector<vector<int>> permute(vector<int> input) {
  vector<vector<int>> res;
  solve(input, res, 0);
  return res;
}




#include "test/rec-l13.h"
int main() { run_tests(); return 0; }