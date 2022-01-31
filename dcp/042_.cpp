
#include <algorithm>
#include <vector>
using namespace std;

bool BT(const vector<int>& input, vector<int>& res, int k, int start) {
  if (k == 0) { // found solution
    return true;
  }

  for (int i=start; i<input.size(); i++) {
    if (i>0 && input[i-1]==input[i]) continue; // ignore dups
    if (k-input[i] >=0) { // might be a solution
      k-=input[i]; // try
      res.push_back(input[i]);

      if (BT(input, res, k, i+1)) return true;

      res.pop_back(); // backtrack
      k+=input[i];
    }
  }
  return false;
}

vector<int> find_subset(vector<int> input, int k) {
  sort(input.rbegin(), input.rend());
  vector<int> res;
  if(!BT(input, res, k, 0)) return {};
  return res;
}



#include "test/042.h"
int main() { run_tests(); return 0; }