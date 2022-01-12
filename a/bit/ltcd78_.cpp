#include <vector>
using namespace std;

vector<vector<int>> subsetsBIT(vector<int>& nums) {
  vector<vector<int>> powerset;
  const int N = nums.size();

  for (int num=0; num<(1<<N); num++) {
    vector<int> subset;
    for (int i=0; i<N; i++) {  // check bits
      if (num&(1<<i)) subset.push_back(nums[i]);
    }
    powerset.push_back(subset);
  }

  return powerset;
}



#include "test/ltcd78.h"
int main() { run_tests(); return 0; }