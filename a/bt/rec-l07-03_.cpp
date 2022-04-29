#include <vector>
using namespace std;

int solve(vector<int> input, int K, int i) {

  // base case: input consumed
  if (i == (int) input.size()) {
    return (int) (K == 0);
  }

  // case 1: pick
  int l = solve(input, K-input[i], i+1);

  // case 2: skip
  int r = solve(input, K, i+1);

  return l+r; // sum
}

int count_subsequences(vector<int> input, int K) {
  return solve(input, K, 0);
}


#include "test/rec-l07-03.h"
int main() { run_tests(); return 0; }