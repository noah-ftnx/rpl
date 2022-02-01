#include <iostream>
#include <vector>
using namespace std;

#include "../.check/check.h"
#include "test/004.h"

int find_first_missing(vector<int>& vec) {
  if (vec.empty()) return -1;
  for (int i=0; i<vec.size(); i++) {
    if (vec[i]<=0) vec[i]=vec.size()+1; // make it invalid index
  }

  for (int i=0; i<vec.size(); i++) { // O(n) mark all found indices
    int idx = abs(vec[i])-1; //TRICKY
    if (idx >= vec.size()) continue; // invalid idx
    if (vec[idx] > 0) vec[idx]*=-1;
  }

  for (int i=0; i<vec.size(); i++) { // O(n)
    if (vec[i] > 0) return i+1;
  }

  return vec.size()+1;
}


int main() {
  vector<vector<int>> tc {}; // WRITE TEST CASES
  run_tests(tc);
  return 0;
}
