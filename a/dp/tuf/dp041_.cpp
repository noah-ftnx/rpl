#include <vector>
using namespace std;

int BF(int idx, int last_idx, vector<int>& nums) {
  const int N = (int) nums.size();
  // base case
  if (idx==0) return 0; // picked all nums

  bool can_pick = (last_idx==N+1) || nums[idx-1]<nums[last_idx-1];
  if (can_pick) {
    int pick=1+BF(idx-1, idx, nums);
    int skip=0+BF(idx-1, last_idx, nums);
    return max(pick, skip);
  } else { // cannot
    return BF(idx-1, last_idx, nums);
  }
}

int lengthOfLISBF(vector<int>& nums) {
  const int N = (int) nums.size();
  if (N<=1) return N;
  return BF(N, N+1, nums);
}



#include "test/dp041.h"
int main() {
  run_tests("BF", lengthOfLISBF);
  // run_tests("MMZ", maximumProfitMMZ);
  // run_tests("BU", maximumProfitBU);
  // run_tests("OPT", maximumProfitOPT);

  print_report();
  return 0;
}