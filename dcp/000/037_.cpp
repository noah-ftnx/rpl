#include <vector>
using namespace std;

void find_powerset(const vector<int>& input,
                   vector<int>& cset,
                   vector<vector<int>>& pset, int start) {
  pset.push_back(cset); // initially empty set. covers empty input also.

  for (int i=start; i<input.size(); i++) {
    // include i, or exclude it
    cset.push_back(input[i]);
    find_powerset(input, cset, pset, i+1);
    cset.pop_back();
  }
}

vector<vector<int>> powerset(vector<int> input) {
  vector<vector<int>> result;
  vector<int> current_set;
  find_powerset(input, current_set, result, 0);

  return result;
}



#include "test/037.h"
int main() { run_tests(); return 0; }