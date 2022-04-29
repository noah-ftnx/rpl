#include <vector>
using namespace std;

bool solve(vector<int> input, vector<int> &first, int K, int i) {

  if (i == (int) input.size()) {
    if (K==0) return true;
    return false;
  }

  // case 1: pick
  first.push_back(input[i]);
  if (solve(input, first, K-input[i], i+1)) return true;
  first.pop_back();

  // case 2: skip
  return solve(input, first, K, i+1);
}

vector<int> any_subsequence(vector<int> input, int K) {
  vector<int> first;
  solve(input, first, K, 0);
  return first;
}



#include "test/rec-l07-02.h"
int main() { run_tests(); return 0; }