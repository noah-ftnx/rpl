/**
 * https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10
 */


#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
void solve(const vector<int>& input, vector<int> &res, int sum, int idx) {
  const int N = (int) input.size();
  if (idx == N) {
    res.push_back(sum);
    return;
  }


  // case 1: pick element
  solve(input, res, sum+input[idx], idx+1);

  // case 2: skip element
  solve(input, res, sum, idx+1);

}

vector<int> subsetSums(vector<int> input) {
  vector<int> res;
  solve(input, res, 0, 0);
  sort(res.begin(), res.end());
  return res;
}



#include "test/rec-l10.h"
int main() { run_tests(); return 0; }